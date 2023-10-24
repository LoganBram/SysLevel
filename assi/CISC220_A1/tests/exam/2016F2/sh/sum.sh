#!/bin/bash

even=0
odd=0
for x in $@; do
    if (( x % 2 == 0 )); then
        even=$(( even + x ))
    else
        odd=$(( odd + x ))
    fi
done
echo $even $odd