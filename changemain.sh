#!/bin/bash

if [ $# -ne 1 ]
  then
    echo "usage:  [file name]"
    exit 1
fi

mv main.cpp "$1"
touch main.cpp


