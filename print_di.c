/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgriceld <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:40:06 by cgriceld          #+#    #+#             */
/*   Updated: 2020/11/25 13:40:08 by cgriceld         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	negprecdi_format(t_ppack *pack, int num, int *len)
{
	if (pack->prec)
		pack->width = pack->prec;
	pack->prec = 0;
	pack->zero = 0;
	pack->minus = 1;
	if (!num)
		*len = 0;
	pack->width -= (num < 0) ? (*len + 1) : *len;
	if (pack->width < 0)
		pack->width = 0;
	return (*len);
}

static int	correct_di(t_ppack *pack, int num, int *len)
{
	*len = ft_intlen(num);
	if (pack->prectow)
		return (negprecdi_format(pack, num, len));
	if (!num && pack->wasdot && !pack->prec)
		*len = pack->negprec ? 1 : 0;
	if (pack->wasdot && !pack->prec && !pack->negprec)
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

void		print_di(t_ppack *pack, int num, int *bytes)
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
