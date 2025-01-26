#!/bin/bash

echo -n "Input a number between 20 and 30: "
read number

while [ $number -lt "20" ] || [ $number -gt "30" ]; do
	echo "Error! Please input a number between 20 and 30"
	read number
done
