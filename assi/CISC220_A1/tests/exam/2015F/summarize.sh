#!/bin/bash

dir=$1
old=$(pwd)
cd "$dir"
n=0
for f in *; do
    if legal.sh "$f"; then
        rating.sh "$f"
        rate=$?
        if (( rate == 4 )); then 
            n=$(( n + 1 ))
        fi
    fi
done
cd "$old"
echo $n