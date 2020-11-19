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
		pack->prec = va_arg(ap, int);
		if (pack->prec < 0)
			pack->prec = 0;
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

static void	print_di(t_ppack *pack, int num)
{
	int len;

	len = numlen(num);

}

static void	process_type(t_ppack *pack, va_list ap, int *bytes)
{
	if (pack->type == '0')
		pack->error = 1;
	else if (pack->type == 'd' || pack->type == 'i')
		print_di(pack, va_arg(ap, int));
}

static void	parser(const char **format, t_ppack *pack, va_list ap, int *bytes)
{
	pack->minus = 0;
	if (**format == '-' || **format == '0')
		get_flags(format, pack);
	else
		pack->zero = 0;
	if (ft_isdigit(**format) || **format == '*')
		get_width(format, pack, ap);
	else
		pack->width = 0;
	if (**format == '.')
		get_prec(format, pack, ap);
	else
		pack->prec = 0;
	if (**format == 'd' || **format == 'i' || **format == 'u' || **format == 'x' \
	|| **format == 'X' || **format == 'c' || **format == 's' || **format == 'p')
		pack->type = **format;
	else
		pack->type = '0';
	pack->error = 0;
	process_type(pack, ap, bytes);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			bytes;
	t_ppack		*pack;

	bytes = 0;
	va_start(ap, format);
	while (*format)
	{
		while (*format && *format != '%')
		{
			if (write(1, format++, 1) < 0)
				return (-1);
			bytes++;
		}
		if (*format == '%')
		{
			if (!(pack = (t_ppack *)malloc(sizeof(t_ppack))))
				return (-1);
			format++;
			parser(&format, pack, ap, &bytes);
			free(pack);
		}
	}
	va_end(ap);
	return (bytes);
}