#include "ft_printf.h"

static void	negprecperc_format(t_ppack *pack)
{
	if (pack->prec)
		pack->width = pack->prec;
	pack->zero = 0;
	pack->minus = 1;
	pack->width--;
}

void		print_perc(t_ppack *pack, int *bytes)
{
	if (pack->prectow)
		negprecperc_format(pack);
	else
		pack->width--;
	if (pack->width < 0)
		pack->width = 0;
	if (!pack->minus && pack->width)
	{
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
	if (!pack->error && (pack->width) > 0)
		print_wdprec(' ', pack, bytes, 1);
}
