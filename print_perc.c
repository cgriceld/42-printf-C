#include "ft_printf.h"

static void	negprecperc_format(t_ppack *pack, unsigned char *flags)
{
	if (pack->prec)
		pack->width = pack->prec;
	*flags &= ~ZERO;
	*flags |= MINUS;
	pack->width--;
}

void		print_perc(t_ppack *pack, unsigned char *flags)
{
	if (*flags & PRECTOW)
		negprecperc_format(pack, flags);
	else
		pack->width--;
	if (pack->width < 0)
		pack->width = 0;
	if (!(*flags & MINUS) && pack->width)
	{
		if (*flags & ZERO)
			print_wdprec('0', &pack->width, flags, &pack->bytes);
		else
			print_wdprec(' ', &pack->width, flags, &pack->bytes);
	}
	if (!(*flags & ERROR))
	{
		if (write(1, "%", 1) < 0)
			*flags |= ERROR;
		else
			pack->bytes++;
	}
	if (!(*flags & ERROR) && (pack->width > 0))
		print_wdprec(' ', &pack->width, flags, &pack->bytes);
}
