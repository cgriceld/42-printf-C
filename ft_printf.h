#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_ppack
{
	int		minus;
	int		zero;
	int		prec;
	int		width;
	int		wasdot;
	int		negprec;
	int		error;
	char	type;
}				t_ppack;

int		ft_printf(const char *format, ...);
void	parser(const char **format, t_ppack *pack, va_list ap, int *bytes);
void	print_wdprec(const char ch, t_ppack *pack, int *bytes, int flag);
void	print_di(t_ppack *pack, int num, int *bytes);
void	print_perc(t_ppack *pack, int *bytes);
void	print_u(t_ppack *pack, unsigned int num, int *bytes);
void	print_hex(t_ppack *pack, unsigned int num, const int flag, int *bytes);

#endif