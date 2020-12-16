#include "ft_printf.h"

static int		negprecu_format(t_ppack *pack, unsigned int num, int *len, \
								unsigned char *flags)
{
	if (pack->prec)
		pack->width = pack->prec;
	pack->prec = 0;
	*flags &= ~ZERO;
	*flags |= MINUS;
	if (!num)
		*len = 0;
	pack->width -= *len;
	if (pack->width < 0)
		pack->width = 0;
	return (*len);
}

static int		correct_u(t_ppack *pack, unsigned int num, int *len, \
							unsigned char *flags)
{
	*len = ft_uintlen(num);
	if (*flags & PRECTOW)
		return (negprecu_format(pack, num, len, flags));
	if (!num && (*flags & WASDOT) && !pack->prec)
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

static void		print_unum(unsigned int n, unsigned char *flags, int *bytes)
{
	if (n >= 10)
		print_unum(n / 10, flags, bytes);
	if (ft_putchar_fd(n % 10 + 48, 1) < 0)
	{
		*flags |= ERROR;
		return ;
	}
	*bytes += 1;
}

void			print_u(t_ppack *pack, unsigned int num, unsigned char *flags)
{
	int len;

	len = correct_u(pack, num, &len, flags);
	if (!(*flags & MINUS) && pack->width)
	{
		if (*flags & ZERO)
			print_wdprec('0', &pack->width, flags, &pack->bytes);
		else
			print_wdprec(' ', &pack->width, flags, &pack->bytes);
	}
	if (!(*flags & ERROR) && pack->prec)
		print_wdprec('0', &pack->prec, flags, &pack->bytes);
	if (!(*flags & ERROR) && len)
		print_unum(num, flags, &pack->bytes);
	if (!(*flags & ERROR) && (pack->width > 0))
		print_wdprec(' ', &pack->width, flags, &pack->bytes);
}
