/**
 * Syncs accepted LeetCode submissions into a NeetCode-style folder structure:
 *   <Topic>/<problem-slug>/submission-0.<ext>
 *   <Topic>/<problem-slug>/submission-1.<ext>
 *   ...
 *
 * Each new submission gets its OWN git commit:
 *   - Message: "Sync: <Problem Title> (<Language>)"
 *   - Author/committer date backdated to the original submission timestamp,
 *     so your GitHub contribution graph reflects when you actually solved
 *     the problem, not when this script happened to run.
 *
 * Requires env vars (set as GitHub Actions secrets):
 *   LEETCODE_SESSION
 *   LEETCODE_CSRF_TOKEN
 *   GIT_USER_NAME
 *   GIT_USER_EMAIL
 */

const fs = require("fs");
const path = require("path");
const { execFileSync } = require("child_process");

const SESSION = process.env.LEETCODE_SESSION;
const CSRF = process.env.LEETCODE_CSRF_TOKEN;
const GIT_NAME = process.env.GIT_USER_NAME;
const GIT_EMAIL = process.env.GIT_USER_EMAIL;
const OUT_DIR = process.env.OUT_DIR || ".";
const STATE_FILE = path.join(OUT_DIR, ".sync-state.json");

if (!SESSION || !CSRF) {
  console.error("Missing LEETCODE_SESSION or LEETCODE_CSRF_TOKEN env vars.");
  process.exit(1);
}
if (!GIT_NAME || !GIT_EMAIL) {
  console.error("Missing GIT_USER_NAME or GIT_USER_EMAIL env vars.");
  process.exit(1);
}

const LANG_DISPLAY = {
  python: "Python",
  python3: "Python",
  java: "Java",
  "c++": "C++",
  cpp: "C++",
  c: "C",
  "c#": "C#",
  csharp: "C#",
  javascript: "JavaScript",
  typescript: "TypeScript",
  php: "PHP",
  swift: "Swift",
  kotlin: "Kotlin",
  dart: "Dart",
  go: "Go",
  golang: "Go",
  ruby: "Ruby",
  scala: "Scala",
  rust: "Rust",
  racket: "Racket",
  erlang: "Erlang",
  elixir: "Elixir",
  mysql: "SQL",
  mssql: "SQL",
  oraclesql: "SQL",
};

const LANG_EXT = {
  python: "py",
  python3: "py",
  java: "java",
  "c++": "cpp",
  cpp: "cpp",
  c: "c",
  "c#": "cs",
  csharp: "cs",
  javascript: "js",
  typescript: "ts",
  php: "php",
  swift: "swift",
  kotlin: "kt",
  dart: "dart",
  go: "go",
  golang: "go",
  ruby: "rb",
  scala: "scala",
  rust: "rs",
  racket: "rkt",
  erlang: "erl",
  elixir: "ex",
  mysql: "sql",
  mssql: "sql",
  oraclesql: "sql",
};

async function gql(query, variables) {
  const res = await fetch("https://leetcode.com/graphql", {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      Referer: "https://leetcode.com",
      Cookie: `LEETCODE_SESSION=${SESSION}; csrftoken=${CSRF}`,
      "x-csrftoken": CSRF,
    },
    body: JSON.stringify({ query, variables }),
  });
  if (!res.ok) {
    throw new Error(`GraphQL request failed: ${res.status} ${await res.text()}`);
  }
  const json = await res.json();
  if (json.errors) {
    throw new Error(`GraphQL errors: ${JSON.stringify(json.errors)}`);
  }
  return json.data;
}

async function fetchAcceptedSubmissions() {
  const query = `
    query submissionList($offset: Int!, $limit: Int!, $lastKey: String, $questionSlug: String) {
      submissionList(offset: $offset, limit: $limit, lastKey: $lastKey, questionSlug: $questionSlug) {
        lastKey
        hasNext
        submissions {
          id
          statusDisplay
          lang
          timestamp
          title
          titleSlug
        }
      }
    }
  `;

  let all = [];
  let offset = 0;
  const limit = 20;
  let lastKey = null;
  let hasNext = true;

  while (hasNext) {
    const data = await gql(query, { offset, limit, lastKey, questionSlug: "" });
    const page = data.submissionList;
    all = all.concat(page.submissions.filter((s) => s.statusDisplay === "Accepted"));
    hasNext = page.hasNext;
    lastKey = page.lastKey;
    offset += limit;
    if (offset > 20000) break; // safety valve
  }

  return all;
}

