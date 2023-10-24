#!/bin/bash

# does no error checking
# assumes a file is legal if its name is longer than 6
name=$1
if (( "${#name}" > 6 )); then
    exit 0
else
    exit 1
fi 
