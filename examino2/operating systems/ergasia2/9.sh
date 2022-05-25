#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Error! Expected: '$0 [FILE NAME]'"
    exit 1
fi

file=$(ls -Artp | grep -v / | tail -n 1)

if [ $(find . -maxdepth 1 -type f -name "$1" | wc -l) -gt 0 ]; then
    echo "Error! File $1 already exists!"
    exit 1
else
    cp $file $1
    echo "Copied $file to $1"
fi
