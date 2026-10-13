#!/bin/bash
cd /home/biaoj/c_code_learn
git add -A
if ! git diff --cached --quiet; then
    git commit -m "daily auto backup $(date +%Y-%m-%d)"
    git push origin main
    echo "backup done"
else
    echo "no changes"
fi
