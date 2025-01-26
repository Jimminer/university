#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Error! Expected: '$0 [USER]'"
    exit 1
fi

if [ "$(grep -c "^$1:" /etc/passwd)" -gt 0 ]; then
    echo "User $1 found"
else
    echo "User not found"
fi
