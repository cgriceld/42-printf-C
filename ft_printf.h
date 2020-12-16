#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define MINUS 0b00000001
# define ZERO 0b00000010
# define WASDOT 0b00000100
# define NEGPREC 0b00001000
# define PRECTOW 0b00010000
# define ERROR 0b00100000

typedef struct	s_ppack
{
	int		prec;
	int		width;
	int		bytes;
	char	type;
}				t_ppack;

int				ft_printf(const char *format, ...);
void			parser(const char **format, t_ppack *pack, \
						unsigned char *flags, va_list ap);
void			print_di(t_ppack *pack, int num, unsigned char *flags);
void			print_perc(t_ppack *pack, unsigned char *flags);
void			print_u(t_ppack *pack, unsigned int num, unsigned char *flags);
void			print_hex(t_ppack *pack, unsigned int num, int f, \
						unsigned char *flags);
void			print_c(t_ppack *pack, int c, unsigned char *flags);
void			print_s(t_ppack *pack, char *s, unsigned char *flags);
void			print_p(t_ppack *pack, void *p, unsigned char *flags);
void			print_wdprec(const char ch, int *i, unsigned char *flags, \
						int *bytes);

#endif
