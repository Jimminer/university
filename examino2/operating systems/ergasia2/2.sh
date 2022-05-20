#!/bin/bash

files=$(find /etc/* -maxdepth 0 -type f | wc -l)

echo "/etc contains $files files"
