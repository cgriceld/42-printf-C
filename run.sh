#!/bin/sh

gcc -Wall -Wextra -g ft_printf.c parser.c print_di.c print_perc.c print_u.c print_utils.c print_hex.c \
						print_sc.c print_p.c utils.c main.c
#gcc main.c

#valgrind --dsymutil=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./a.out