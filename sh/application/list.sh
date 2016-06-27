#!/bin/bash

touch list.txt
: > list.txt
ls | awk -F ' ' '{for(i=1;i<=NF;i++) print $i}' > list.txt
