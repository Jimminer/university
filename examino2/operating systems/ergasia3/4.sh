#!/bin/bash

infofile="4_info"
sum=0
size=0

if [ $(find . -maxdepth 1 -type f -name "$infofile" | wc -l) -eq 0 ]; then
	echo "Error! The file $infofile does not exist!"
    exit 1
fi

for i in $(awk '{print $2}' $infofile); do
    ((sum=sum+i))
    ((size=size+1))
done

echo "The average income is $((sum/size))"