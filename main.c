#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("[%00007d]\n", 21);
	printf("[%0000--8d]\n", 21);
	printf("[%---6d]\n", 21);
	
	return (0);
}