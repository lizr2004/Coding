#!/bin/bash

rm -f "contest/XTYF-lzr.zip"
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
