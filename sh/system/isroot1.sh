#!/bin/bash

test=$(env | grep USER | cut -d "=" -f 2)

if [ "$test" == "root" ]
then
    echo "Current user is root"
fi
