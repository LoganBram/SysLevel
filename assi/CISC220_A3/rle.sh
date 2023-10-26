#!/bin/bash

encode() {
   
    declare -a enc
    n="${#arr[@]}"

    if (( $n > 0 )); then
        start=0
        value=${arr[0]}
        finished=false
        while [ "$finished" != "true" ]; do
            end=$(next $start)
			#if reached the end of the array
			if (( $end == -1 )); then
				end=$n
				finished=true
				
			else
				#count is equal to index of where the next diff character is - where started last
				count=$(( $end - $start ))
				#add values to encoded array
				enc+=("$count")
				enc+=("$value")
				start=$end
				value="${arr[$start]}"
            fi

        done
		echo "${enc[@]}"
    else 
        exit 0
    fi
}

next() {
    local param1=$1
    local current_value=${arr[$param1]}

    for (( i = param1+1; i <= ${#arr[@]}; i++ )); do
        if [ "${arr[$i]}" != "$current_value" ]; then
            echo $i
            return
        fi
		if [ $i == ${#arr[@]} ]; then
			echo -1
			return
		fi

    done

    echo -1
}
# create array arr from command line arguments
arr=("$@")
# encode the array
encode

# print elements of enc on one line with one space between elements
echo "${enc[@]}"
