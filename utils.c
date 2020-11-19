#include "ft_printf.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

static int	ft_issign(const char c)
{
	return (c == 43 || c == 45);
}

static int	ft_isspace(const char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int			ft_atoi(const char *str)
{
	long long int	prevn;
	long long int	n;
	int				sign;

	n = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (ft_issign(*str) && *str++ == '-')
		sign = -1;
	while (*str && ft_isdigit(*str))
	{
		prevn = n;
		n = 10 * n + sign * (*str++ - 48);
		if (n > prevn && sign == -1)
			return (0);
		if (n < prevn && sign == 1)
			return (-1);
	}
	return (n);
}

size_t	ft_strlen(const char *s)
{
	const char *str;

	str = s;
	while (*str)
		str++;
	return (str - s);
}

char	*percchr(const char *s)
{
	while (*s && *s != '%')
		s++;
	return (*s == '%' ? (char *)s : NULL);
}

int	putformat(const char **s)
{
	const char	*tmp;
	int			bytes;

	tmp = *s;
	bytes = 0;
	while (*tmp)
	{
		if (write(1, tmp++, 1) < 0)
			return (-1);
		bytes++;
	}
	*s = tmp;
	return (bytes);
}

//without sign
int	numlen(int n)
{
	int i;

	i = (n == 0) ? 1 : 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}