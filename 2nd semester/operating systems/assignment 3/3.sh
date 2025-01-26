#!/bin/bash

output="Script 3 files"

if [ $(find . -maxdepth 1 -type d -name "$output" | wc -l) -eq 0 ]; then
	mkdir "$output"
fi

cd "$output"

for i in {1..150}; do
	echo "$i" > "file$i"
	chmod +x "file$i"
done
