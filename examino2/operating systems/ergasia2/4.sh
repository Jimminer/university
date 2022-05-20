#!/bin/bash

hour=$(date "+%k")
minute=$(date "+%M")

if [ $hour -gt "12" ]; then
    echo "Current time is: $(($hour%12)):$minute PM"
else
    echo "Current time is: $hour:$minute AM"
fi
