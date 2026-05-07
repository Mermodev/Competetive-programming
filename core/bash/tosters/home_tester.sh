#!/bin/bash

# =========================================================
# Toster HOME edition
# =========================================================
#
# Usage:
# ./windows.sh 10000 8 # windows is the name of the file with the code
#
#   10000 -> number of tests
#   8     -> number of threads
#
# Files expected:
#   gen   -> generator
#   main  -> main solution
#   brut  -> brute force solution
#
# =========================================================

TESTS=${1:-1000}
THREADS=${2:-$(nproc)}

GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m'

WIDTH=${#TESTS}

mkdir -p .stress_tmp
rm -f .stress_tmp/*

run_test() {
    local i=$1

    local IN=".stress_tmp/in_$i"
    local OUT1=".stress_tmp/out1_$i"
    local OUT2=".stress_tmp/out2_$i"

    ./gen "$i" > "$IN"

    ./main < "$IN" > "$OUT1"
    ./brut < "$IN" > "$OUT2"

    if diff -q "$OUT1" "$OUT2" > /dev/null; then
        printf "Test %${WIDTH}d -> ${GREEN}OK${NC}\n" "$i"
    else
        printf "Test %${WIDTH}d -> ${RED}WA${NC}\n" "$i"

        echo
        echo -e "${BLUE}========== INPUT ==========${NC}"
        cat "$IN"

        echo
        echo -e "${BLUE}========== MAIN ==========${NC}"
        cat "$OUT1"

        echo
        echo -e "${BLUE}========== BRUT ==========${NC}"
        cat "$OUT2"

        pkill -P $$ 2>/dev/null
        exit 1
    fi
}

export -f run_test
export GREEN RED BLUE NC WIDTH

seq 1 "$TESTS" | xargs -P "$THREADS" -I{} bash -c 'run_test "$@"' _ {}

echo
echo -e "${GREEN}All tests passed.${NC}"

rm -rf .stress_tmp
