/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgriceld <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:40:47 by cgriceld          #+#    #+#             */
/*   Updated: 2020/11/25 13:40:49 by cgriceld         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_c(t_ppack *pack, int c, int *bytes)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (pack->width)
		pack->width--;
	if (!pack->minus && pack->width)
	{
		if (pack->zero)
			print_wdprec('0', pack, bytes, 1);
		else
			print_wdprec(' ', pack, bytes, 1);
	}
	if (!pack->error)
	{
		if (ft_putchar_fd(ch, 1) < 0)
			pack->error = 1;
		else
			*bytes += 1;
	}
	if (!pack->error && (pack->width > 0))
		print_wdprec(' ', pack, bytes, 1);
}

static int	correct_s(t_ppack *pack, char *s, int *len)
{
	*len = s ? (int)ft_strlen(s) : 6;
	if (pack->prectow)
	{
		if (pack->prec)
			pack->width = pack->prec;
		pack->zero = 0;
		*len = 0;
		return (*len);
	}
	if (pack->wasdot && !pack->prec && !pack->negprec)
		*len = 0;
	if (len && pack->prec && (pack->prec < *len))
		*len = pack->prec;
	pack->width -= *len;
	if (pack->width < 0)
		pack->width = 0;
	return (*len);
}

static void	print_string(t_ppack *pack, char *s, int *bytes, int len)
{
	if (!s)
	{
		if (write(1, "(null)", len) < 0)
			pack->error = 1;
		else
			*bytes += len;
	}
	else if (len)
	{
		if (write(1, s, len) < 0)
			pack->error = 1;
		else
			*bytes += len;
	}
}

void		print_s(t_ppack *pack, char *s, int *bytes)
{
	int len;

	len = correct_s(pack, s, &len);
	if (!pack->minus && pack->width)
	{
		if (pack->zero)
			print_wdprec('0', pack, bytes, 1);
		else
			print_wdprec(' ', pack, bytes, 1);
	}
	if (!pack->error)
		print_string(pack, s, bytes, len);
	if (!pack->error && (pack->width > 0))
		print_wdprec(' ', pack, bytes, 1);
}
