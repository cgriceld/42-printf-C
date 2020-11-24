#include "ft_printf.h"

void	print_perc(t_ppack *pack, int *bytes)
{
	if (!pack->minus && pack->width)
	{
		pack->width--;
		if (pack->zero)
			print_wdprec('0', pack, bytes, 1);
		else
			print_wdprec(' ', pack, bytes, 1);
	}
	if (!pack->error)
	{
		if (write(1, "%", 1) < 0)
			pack->error = 1;
		else
			*bytes += 1;
	}
	if (!pack->error && (--pack->width) > 0)
		print_wdprec(' ', pack, bytes, 1);
}