#!/bin/bash
#统计一个文本有几行
echo -n "line:"
awk 'END{ print NR }' $1
