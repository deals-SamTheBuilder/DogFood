#!/bin/bash

# run:_DEBUG=on sh debug.sh

function DEBUG()
{
    [ "$_DEBUG" == "on" ] && $@ || :
}

for i in {1..5}
do
    DEBUG echo -e "This is debug line!"
    echo $i
done
    
