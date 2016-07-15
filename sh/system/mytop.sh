#!/bin/bash
# top your programs (multiple program)

# get pids from multiple argv
for i in $*
do
    tmp=`pidof $i`
    pids=${tmp}" "${pids}
done
#echo -e ${pids}

# add "," to pids
pids=`echo -e ${pids} | sed 's/\s/,/g'`
#echo -e ${pids}

top -p ${pids}

if [ $? -ne 0 ];then
    echo -e "Usage: sh mytop.sh [programs]"
fi
