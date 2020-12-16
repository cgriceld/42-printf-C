#include "ft_printf.h"

static int	negprecp_format(t_ppack *pack, void *p, int *len, \
							unsigned char *flags)
{
	if (pack->prec)
		pack->width = pack->prec;
	pack->prec = 0;
	*flags &= ~ZERO;
	*flags |= MINUS;
	if (!p)
		*len = 0;
	pack->width -= *len + 2;
	if (pack->width < 0)
		pack->width = 0;
	return (*len);
}

static int	correct_p(t_ppack *pack, const char *address, void *p, \
						unsigned char *flags)
{
	int len;

	if (!address)
	{
		*flags |= ERROR;
		return (0);
	}
	len = (int)ft_strlen(address);
	if (*flags & PRECTOW)
		return (negprecp_format(pack, p, &len, flags));
	if (!p && (*flags & WASDOT) && !pack->prec && !(*flags & NEGPREC))
		len = 0;
	if ((*flags & WASDOT) && !pack->prec && !(*flags & NEGPREC))
		*flags &= ~ZERO;
	if (pack->prec)
		*flags &= ~ZERO;
	pack->prec = len >= pack->prec ? 0 : pack->prec - len;
	pack->width -= pack->prec + len + 2;
	if (pack->width < 0)
		pack->width = 0;
	return (len);
}

static void	print_ox(unsigned char *flags, int *bytes)
{
	if (write(1, "0x", 2) < 0)
		*flags |= ERROR;
	else
		*bytes += 2;
}

static void	print_ptr(const char *address, unsigned char *flags, int *bytes, \
						int len)
{
	if (write(1, address, len) < 0)
		*flags |= ERROR;
	else
		*bytes += len;
}

void		print_p(t_ppack *pack, void *p, unsigned char *flags)
{
	const char	*address;
	int			len;

	address = ft_itoahex((size_t)p, 0);
	len = correct_p(pack, address, p, flags);
	if (!(*flags & ERROR) && (*flags & ZERO))
		print_ox(flags, &pack->bytes);
	if (!(*flags & ERROR) && !(*flags & MINUS) && pack->width)
	{
		if (*flags & ZERO)
			print_wdprec('0', &pack->width, flags, &pack->bytes);
		else
			print_wdprec(' ', &pack->width, flags, &pack->bytes);
	}
	if (!(*flags & ERROR) && !(*flags & ZERO))
		print_ox(flags, &pack->bytes);
	if (!(*flags & ERROR) && pack->prec)
		print_wdprec('0', &pack->prec, flags, &pack->bytes);
	if (!(*flags & ERROR))
		print_ptr(address, flags, &pack->bytes, len);
	if (!(*flags & ERROR) && (pack->width > 0))
		print_wdprec(' ', &pack->width, flags, &pack->bytes);
	free((char *)address);
}
