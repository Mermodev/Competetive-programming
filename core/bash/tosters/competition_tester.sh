#!/bin/bash

# =========================================================
# ojejku toster 
# =========================================================
#
# Usage:
# ./toster.sh 1000 #toster is the name of the file with this code
#
# Files expected:
#   gen   -> generator [takes the seed as argv parameter]
#   main  -> main solution
#   brut  -> brute force solution
#
# =========================================================

TESTS=${1:-100}

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

WIDTH=${#TESTS}

for ((i=1; i<=TESTS; i++)); do

    ./gen $i > input.txt

    ./main < input.txt > out1.txt
    ./brut < input.txt > out2.txt

    if diff -q out1.txt out2.txt > /dev/null; then
        printf "Test %${WIDTH}d -> ${GREEN}OK${NC}\n" "$i"
    else
        printf "Test %${WIDTH}d -> ${RED}WA${NC}\n" "$i"

        echo
        echo "========== INPUT =========="
        cat input.txt

        echo
        echo "========== MAIN OUTPUT =========="
        cat out1.txt

        echo
        echo "========== BRUTE OUTPUT =========="
        cat out2.txt

        exit 1
    fi

done

echo
printf "${GREEN}All %d tests passed.${NC}\n" "$TESTS"
