#include "ft_printf.h"

static int	correct_hex(t_ppack *pack, const char *hexnum, int *len)
{
	*len = (int)ft_strlen(hexnum);
	if (*hexnum == '0' && pack->wasdot && !pack->prec)
		*len = pack->negprec ? 1 : 0;
	if (pack->wasdot && !pack->prec)
		pack->zero = 0;
	if (pack->prec)
		pack->zero = 0;
	pack->prec = *len >= pack->prec ? 0 : pack->prec - *len;
	pack->width -= pack->prec + *len;
	if (hexnum < 0)
		pack->width--;
	if (pack->width < 0)
		pack->width = 0;
	return (*len);
}

void	print_hex(t_ppack *pack, unsigned int num, const int flag, int *bytes)
{
	const char	*hexnum;
	int			len;

	hexnum = ft_itoahex(num, flag);
	len = correct_hex(pack, hexnum, &len);
	if (!pack->minus && pack->width)
	{
		if (pack->zero)
			print_wdprec('0', pack, bytes, 1);
		else
			print_wdprec(' ', pack, bytes, 1);
	}
	if (!pack->error && pack->prec)
		print_wdprec('0', pack, bytes, 0);
	if (!pack->error && len)
	{
		if (ft_putstr_fd(hexnum, 1) < 0)
			pack->error = 1;
		else
			*bytes += len;
	}
	if (!pack->error && (pack->width > 0))
		print_wdprec(' ', pack, bytes, 1);
}