async function fetchSubmissionCode(submissionId) {
  const query = `
    query submissionDetails($submissionId: Int!) {
      submissionDetails(submissionId: $submissionId) {
        code
        lang {
          name
        }
      }
    }
  `;
  const data = await gql(query, { submissionId: Number(submissionId) });
  return data.submissionDetails;
}

async function fetchTopicTags(titleSlug) {
  const query = `
    query questionData($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        questionFrontendId
        title
        topicTags {
          name
        }
      }
    }
  `;
  const data = await gql(query, { titleSlug });
  return data.question;
}

function loadState() {
  if (fs.existsSync(STATE_FILE)) {
    return JSON.parse(fs.readFileSync(STATE_FILE, "utf8"));
  }
  return { processedSubmissionIds: [] };
}

function saveState(state) {
  fs.writeFileSync(STATE_FILE, JSON.stringify(state, null, 2));
}

function sanitize(name) {
  return name.replace(/[<>:"/\\|?*]/g, "").trim();
}

function gitCommitFile(filePath, message, isoDate) {
  const env = {
    ...process.env,
    GIT_AUTHOR_NAME: GIT_NAME,
    GIT_AUTHOR_EMAIL: GIT_EMAIL,
    GIT_COMMITTER_NAME: GIT_NAME,
    GIT_COMMITTER_EMAIL: GIT_EMAIL,
    GIT_AUTHOR_DATE: isoDate,
    GIT_COMMITTER_DATE: isoDate,
  };
  execFileSync("git", ["add", filePath], { stdio: "inherit" });
  execFileSync("git", ["commit", "-m", message], { env, stdio: "inherit" });
}

async function main() {
  const state = loadState();
  const processed = new Set(state.processedSubmissionIds);

  console.log("Fetching accepted submissions...");
  const submissions = await fetchAcceptedSubmissions();
  console.log(`Found ${submissions.length} accepted submissions total.`);

  // Oldest first, so submission-0, submission-1... land in chronological
  // order, and commits are made (and dated) in the order you actually solved them.
  submissions.sort((a, b) => Number(a.timestamp) - Number(b.timestamp));

  const topicCache = new Map();
  let newCount = 0;

  for (const sub of submissions) {
    if (processed.has(sub.id)) continue;

    if (!topicCache.has(sub.titleSlug)) {
      const q = await fetchTopicTags(sub.titleSlug);
      topicCache.set(sub.titleSlug, q);
    }
    const question = topicCache.get(sub.titleSlug);
    const topic = question.topicTags?.[0]?.name
      ? sanitize(question.topicTags[0].name)
      : "Uncategorized";

    const problemFolder = path.join(OUT_DIR, topic, sub.titleSlug);
    fs.mkdirSync(problemFolder, { recursive: true });

    const detail = await fetchSubmissionCode(sub.id);
    const langKey = sub.lang.toLowerCase();
    const ext = LANG_EXT[langKey] || "txt";
    const langLabel = LANG_DISPLAY[langKey] || sub.lang;

    const existing = fs
      .readdirSync(problemFolder)
      .filter((f) => f.startsWith("submission-") && f.endsWith(`.${ext}`));
    const nextIndex = existing.length;

    const filePath = path.join(problemFolder, `submission-${nextIndex}.${ext}`);
    fs.writeFileSync(filePath, detail.code);

    const isoDate = new Date(Number(sub.timestamp) * 1000).toISOString();
    const commitMessage = `Sync: ${sub.title} (${langLabel})`;

    gitCommitFile(filePath, commitMessage, isoDate);

    processed.add(sub.id);
    newCount++;
    console.log(`Committed ${filePath} — "${commitMessage}"`);
  }

  state.processedSubmissionIds = Array.from(processed);
  saveState(state);

  if (newCount > 0) {
    const nowIso = new Date().toISOString();
    gitCommitFile(STATE_FILE, "Update sync state", nowIso);
  }

  console.log(`Done. ${newCount} new submission(s) synced.`);
}

main().catch((err) => {
  console.error(err);
  process.exit(1);
});
