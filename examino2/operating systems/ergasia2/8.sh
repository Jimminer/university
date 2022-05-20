#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Error! Expected: '$0 [FILE/DIRECTORY]'"
    exit 1
fi

if [ $(find ./ -maxdepth 0 -type f -name "$1" | wc -l) -gt 0 ]; then
    echo "$1 is a file"
elif [ $(find ./ -maxdepth 0 -type d -name "$1" | wc -l) -gt 0 ]; then
    echo "$1 is a directory"
else
    echo "There is no such file or directory"
fi
