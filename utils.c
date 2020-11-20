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

// now track write errors, add to lib
int	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
	{
		if (write(fd, &c, 1) < 0)
			return (-1);
		return (1);
	}
	return (-1);
}

// stay in utils, print without sign
void	print_num(int n, t_ppack *pack, int *bytes)
{
	int sign;

	sign = (n < 0) ? -1 : 1;
	if (n <= -10 || n >= 10)
		print_num(n / 10, pack, bytes);
	if (ft_putchar_fd(n % 10 * sign + 48, 1) < 0)
	{
		pack->error = 1;
		return ;
	}
	else
		*bytes += 1;
}