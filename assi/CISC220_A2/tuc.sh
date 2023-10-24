#!/bin/bash

file=$1
n=$2



rev $1| cut -f1-$n| rev | cat -n