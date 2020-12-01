#include "ft_printf.h"

/*
** If flag = 1, write ch (0 or space) within width,
** set error flag if error in write call and break then.
** If flag = 0, write '0' within precision and also track errors.
** Increase written bytes.
*/

void		print_wdprec(const char ch, t_ppack *pack, int *bytes, int flag)
{
	while (flag && pack->width--)
	{
		if (write(1, &ch, 1) < 0)
		{
			pack->error = 1;
			return ;
		}
		*bytes += 1;
	}
	while (!flag && pack->prec--)
	{
		if (write(1, &ch, 1) < 0)
		{
			pack->error = 1;
			return ;
		}
		*bytes += 1;
	}
}
