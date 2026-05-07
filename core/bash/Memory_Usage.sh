#!/bin/bash 

# ==============================================
# Use this line to test the memory usage of main
# ==============================================

command time -f %MKB ./main < t.in > m.out
