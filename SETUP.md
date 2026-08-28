# LeetCode → GitHub Sync — Setup Guide

This syncs your accepted LeetCode submissions into a NeetCode-style folder
structure (`Topic/problem-slug/submission-N.ext`) and auto-generates a
README with your progress, using a manually-triggered GitHub Action.

## Files in this bundle

```
.github/workflows/sync_leetcode.yml   ← the GitHub Action workflow
scripts/sync.js                       ← fetches submissions, writes files
scripts/generate_readme.js            ← rebuilds README.md from synced folders
```

## 1. Create the repository

- Go to GitHub → New repository
- Name it whatever you like (e.g. `leetcode-solutions`)
- Set visibility to **Private**
- Do NOT initialize with a README, .gitignore, or license (keep it empty)

## 2. Add the files

Copy this bundle's folder structure exactly into the root of your new repo:

```
your-repo/
├── .github/
│   └── workflows/
│       └── sync_leetcode.yml
└── scripts/
    ├── sync.js
    └── generate_readme.js
```

Commit and push these three files as your first commit.

## 3. Get your LeetCode cookies

1. Log into [leetcode.com](https://leetcode.com) in your browser
2. Right-click anywhere on the page → **Inspect** → go to the **Network** tab
3. Refresh the page
4. Click any request made to `leetcode.com`
5. In the request headers, find the `cookie:` line
6. Copy the values for:
   - `LEETCODE_SESSION`
   - `csrftoken`

Keep these handy for the next step — treat them like passwords, don't paste
them anywhere public.

## 4. Add repo secrets

In your repo: **Settings → Secrets and variables → Actions → New repository secret**

Add four secrets:
| Name | Value |
|---|---|
| `LEETCODE_SESSION` | the `LEETCODE_SESSION` cookie value |
| `LEETCODE_CSRF_TOKEN` | the `csrftoken` cookie value |
| `GIT_USER_NAME` | your GitHub username (not your real name, if you'd rather not expose it) |
| `GIT_USER_EMAIL` | your GitHub **noreply** email — enable "Keep my email addresses private" at github.com/settings/emails to get one, e.g. `12345678+yourusername@users.noreply.github.com` |

Using the noreply email means sync commits count toward your GitHub
contribution graph without exposing your real email address anywhere
public.

## 5. Enable write permissions for Actions

**Settings → Actions → General → Workflow permissions**
→ select **Read and write permissions** → Save

(Without this, the Action can pull your submissions but won't be able to
commit/push them back to the repo.)

## 6. Run it

- Go to the **Actions** tab
- Click **Sync Leetcode** in the left sidebar
- Click **Run workflow** → **Run workflow** (confirm)
- Wait for it to finish (first run may take longer — it pulls your entire
  accepted-submission history)

Check the repo afterward: you should see topic folders, each containing a
folder per problem, with `submission-0.<ext>`, `submission-1.<ext>`, etc.,
plus an auto-generated `README.md` at the root summarizing your progress.

## Notes for ongoing use

- **Per-submission commits.** Each new submission gets its own commit, with
  a message like `Sync: Two Sum (Python)` — so your history shows exactly
  what was solved, and in what language, at a glance.
- **Backdated commit timestamps.** Each commit's date is set to when you
  actually submitted the solution on LeetCode, not when the sync ran — so
  your GitHub contribution graph reflects your real solving activity.
- **Re-run anytime** after a solving session — it only pulls submissions it
  hasn't already synced (tracked in a `.sync-state.json` file it creates
  and commits separately).
- **Cookies expire.** If a run fails with an auth-type error, repeat step 3
  to grab fresh cookie values and update the two LeetCode secrets.
- **First run is the big one.** It backfills your *entire* accepted-submission
  history, creating one commit per past submission — expect a long commit
  log after the first run. After that, runs are small and incremental.
- **Topic assignment**: each problem is filed under its *first* LeetCode
  topic tag. Problems with multiple tags will only appear once, under
  whichever tag LeetCode lists first — this won't always match how NeetCode
  or other sources categorize the same problem.
