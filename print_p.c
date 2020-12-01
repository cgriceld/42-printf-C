#include "ft_printf.h"

static int	negprecp_format(t_ppack *pack, void *p, int *len)
{
	if (pack->prec)
		pack->width = pack->prec;
	pack->prec = 0;
	pack->zero = 0;
	pack->minus = 1;
	if (!p)
		*len = 0;
	pack->width -= *len + 2;
	if (pack->width < 0)
		pack->width = 0;
	return (*len);
}

static int	correct_p(t_ppack *pack, const char *address, void *p, int *len)
{
	*len = (int)ft_strlen(address);
	if (pack->prectow)
		return (negprecp_format(pack, p, len));
	if (!p && pack->wasdot && !pack->prec && !pack->negprec)
		*len = 0;
	if (pack->wasdot && !pack->prec && !pack->negprec)
		pack->zero = 0;
	if (pack->prec)
		pack->zero = 0;
	pack->prec = *len >= pack->prec ? 0 : pack->prec - *len;
	pack->width -= pack->prec + *len + 2;
	if (pack->width < 0)
		pack->width = 0;
	return (*len);
}

static void	print_ox(t_ppack *pack, int *bytes)
{
	if (write(1, "0x", 2) < 0)
		pack->error = 1;
	else
		*bytes += 2;
}

static void	print_ptr(t_ppack *pack, const char *address, int *bytes, int len)
{
	if (write(1, address, len) < 0)
		pack->error = 1;
	else
		*bytes += len;
}

void		print_p(t_ppack *pack, void *p, int *bytes)
{
	const char	*address;
	int			len;

	address = ft_itoahex((size_t)p, 0);
	len = correct_p(pack, address, p, &len);
	if (pack->zero)
		print_ox(pack, bytes);
	if (!pack->error && !pack->minus && pack->width)
	{
		if (pack->zero)
			print_wdprec('0', pack, bytes, 1);
		else
			print_wdprec(' ', pack, bytes, 1);
	}
	if (!pack->error && !pack->zero)
		print_ox(pack, bytes);
	if (!pack->error && pack->prec)
		print_wdprec('0', pack, bytes, 0);
	if (!pack->error)
		print_ptr(pack, address, bytes, len);
	if (!pack->error && (pack->width > 0))
		print_wdprec(' ', pack, bytes, 1);
	free((char *)address);
}
