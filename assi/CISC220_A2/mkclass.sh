#!/bin/bash

#get name of input

fulqualname=.$1

#get name which is last word from input

filename=${fulqualname##*.}
packagename=${fulqualname%.*} 

echo $packagename
echo $filename

if [[ -n ${packagename//.} ]]; then
    package="package ${packagename:1};"
else
    package=''
fi

#write to file
cat > "$filename.java" << EOF
$package

public class $filename {
}
EOF