#!/bin/sh

gcc -Wall -Wextra -Werror -g ft_printf.c parser.c print_di.c utils.c main.c
#gcc main.c

#valgrind --dsymutil=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./a.out