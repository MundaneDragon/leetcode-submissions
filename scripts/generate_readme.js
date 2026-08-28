/**
 * Scans the repo's topic folders (created by sync.js) and generates a
 * README.md summarizing progress: total problems solved, and a
 * breakdown by topic with problem counts.
 *
 * Run this AFTER sync.js so it reflects the latest state.
 */

const fs = require("fs");
const path = require("path");

const OUT_DIR = process.env.OUT_DIR || ".";
const README_PATH = path.join(OUT_DIR, "README.md");

// Folders to ignore when scanning for topic directories.
const IGNORE = new Set([
  ".git",
  ".github",
  "scripts",
  "node_modules",
  ".sync-state.json",
  "README.md",
]);

function isDir(p) {
  return fs.existsSync(p) && fs.statSync(p).isDirectory();
}

function main() {
  const entries = fs
    .readdirSync(OUT_DIR)
    .filter((e) => !IGNORE.has(e) && isDir(path.join(OUT_DIR, e)))
    .sort((a, b) => a.localeCompare(b));

  const topics = [];
  let totalProblems = 0;

  for (const topic of entries) {
    const topicPath = path.join(OUT_DIR, topic);
    const problemFolders = fs
      .readdirSync(topicPath)
      .filter((e) => isDir(path.join(topicPath, e)));

    if (problemFolders.length === 0) continue;

    topics.push({ name: topic, count: problemFolders.length, problems: problemFolders.sort() });
    totalProblems += problemFolders.length;
  }

  topics.sort((a, b) => b.count - a.count);

  const lines = [];
  lines.push("# LeetCode Solutions");
  lines.push("");
  lines.push("> Automatically synced from [LeetCode](https://leetcode.com) accepted submissions.");
  lines.push("");
  lines.push("## Progress");
  lines.push("");
  lines.push(`**Total problems solved:** ${totalProblems}`);
  lines.push("");
  lines.push("## Breakdown by topic");
  lines.push("");
  lines.push("| Topic | Problems Solved |");
  lines.push("| --- | --- |");
  for (const t of topics) {
    lines.push(`| ${t.name} | ${t.count} |`);
  }
  lines.push("");
  lines.push("## Problem list");
  lines.push("");
  for (const t of topics) {
    lines.push(`<details>`);
    lines.push(`<summary><strong>${t.name}</strong> (${t.count})</summary>`);
    lines.push("");
    for (const p of t.problems) {
      lines.push(`- [${p}](./${encodeURIComponent(t.name)}/${encodeURIComponent(p)})`);
    }
    lines.push("");
    lines.push(`</details>`);
    lines.push("");
  }
  lines.push("---");
  lines.push(`*Last updated: ${new Date().toISOString().split("T")[0]}*`);

  fs.writeFileSync(README_PATH, lines.join("\n"));
  console.log(`README.md generated: ${totalProblems} problems across ${topics.length} topics.`);
}

main();
