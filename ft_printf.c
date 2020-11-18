#include "ft_printf.h"

static void	init_pack(t_ppack *pack)
{
	pack->minus = 0;
	pack->prec = 0;
	pack->width = 0;
	pack->type = '0';
}

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

}

static void	parser(const char *format, t_ppack *pack, va_list ap, int *bytes)
{
	get_flags(&format, pack);
	if (ft_isdigit(*format))
		get_width(&format, pack, ap);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap; // sizeof(argptr)?
	int			bytes;
	t_ppack		*pack;

	pack = (t_ppack *)malloc(sizeof(t_ppack));
	if (!pack)
		return (-1);
	bytes = 0;
	va_start(ap, format); // format - fist and last known parameter, init ap pointer
	while (*format && *format != '%')
	{
		write(1, format++, 1);
		bytes++;
	}
	if (*format == '%')
	{
		init_pack(pack);
		parser(++format, pack, ap, &bytes);
	}
	va_end(ap); // reload stack
	free(pack);
	return (bytes);
}