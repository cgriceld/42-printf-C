#!/bin/sh

gcc -Wall -Wextra -Werror main.c
#gcc main.c

#valgrind --dsymutil=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./a.out