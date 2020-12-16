#include "ft_printf.h"

static int	negprecx_format(t_ppack *pack, const char *hexnum, int *len, \
							unsigned char *flags)
{
	if (pack->prec)
		pack->width = pack->prec;
	pack->prec = 0;
	*flags &= ~ZERO;
	*flags |= MINUS;
	if (*hexnum == '0')
		*len = 0;
	pack->width -= *len;
	if (pack->width < 0)
		pack->width = 0;
	return (*len);
}

static int	correct_hex(t_ppack *pack, const char *hexnum, int *len, \
						unsigned char *flags)
{
	if (!hexnum)
	{
		*flags |= ERROR;
		return (0);
	}
	*len = (int)ft_strlen(hexnum);
	if (*flags & PRECTOW)
		return (negprecx_format(pack, hexnum, len, flags));
	if (*hexnum == '0' && (*flags & WASDOT) && !pack->prec)
		*len = (*flags & NEGPREC) ? 1 : 0;
	if ((*flags & WASDOT) && !pack->prec && !(*flags & NEGPREC))
		*flags &= ~ZERO;
	if (pack->prec)
		*flags &= ~ZERO;
	pack->prec = *len >= pack->prec ? 0 : pack->prec - *len;
	pack->width -= pack->prec + *len;
	if (pack->width < 0)
		pack->width = 0;
	return (*len);
}

void		print_hex(t_ppack *pack, unsigned int num, int f, \
						unsigned char *flags)
{
	const char	*hexnum;
	int			len;

	hexnum = ft_itoahex((size_t)num, f);
	len = correct_hex(pack, hexnum, &len, flags);
	if (!(*flags & ERROR) && !(*flags & MINUS) && pack->width)
	{
		if (*flags & ZERO)
			print_wdprec('0', &pack->width, flags, &pack->bytes);
		else
			print_wdprec(' ', &pack->width, flags, &pack->bytes);
	}
	if (!(*flags & ERROR) && pack->prec)
		print_wdprec('0', &pack->prec, flags, &pack->bytes);
	if (!(*flags & ERROR) && len)
	{
		if (write(1, hexnum, len) < 0)
			*flags |= ERROR;
		else
			pack->bytes += len;
	}
	if (!(*flags & ERROR) && (pack->width > 0))
		print_wdprec(' ', &pack->width, flags, &pack->bytes);
	free((char *)hexnum);
}
