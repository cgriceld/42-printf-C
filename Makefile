NAME = libftprintf.a
HEADER = ft_printf.h
LIBFTDIR = libft
LIBFTNAME = libft.a

SRC = ft_printf.c parser.c print_utils.c \
	print_di.c print_perc.c print_u.c print_hex.c \
	print_sc.c print_p.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) $@
	@ar rc $@ $(OBJ)
	@ranlib $@

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re