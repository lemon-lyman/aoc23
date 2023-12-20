#!/bin/bash

if [ $# -eq 1 ]; then
    DAY=$(printf "%02d" $1)
else
    DAY=""
fi

mkdir -p build
cd build

if [ -z "$DAY" ]; then
    cmake .. -D CMAKE_BUILD_TYPE=Debug
else
    cmake -DDAY=$DAY .. -D CMAKE_BUILD_TYPE=Debug
fi

make

cd ..
