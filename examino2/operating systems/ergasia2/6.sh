#!/bin/bash

echo -n "Please input your birthday (DDMMYYYY): "
read birth

bdays=${birth:0:2}
bmonth=${birth:2:2}
byear=${birth:4:4}

ndays=$(date "+%d")
nmonth=$(date "+%m")
nyear=$(date "+%Y")

age=$(($nyear - $byear - 1))

if [ $nmonth -gt $bmonth ] || ([ $nmonth -eq $bmonth ] && [ $ndays -ge $bdays ]); then
    age=$(($age+1))
fi

if [ $age -lt "12" ]; then
    echo "Hello little boy"
elif [ $age -lt "18" ]; then
    echo "Hello teenager"
elif [ $age -lt "45" ]; then
    echo "Hello little mister"
else
    echo "Hello mister"
fi
