NAME = libftprintf.a
HEADER = ft_printf.h
LIBFTDIR = libft
LIBFTNAME = libft.a

SRC = ft_printf.c parser.c print_di.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) $(NAME)
	@ar rc $@ $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re