#!/bin/bash

# Check if the script received exactly one argument
if [[ $# -ne 1 ]]; then
    echo "Usage: $0 specfile" >&2
    exit 1
fi

SPECFILE=$1

# Check if the specfile exists and is readable
if [[ ! -r $SPECFILE ]]; then
    echo "$SPECFILE is missing or could not be read" >&2
    exit 2
fi

MISSING_FILES=0

# Process each line in the specfile
while read -r line; do
    # Skip blank lines and comments
    [[ -z $line || ${line:0:1} == '#' ]] && continue

    
    if [[ ! -f $line ]]; then
        echo "$line missing" >&2
        MISSING_FILES=1
    fi
done < "$SPECFILE"


if [[ $MISSING_FILES -eq 1 ]]; then
    exit 3
fi


exit 0

