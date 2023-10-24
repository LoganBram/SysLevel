#!/bin/bash

res=""
for s in "$@"; do
    if (( ${#s} >= 3 )); then
        res="${res}"${s:2:1}
    fi
done
echo $res
