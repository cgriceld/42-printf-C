#include "ft_printf.h"

static void	process_type(t_ppack *pack, va_list ap, int *bytes)
{
	if (pack->error)
		return ;
	if (pack->type == '0')
		pack->error = 1;
	else if (pack->type == 'd' || pack->type == 'i')
		print_di(pack, va_arg(ap, int), bytes);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			bytes;
	t_ppack		*pack;

	bytes = 0;
	va_start(ap, format);
	while (*format) // && !pack->error
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
	return (bytes); // pack->error ? -1 : bytes
}