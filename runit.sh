#!/bin/bash

# shortcut to compile and run the program

echo "========================="
echo "* Compiling with everything"
rm -f a.out
g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp store_test.cpp movie.h movie.cpp comedy.h comedy.cpp drama.h drama.cpp classic.h classic.cpp customer.h customer.cpp customermap.h customermap.cpp store.h store.cpp command.h command.cpp borrowcommand.h borrowcommand.cpp returncommand.h returncommand.cpp inventorycommand.h inventorycommand.cpp historycommand.h historycommand.cpp
./a.out