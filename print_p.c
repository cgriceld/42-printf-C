#include "ft_printf.h"

static int	correct_p(t_ppack *pack, const char	*address, void *p, int *len)
{
	*len = (int)ft_strlen(address);
	pack->width -= 2;
	if (!p && pack->wasdot && !pack->prec)
		*len = 0;
	if (pack->width)
		pack->width -= *len;
	if (pack->width < 0)
		pack->width = 0;
	return (*len);
}

void	print_p(t_ppack *pack, void *p, int *bytes)
{
	const char	*address;
	int			len;

	address = ft_itoahex((size_t)p, 0);
	len = correct_p(pack, address, p, &len);
	if (!pack->minus && pack->width)
			print_wdprec(' ', pack, bytes, 1);
	if (!pack->error)
	{
		if (write(1, "0x", 2) < 0)
			pack->error = 1;
		else
			*bytes += 2;
		if (!pack->error)
		{
			if (write(1, address, len) < 0)
				pack->error = 1;
			else
				*bytes += len;
		}
	}
	if (!pack->error && (pack->width > 0))
		print_wdprec(' ', pack, bytes, 1);
	free((char *)address);
}