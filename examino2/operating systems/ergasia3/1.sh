#!/bin/bash

echo -n "Please input a filename: "
read filename

while [ $(find . -maxdepth 1 -type f -name "$filename" | wc -l) -eq 0 ]; do
	clear
	echo "Searching for $filename..."
	sleep 0.1
done

echo "Found the file $filename"
