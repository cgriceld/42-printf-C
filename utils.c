#include "ft_printf.h"

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
		n = 10 * n + sign * (*str++ - 48); //*
		if (n > prevn && sign == -1) //**
			return (0);
		if (n < prevn && sign == 1)
			return (-1);
	}
	return (n);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_intlen(int n)
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

int	ft_uintlen(unsigned int n)
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

int	ft_putchar_fd(const char c, const int fd)
{
	if (fd >= 0)
	{
		if (write(fd, &c, 1) < 0)
			return (-1);
		return (1);
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	const char *str;

	str = s;
	while (*str)
		str++;
	return (str - s);
}

static int	ft_hexlen(unsigned int n)
{
	int i;

	i = (n == 0) ? 1 : 0;
	while (n)
	{
		i++;
		n /= 16;
	}
	return (i);
}

char		*ft_itoahex(unsigned int n, const int flag)
{
	int		len;
	char	*str;

	len = ft_hexlen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str += len;
	*str-- = '\0';
	if (!n)
		*str = '0';
	while (n)
	{
		if (n % 16 < 10)
			*str = (n % 16) + 48;
		else
			*str = flag ? (n % 16) + 55 : (n % 16) + 87;
		if (n > 15)
			str--;
		n /= 16;
	}
	return (str);
}

int	ft_putstr_fd(const char *s, const int fd)
{
	if (fd >= 0 && s)
	{
		if (write(fd, s, ft_strlen(s)) < 0)
			return (-1);
		return (1);
	}
	return (-1);
}