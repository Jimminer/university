#!/bin/bash

if [ $(find . -maxdepth 1 -type d -name "$1" | wc -l) -eq 0 ]; then
	mkdir "Script 3 files"
fi

cd "Script 3 files"

for i in {1..150}; do
	echo "$i" > "file$i"
	chmod +x "file$i"
done
