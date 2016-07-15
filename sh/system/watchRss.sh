#!/bin/bash
# watch program rss

if [ $# -ne 1 ];then
    echo -e "Usage: sh watchRss.sh [program]"
    exit
fi

# get pids
pids=`pidof $1`
#echo -e ${pids}


if [ $? -ne 0 ];then
    echo -e "Usage: sh watchRss.sh [program]"
    exit
fi

while :
do
    clear
    count=0
    total=0

    echo -e "PID    RSS"
    for i in $pids
    do
        echo -n -e ${i}"  "
        line=`cat /proc/$i/status | grep "VmRSS" | cut -d ":" -f2 `
        value=`echo ${line} | grep -o "[0-9]\+"`
        echo -e ${line}
 
       #if [ ! -n $each ];then
            total=$(($total+$value))
       # fi
            count=$(($count+1))
    done

    total=$(($total/1024))

    echo "pids conut: "${count}
    echo "RSS total: "${total} MB 

    sleep 3
done

