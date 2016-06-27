#!/bin/bash

#判断根分区使用率

rate=$(df -h | grep "/dev/sda1" | awk '{print $5}' | cut -d "%" -f 1)
if [ $rate -ge 80 ]
then
    echo "Warning!/dev/sd1 is full!"
fi
