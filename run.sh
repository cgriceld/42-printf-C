#!/bin/sh

gcc -Wall -Wextra -g -L. -lftprintf main.c

#valgrind --dsymutil=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./a.out