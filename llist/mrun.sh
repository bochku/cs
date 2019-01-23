#!/bin/bash

# makes and runs the linked list program.

clear
g++ main.cpp llist.cpp -o llist
echo "compilation finished. Executing llist"
./llist
