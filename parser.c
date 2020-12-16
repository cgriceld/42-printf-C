#include "ft_printf.h"

static void	get_flags(const char **format, unsigned char *flags)
{
	while (**format == '-' || **format == '0')
	{
		if (**format == '-' && !(*flags & MINUS))
			*flags |= MINUS;
		if (**format == '0' && !(*flags & MINUS) && !(*flags & ZERO))
			*flags |= ZERO;
		++*format;
	}
	if ((*flags & MINUS) && (*flags & ZERO))
		*flags &= ~ZERO;
}

static void	get_width(const char **format, t_ppack *pack, va_list ap, \
						unsigned char *flags)
{
	if (**format == '*')
	{
		pack->width = va_arg(ap, int);
		if (pack->width < 0)
		{
			*flags |= MINUS;
			*flags &= ~ZERO;
			pack->width *= -1;
		}
		++*format;
		return ;
	}
	while (ft_isdigit(**format))
	{
		pack->width = pack->width * 10 + (**format - 48);
		++*format;
	}
}

static void	get_prec(const char **format, t_ppack *pack, va_list ap, \
						unsigned char *flags)
{
	*flags |= WASDOT;
	++*format;
	if (**format == '*')
	{
		if ((pack->prec = va_arg(ap, int)) < 0)
		{
			pack->prec = 0;
			*flags |= NEGPREC;
		}
		++*format;
		return ;
	}
	if (**format == '-')
	{
		*flags |= PRECTOW;
		++*format;
	}
	while (ft_isdigit(**format))
	{
		pack->prec = pack->prec * 10 + (**format - 48);
		++*format;
	}
}

void		parser(const char **format, t_ppack *pack, \
					unsigned char *flags, va_list ap)
{
	if (**format == '-' || **format == '0')
		get_flags(format, flags);
	if (ft_isdigit(**format) || **format == '*')
		get_width(format, pack, ap, flags);
	if (**format == '.')
		get_prec(format, pack, ap, flags);
	if (**format == 'd' || **format == 'i' || **format == 'u' \
		|| **format == 'x' || **format == 'X' || **format == 'c' \
		|| **format == 's' || **format == 'p' || **format == '%')
		pack->type = **format;
	else
		pack->type = '0';
}
