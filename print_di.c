#include "ft_printf.h"

static int	negprecdi_format(t_ppack *pack, int num, int *len, \
							unsigned char *flags)
{
	if (pack->prec)
		pack->width = pack->prec;
	pack->prec = 0;
	*flags &= ~ZERO;
	*flags |= MINUS;
	if (!num)
		*len = 0;
	pack->width -= (num < 0) ? (*len + 1) : *len;
	if (pack->width < 0)
		pack->width = 0;
	return (*len);
}

static int	correct_di(t_ppack *pack, int num, int *len, unsigned char *flags)
{
	*len = ft_intlen(num);
	if (*flags & PRECTOW)
		return (negprecdi_format(pack, num, len, flags));
	if (!num && (*flags & WASDOT) && !pack->prec)
		*len = (*flags & NEGPREC) ? 1 : 0;
	if ((*flags & WASDOT) && !pack->prec && !(*flags & NEGPREC))
		*flags &= ~ZERO;
	if (pack->prec)
		*flags &= ~ZERO;
	pack->prec = *len >= pack->prec ? 0 : pack->prec - *len;
	pack->width -= pack->prec + *len;
	if (num < 0)
		pack->width--;
	if (pack->width < 0)
		pack->width = 0;
	return (*len);
}

static void	print_disign(const char ch, unsigned char *flags, int *bytes)
{
	if (write(1, &ch, 1) < 0)
	{
		*flags |= ERROR;
		return ;
	}
	*bytes += 1;
}

static void	print_dinum(int n, unsigned char *flags, int *bytes)
{
	int sign;

	sign = (n < 0) ? -1 : 1;
	if (n <= -10 || n >= 10)
		print_dinum(n / 10, flags, bytes);
	if (ft_putchar_fd(n % 10 * sign + 48, 1) < 0)
	{
		*flags |= ERROR;
		return ;
	}
	*bytes += 1;
}

void		print_di(t_ppack *pack, int num, unsigned char *flags)
{
	int len;

	len = correct_di(pack, num, &len, flags);
	if ((*flags & ZERO) && num < 0)
		print_disign('-', flags, &pack->bytes);
	if (!(*flags & ERROR) && !(*flags & MINUS) && pack->width)
	{
		if (*flags & ZERO)
			print_wdprec('0', &pack->width, flags, &pack->bytes);
		else
			print_wdprec(' ', &pack->width, flags, &pack->bytes);
	}
	if (!(*flags & ERROR) && !(*flags & ZERO) && num < 0)
		print_disign('-', flags, &pack->bytes);
	if (!(*flags & ERROR) && pack->prec)
		print_wdprec('0', &pack->prec, flags, &pack->bytes);
	if (!(*flags & ERROR) && len)
		print_dinum(num, flags, &pack->bytes);
	if (!(*flags & ERROR) && (pack->width > 0))
		print_wdprec(' ', &pack->width, flags, &pack->bytes);
}
