#!/bin/bash

res="Output:"
read -p "Insert a list of words: " -a arr
for s in "${arr[@]}"; do
    mid=$(( ${#s} / 2 ))
    front=${s:0:${mid}}
    back=${s:${mid}}
    if [ "$front" = "$back" ]; then
        res="${res} Yes"
    else
        res="${res} No"
    fi
done
echo "$res"