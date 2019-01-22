#!/bin/bash

# makes and runs the linked list program.

clear
g++ -Wall main.cpp llist.cpp -o llist
echo "compilation finished. Executing llist"
./llist
