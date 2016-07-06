#!/bin/bash

# 在项目目录下递归寻找函数或变量

grep -r -n -e $1 $2

if (( $? != 0 ));then
    echo -e "Usage: sh search.sh func|var|etc. [Path](default .)"
fi
