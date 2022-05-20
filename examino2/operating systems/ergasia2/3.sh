#!/bin/bash

files=$(find ./* -maxdepth 0 -type f -name "k*" | wc -l)

echo "The current dircetory contains $files files that start with the letter k"
