#include "ft_printf.h"

static int	collect_pack(const char **format, va_list ap, int *bytes)
{
	t_ppack		*pack;

	if (!(pack = (t_ppack *)malloc(sizeof(t_ppack))))
		return (-1);
	pack->minus = 0;
	pack->error = 0;
	pack->wasdot = 0;
	pack->negprec = 0;
	parser(format, pack, ap, bytes);
	if (pack->error)
	{
		free(pack);
		return (-1);
	}
	free(pack);
	return (1);
}

int	ft_printf(const char *format, ...)
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