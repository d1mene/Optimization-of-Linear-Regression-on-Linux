#!/bin/bash
FILE="main.cpp"
OPTIONS=("-O0" "-Os" "-O1" "-O2" "-O3" "-O2 -march=native" "-O3 -march=native" "-O2 -march=native -funroll-loops" "-O3 -march=native -funroll-loops")

for opt in "${OPTIONS[@]}"; do
    echo "Building with $opt"
    g++ $FILE -o linear_regression $opt
    size=$(du -b linear_regression | cut -f1)
    time=$( { /usr/bin/time -f "%e" ./linear_regression > /dev/null; } 2>&1 )
    echo "Optimization: $opt | Size: $size bytes | Time: $time s"
done