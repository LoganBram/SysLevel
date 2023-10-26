#!/bin/bash

#Script to test if value is a valid canadian number using regex



phonenumber=$1
if [[ $phonenumber =~ ^[0-9]{3}[-\ ]?[0-9]{3}[-\ ]?[0-9]{4}$ ]]; then
    echo 1
else
    echo 0
 fi


if [[ $# -ne 1 ]]; then
    echo "Usage: $0 phone"
    exit 1
fi

