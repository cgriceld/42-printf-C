#include "ft_printf.h"

/*
** If width > prec, prec is ignores and otherwise.
*/
static int	correct_di(t_ppack *pack, int num)
{
	int len;

	len = numlen(num);
	if (!num && pack->wasdot && !pack->prec)
		len = 0;
	if (pack->wasdot && !pack->prec)
		pack->zero = 0;
	pack->prec = len >= pack->prec ? 0 : pack->prec - len; // number of 0 = pack->prec
	if (pack->prec)
		pack->zero = 0;
	pack->width -= len;
	//pack->width -= pack->prec + len; // how many blank beside 0 of pack->prec
	if (num < 0)
		pack->width--;
	if (pack->width < 0)
		pack->width = 0;
	return (len);
}

static void	print_di_sign(t_ppack *pack, int *bytes)
{
	if (write(1, '-', 1) < 0)
	{
		pack->error = 1;
		return ;
	}
	*bytes += 1;
}

static void	printwd(const char ch, t_ppack *pack, int *bytes)
{
	while (pack->width--)
	{
		if (write(1, &ch, 1) < 0)
		{
			pack->error = 1;
			return ;
		}
		*bytes += 1;
	}
}

/*
** If 0 flag and num < 0, sign is printed before zeros.
*/
void	print_di(t_ppack *pack, int num, int *bytes)
{
	int len;

	len = correct_di(pack, num);
	if (pack->zero && num < 0)
		print_di_sign(pack, bytes);
	if (!pack->error && !pack->minus && pack->width)
	{
		if (pack->zero)
			printwd('0', pack, bytes);
		else
			printwd(' ', pack, bytes);
	}
	
}