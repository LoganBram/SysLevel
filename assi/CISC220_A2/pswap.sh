#!/bin/bash


if [ "$#" -lt 2 ]; then
    echo "Usage: pswap.sh file1 file2" 1>&2
    exit 1
fi


file1name=$1
file1perm=$(stat -c %A $1)
file1perm2=$(stat -c %a $1)

file2name=$2
file2perm=$(stat -c %A $2)
file2perm2=$(stat -c %a $2)



#swap
temp=$file1name
file1name=$file2name
file2name=$temp



echo $file1perm $file1perm2 $file1name
echo $file2perm $file2perm2 $file2name
#print out -rwxrwxrwx 777 filename
