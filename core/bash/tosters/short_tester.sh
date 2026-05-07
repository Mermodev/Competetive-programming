#!/bin/bash

# =========================================================
# Short toster
# =========================================================
#
# Usage:
# ./sotkoster.sh 1000 #sotkoster is the name of the bash file with this code
#
# Files expected:
#   gen   -> generator [takes the seed as argv parameter]
#   main  -> main solution
#   brut  -> brute force solution
#
# =========================================================

for ((i=1;i<=$1;i++)); do
    ./gen $i > g.out
    ./main < g.out > m.out
    ./brut < g.out > b.out

    if diff m.out b.out > /dev/null; then
        echo -e "Test $i -> OK"
    else
        echo -e "Test $i -> WA"
        exit
    fi
done
