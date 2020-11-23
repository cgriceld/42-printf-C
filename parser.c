#include "ft_printf.h"

static void	get_flags(const char **format, t_ppack *pack)
{
	const char	*tmp;
	int			was_zero;

	tmp = *format;
	was_zero = 0;
	while (*tmp == '-' || *tmp == '0')
	{
		if (*tmp == '-' && !pack->minus)
			pack->minus++;
		if (*tmp++ == '0' && !was_zero)
			was_zero++;
	}
	pack->zero = (!pack->minus && was_zero) ? 1 : 0;
	*format = tmp;
}

static void	get_width(const char **format, t_ppack *pack, va_list ap)
{
	const char	*tmp;

	tmp = *format;
	if (*tmp == '*')
	{
		pack->width = va_arg(ap, int);
		if (pack->width < 0)
		{
			pack->minus = 1;
			pack->width *= -1;
		}
		*format = ++tmp;
		return ;
	}
	pack->width = ft_atoi(tmp++);
	while (ft_isdigit(*tmp))
		tmp++;
	*format = tmp;
}

static void	get_prec(const char **format, t_ppack *pack, va_list ap)
{
	const char *tmp;

	tmp = *format;
	if (*++tmp == '*')
	{
		if ((pack->prec = va_arg(ap, int)) < 0)
		{
			pack->prec = 0;
			pack->negprec = 1;
		}
		*format = ++tmp;
		return ;
	}
	else if (ft_isdigit(*tmp))
	{
		pack->prec = ft_atoi(tmp++);
		if (pack->prec < 0)
			pack->error = 1;
		while (ft_isdigit(*tmp))
			tmp++;
	}
	else
		pack->prec = 0;
	*format = tmp;
}

static void	process_type(t_ppack *pack, va_list ap, int *bytes)
{
	if (pack->type == 'd' || pack->type == 'i')
		print_di(pack, va_arg(ap, int), bytes);
	else if (pack->type == '%')
		print_perc(pack, bytes);
	else if (pack->type == 'u')
		print_u(pack, va_arg(ap, unsigned int), bytes);
	else if (pack->type == 'x')
		print_hex(pack, va_arg(ap, unsigned int), 0, bytes);
	else if (pack->type == 'X')
		print_hex(pack, va_arg(ap, unsigned int), 1, bytes);
	else if (pack->type == 'c')
		print_c(pack, va_arg(ap, int), bytes);
	else if (pack->type == 's')
		print_s(pack, va_arg(ap, char *), bytes);
}

void	parser(const char **format, t_ppack *pack, va_list ap, int *bytes)
{
	if (**format == '-' || **format == '0')
		get_flags(format, pack);
	else
		pack->zero = 0;
	if (ft_isdigit(**format) || **format == '*')
		get_width(format, pack, ap);
	else
		pack->width = 0;
	if (**format == '.')
	{
		pack->wasdot = 1;
		get_prec(format, pack, ap);
	}
	else
		pack->prec = 0;
	if (**format == 'd' || **format == 'i' || **format == 'u' \
		|| **format == 'x' || **format == 'X' || **format == 'c' \
		|| **format == 's' || **format == 'p' || **format == '%')
		pack->type = **format;
	else
		pack->error = 1;
	if (!pack->error)
		process_type(pack, ap, bytes);
}