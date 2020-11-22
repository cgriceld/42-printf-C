#include "ft_printf.h"

/*
** Determine, how many 0 from precision, ignore 0 flag is there is precision.
** Determine width (subtract len and precision).
** Width will be blank or 0 (if 0 flag and no precision).
** If num is negative, reduce width.
** If width is negative now, thus we ignore it (e.g., prec > width).
*/
static int	correct_di(t_ppack *pack, int num, int *len)
{
	*len = ft_intlen(num);
	if (!num && pack->wasdot && !pack->prec)
		*len = pack->negprec ? 1 : 0;
	if (pack->wasdot && !pack->prec)
		pack->zero = 0;
	if (pack->prec)
		pack->zero = 0;
	pack->prec = *len >= pack->prec ? 0 : pack->prec - *len;
	pack->width -= pack->prec + *len;
	if (num < 0)
		pack->width--;
	if (pack->width < 0)
		pack->width = 0;
	return (*len);
}

/*
** Print minus and set error flag if error in write call.
** Increase written bytes by 1.
*/
static void	print_disign(const char ch, t_ppack *pack, int *bytes)
{
	if (write(1, &ch, 1) < 0)
	{
		pack->error = 1;
		return ;
	}
	*bytes += 1;
}

static void	print_dinum(int n, t_ppack *pack, int *bytes)
{
	int sign;

	sign = (n < 0) ? -1 : 1;
	if (n <= -10 || n >= 10)
		print_dinum(n / 10, pack, bytes);
	if (ft_putchar_fd(n % 10 * sign + 48, 1) < 0)
	{
		pack->error = 1;
		return ;
	}
	else
		*bytes += 1;
}

/*
** 1) If 0 flag and num < 0, sign is printed before zeros.
** 2) If rightaligned (no flag -) and width is present, fill width with 0
** (if flag 0) and with spaces otherwise.
** 3) Print sign if num < 0 and we haven't printed it yet,
** because no zero flag.
** 4) Fill precision if it is.
** 5) Write number itself (without sign if num < 0).
** 6) If leftaligned (flag -) and width is present, fill it with spaces.
*/
void	print_di(t_ppack *pack, int num, int *bytes)
{
	int len;

	len = correct_di(pack, num, &len);
	if (pack->zero && num < 0)
		print_disign('-', pack, bytes);
	if (!pack->error && !pack->minus && pack->width)
	{
		if (pack->zero)
			print_wdprec('0', pack, bytes, 1);
		else
			print_wdprec(' ', pack, bytes, 1);
	}
	if (!pack->error && !pack->zero && num < 0)
		print_disign('-', pack, bytes);
	if (!pack->error && pack->prec)
		print_wdprec('0', pack, bytes, 0);
	if (!pack->error && len)
		print_dinum(num, pack, bytes);
	if (!pack->error && (pack->width > 0))
		print_wdprec(' ', pack, bytes, 1);
}