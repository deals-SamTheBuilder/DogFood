#!/bin/bash

if [ $UID -ne 0 ];then
    echo "Not root user."
else
    echo "Root user"
fi
