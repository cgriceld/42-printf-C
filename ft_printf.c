#include "ft_printf.h"

static void	process_type(t_ppack *pack, va_list ap, unsigned char *flags)
{
	if (pack->type == 'd' || pack->type == 'i')
		print_di(pack, va_arg(ap, int), flags);
	else if (pack->type == '%')
		print_perc(pack, flags);
	else if (pack->type == 'u')
		print_u(pack, va_arg(ap, unsigned int), flags);
	else if (pack->type == 'x')
		print_hex(pack, va_arg(ap, unsigned int), 0, flags);
	else if (pack->type == 'X')
		print_hex(pack, va_arg(ap, unsigned int), 1, flags);
	else if (pack->type == 'c')
		print_c(pack, va_arg(ap, int), flags);
	else if (pack->type == 's')
		print_s(pack, va_arg(ap, char *), flags);
	else if (pack->type == 'p')
		print_p(pack, va_arg(ap, void *), flags);
}

static int	collect_pack(const char **format, va_list ap, int *bytes)
{
	t_ppack			*pack;
	unsigned char	flags;

	if (!(pack = (t_ppack *)malloc(sizeof(t_ppack))))
		return (-1);
	pack->width = 0;
	pack->prec = 0;
	pack->bytes = 0;
	flags = 0b00000000;
	parser(format, pack, &flags, ap);
	pack->type == '0' ? --*format : process_type(pack, ap, &flags);
	*bytes += pack->bytes;
	free(pack);
	return ((flags & ERROR) ? -1 : 1);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			bytes;

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
			format++;
			if (collect_pack(&format, ap, &bytes) < 0)
				return (-1);
			format++;
		}
	}
	va_end(ap);
	return (bytes);
}
