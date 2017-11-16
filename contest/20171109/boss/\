#!/bin/bash
while true
do
    ./datamaker
    ./boss > 1.out
    ./boss_BL > 2.out
    diff 1.out 2.out
    echo fuck
    if [ $? -ne 0 ]
    then
        break;
    fi
done
