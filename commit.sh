./clean.sh
# Linux or Mac
~/git.init.neoviki 2>/dev/null

git config --local core.autocrlf false
git config --local core.longpaths true
git add .
git commit -m "auto"
git push

