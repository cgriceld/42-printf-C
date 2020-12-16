#include "ft_printf.h"

static void	correct_c(t_ppack *pack, unsigned char *flags)
{
	if (*flags & PRECTOW)
	{
		if (pack->prec)
			pack->width = pack->prec;
		*flags &= ~ZERO;
		*flags |= MINUS;
	}
	if (pack->width)
		pack->width--;
}

void		print_c(t_ppack *pack, int c, unsigned char *flags)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	correct_c(pack, flags);
	if (!(*flags & MINUS) && pack->width)
	{
		if (*flags & ZERO)
			print_wdprec('0', &pack->width, flags, &pack->bytes);
		else
			print_wdprec(' ', &pack->width, flags, &pack->bytes);
	}
	if (!(*flags & ERROR))
	{
		if (write(1, &ch, 1) < 0)
			*flags |= ERROR;
		else
			pack->bytes++;
	}
	if (!(*flags & ERROR) && (pack->width > 0))
		print_wdprec(' ', &pack->width, flags, &pack->bytes);
}

static int	correct_s(t_ppack *pack, char *s, int *len, unsigned char *flags)
{
	*len = s ? (int)ft_strlen(s) : 6;
	if (*flags & PRECTOW)
	{
		if (pack->prec)
			pack->width = pack->prec;
		*flags &= ~ZERO;
		*len = 0;
		return (*len);
	}
	if ((*flags & WASDOT) && !pack->prec && !(*flags & NEGPREC))
		*len = 0;
	if (len && pack->prec && (pack->prec < *len))
		*len = pack->prec;
	pack->width -= *len;
	if (pack->width < 0)
		pack->width = 0;
	return (*len);
}

static void	print_string(t_ppack *pack, char *s, unsigned char *flags, \
						int len)
{
	if (!s)
	{
		if (write(1, "(null)", len) < 0)
			*flags |= ERROR;
		else
			pack->bytes += len;
	}
	else if (len)
	{
		if (write(1, s, len) < 0)
			*flags |= ERROR;
		else
			pack->bytes += len;
	}
}

void		print_s(t_ppack *pack, char *s, unsigned char *flags)
{
	int len;

	len = correct_s(pack, s, &len, flags);
	if (!(*flags & MINUS) && pack->width)
	{
		if (*flags & ZERO)
			print_wdprec('0', &pack->width, flags, &pack->bytes);
		else
			print_wdprec(' ', &pack->width, flags, &pack->bytes);
	}
	if (!(*flags & ERROR))
		print_string(pack, s, flags, len);
	if (!(*flags & ERROR) && (pack->width > 0))
		print_wdprec(' ', &pack->width, flags, &pack->bytes);
}
