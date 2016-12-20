#! /bin/bash
# Usage: sh getlog.sh [package name]

if [ $# -eq 1 ];then
    pid=`adb shell ps | grep $1 | awk '{print $2}'`
    adb logcat -v threadtime | grep $pid
else
    echo -e "Usage: sh getlog.sh [package name]"
fi
