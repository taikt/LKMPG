#!/bin/bash
VERSION='4.12.12'
pandoc -f html -t markdown -o LKMPG-${VERSION}.md LKMPG-${VERSION}.html
pandoc -f markdown -t rst -o LKMPG-${VERSION}.rst LKMPG-${VERSION}.md
git add LKMPG-${VERSION}.md
git add LKMPG-${VERSION}.rst
