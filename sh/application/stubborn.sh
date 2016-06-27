#!/bin/bash
#执行命令直到成功

while :
do
    $@ && exit
    sleep 5
done
