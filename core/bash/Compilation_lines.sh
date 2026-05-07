# =========================================================
# Compilation aliases (copy and paste into the terminal)
# =========================================================

# Small one
# Use this whenver lazy
g++ main.cpp -o main

# Fast one
# Use this when wanna be fast
g++ main.cpp -o main -O3

# Standard / recommended
# Use this alwyas
g++ main.cpp -o main -O2 -std=c++20

# Debugging
# Use this when vector or some other thing shits seg_fault at you 
g++ main.cpp -o main -g -Wall -Wextra -std=c++20

# Advanced debugging
# Use this when debug and praying to the holy trinity does not work
g++ main.cpp -o main \
-g -O1 -fsanitize=address,undefined \
-fno-omit-frame-pointer \
-Wall -Wextra -Wshadow -std=c++20

# Competition line
# Use this alwaysER that the standard one
g++ main.cpp -o main O2 -Wall -Wextra -std=c++20

# Home alias
# Use this when you can copy it (DO NOT LEARN IT)
g++ main.cpp -o main \
-O2 -g -D_GLIBCXX_ASSERTIONS \
-Wall -Wextra -Wpedantic -Wshadow \
-Wconversion -Wsign-conversion \
-Wfloat-equal -Wlogical-op \
-Wshift-overflow=2 -Wduplicated-cond \
-Wcast-qual -Wnull-dereference \
-fstack-protector-strong -std=c++20

# Over the top one
# DO NOT LEARN THIS 
# Use this when something that should 100% work does not work and the only possible mistake is some obscure warning
g++ main.cpp -o main \
-O2 -g3 \
-D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC \
-D_GLIBCXX_ASSERTIONS \
-fsanitize=address,undefined \
-fno-sanitize-recover \
-fstack-protector-strong \
-fno-omit-frame-pointer \
-Wall -Wextra -Wpedantic \
-Wshadow -Wconversion -Wsign-conversion \
-Wcast-align -Wcast-qual \
-Wfloat-equal -Wlogical-op \
-Wduplicated-cond -Wduplicated-branches \
-Wnull-dereference -Wshift-overflow=2 \
-Wuseless-cast -Wformat=2 \
-Wunused -Werror \
-std=c++20

# Quick compile
# Use this when you need to compile >100 files simultaneously
g++ main.cpp -o main \
-O0 -std=c++20

# Local stress testing
# Use this idk when (just use this when testing ig)
g++ main.cpp -o main \
-O2 -g -DLOCAL \
-D_GLIBCXX_ASSERTIONS \
-fsanitize=address,undefined \
-Wall -Wextra -std=c++20

# Run
./main
