#include "ft_printf.h"

void	print_c(t_ppack *pack, int c, int *bytes)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (pack->width)
		pack->width--;
	if (!pack->minus && pack->width)
		print_wdprec(' ', pack, bytes, 1);
	if (!pack->error)
	{
		if (ft_putchar_fd(ch, 1) < 0)
			pack->error = 1;
		else
			*bytes += 1;
	}
	if (!pack->error && (pack->width > 0))
		print_wdprec(' ', pack, bytes, 1);
}