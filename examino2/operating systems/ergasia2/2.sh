#!/bin/bash

files=$(find /etc -maxdepth 1 -type f | wc -l)

echo "/etc contains $files files"
