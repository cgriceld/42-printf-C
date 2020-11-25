/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgriceld <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:40:18 by cgriceld          #+#    #+#             */
/*   Updated: 2020/11/25 13:40:20 by cgriceld         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	correct_hex(t_ppack *pack, const char *hexnum, int *len)
{
	*len = (int)ft_strlen(hexnum);
	if (*hexnum == '0' && pack->wasdot && !pack->prec)
		*len = pack->negprec ? 1 : 0;
	if (pack->wasdot && !pack->prec && !pack->negprec)
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

void		print_hex(t_ppack *pack, unsigned int num, const int f, int *bytes)
{
	const char	*hexnum;
	int			len;

	hexnum = ft_itoahex((size_t)num, f);
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
		if (write(1, hexnum, len) < 0)
			pack->error = 1;
		else
			*bytes += len;
	}
	if (!pack->error && (pack->width > 0))
		print_wdprec(' ', pack, bytes, 1);
	free((char *)hexnum);
}
