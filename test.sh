#!/bin/bash

while [ 1 ]
do
    echo 1
    ./client $1 $'42 Malaga\n'
    echo 02
done
