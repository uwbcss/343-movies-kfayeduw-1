#!/bin/bash

# shortcut to compile and run the program

echo "========================="
echo "* Compiling without comedy.cpp / comedy.h / drama.cpp / drama.h / classic.cpp / classic.h / borrowcommand.h / borrowcommand.cpp / returncommand.h / returncommand.cpp / inventorycommand.h / inventorycommand.cpp / historycommand.h / historycommand.cpp"
rm -f a.out
g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp store_test.cpp movie.h movie.cpp customer.h customer.cpp customermap.h customermap.cpp store.h store.cpp command.h command.cpp
./a.out