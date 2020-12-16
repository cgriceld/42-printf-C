#include "ft_printf.h"

void		print_wdprec(const char ch, int *i, unsigned char *flags, \
							int *bytes)
{
	while (*i)
	{
		if (write(1, &ch, 1) < 0)
		{
			*flags |= ERROR;
			return ;
		}
		*bytes += 1;
		*i -= 1;
	}
}
