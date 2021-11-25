#!/bin/bash

sed "s/=NUM/=0/g" Makefile.bak | sed "s/TYPE/original/g" > Makefile
make re

sed "s/=NUM/=1/g" Makefile.bak | sed "s/TYPE/test/g" > Makefile
make re

echo -e "original containers:\n"
time ./original > logoriginal

echo  -e "\n ft_containers:"
time ./test > logtest

echo  -e "\nvalgrind - original containers:"
valgrind ./original > /dev/null

echo  -e "\nvalgrind - ft_containers:"
valgrind ./test > /dev/null

rm test original Makefile test.o

echo -e "\ndiff: "
# diff logtest logoriginal