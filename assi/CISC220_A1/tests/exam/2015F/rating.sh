#!/bin/bash

# does no error checking
# rating depends on length of filename
# rating = (len - 1) % 4 + 1
name=$1
rating=$(( ("${#name}" - 1) % 4 + 1 ))
exit $rating