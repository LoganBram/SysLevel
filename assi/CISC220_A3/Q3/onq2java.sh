#!/usr/bin/env bash

#script to organize zip files with their directories

#send first input to mkpkg, if pkg = '', do nothing

#else, get string after last period, replace . with /, and copy last string.java into that path

if [[ $# -eq 0 ]]; then
	echo "at least one fully qualified class name is required" >&2
	exit 1
fi

for input in "$@"; do
	for stud_direct in */; do
		cd "$stud_direct"

		source ../mkpkg.sh "$input"

		#if pkg has value, then there has been a directory made, otherwise no package
		if [[ -n $pkg ]]; then
			filename="${qname##*.}.java" 
			cp $filename $dir
		else
			:
		fi

		cd ..
	done
done