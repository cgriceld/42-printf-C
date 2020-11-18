#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_ppack
{
    int		minus;
    int		zero;
    int		prec;
    int		width;
    char	type;
}				t_ppack;

#endif