#!/bin/bash

function substr
{
    STRING_A=$1
    STRING_B=$2

    if [[ ${STRING_A/${STRING_B}//} == $STRING_A ]]
    then
        ## is not substring.
        return 0
    else
        ## is substring.
        return 1
    fi
}
rm "contest/XTYF-lzr.zip"
find -name "*.in" -delete
find -name "*.out" -delete
find -name "*.ans" -delete
find -name "*.exe" -delete
for fil in $(find `ls`)
do
	str=$(file ${fil})
	# echo $str
    if [[ ${str/"ELF"//} != $str ]]
    then
        ## is not substring.
        echo $fil
        rm $fil
    fi
done
