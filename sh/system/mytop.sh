#!/bin/bash
# top your program

pids=`pidof $1`
#echo -e ${pids}

pids=`echo -e ${pids} | sed 's/\s/,/g'`
#echo -e ${pids}

top -p ${pids}

if (($? != 0));then
    echo -e "Usage: sh mytop.sh [program]"
fi
