#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("ZERO TEST\n");
	printf("set 1\n");
	ft_printf("[%4.d]\n", 0);
	printf("[%4.d]\n", 0); // len = 0
	ft_printf("[%04.d]\n", 0);
	printf("[%04.d]\n", 0);

	printf("set 2\n");
	ft_printf("[%4d]\n", 0);
	printf("[%4d]\n", 0);
	ft_printf("[%04d]\n", 0);
	printf("[%04d]\n", 0);

	printf("set 3\n");
	printf("[%.*d]\n", -1, 0);
	ft_printf("[%.*d]\n", -1, 0);
	printf("[%0.*d]\n", -1, 0);
	ft_printf("[%0.*d]\n", -1, 0);

	printf("set 4\n");
	printf("[%.d]\n", 0);
	ft_printf("[%.d]\n", 0);
	printf("[%0.d]\n", 0);
	ft_printf("[%0.d]\n", 0);

	printf("set 5\n");
	printf("[%.0d]\n", 0);
	ft_printf("[%.0d]\n", 0);
	printf("[%0.0d]\n", 0);
	ft_printf("[%0.0d]\n", 0);

	printf("set 6\n");
	printf("[%.*d]\n", 0, 0);
	ft_printf("[%.*d]\n", 0, 0);
	printf("[%0.*d]\n", 0, 0);
	ft_printf("[%0.*d]\n", 0, 0);

	printf("set 7\n");
	printf("[%.*d]\n", -0, 0);
	ft_printf("[%.*d]\n", -0, 0);
	printf("[%0.*d]\n", -0, 0);
	ft_printf("[%0.*d]\n", -0, 0);
	printf("-------\n");
	
	printf("MIN MAX INT TESTS\n");
	ft_printf("[%d]\n", -2147483648);
	printf("[%d]\n", -2147483648);
	ft_printf("[%d]\n", -2147483649);
	printf("[%d]\n", -2147483649);
	ft_printf("[%i]\n", 2147483648);
	printf("[%i]\n", 2147483648);
	ft_printf("[min%04.*dint]\n", 20, -2147483648);
	printf("[min%04.*dint]\n", 20, -2147483648);
	ft_printf("[max%-04.*dint]\n", -20, 2147483647);
	printf("[max%-04.*dint]\n", -20, 2147483647);
	printf("-------\n");

	printf("SOME RANDOM TESTS\n");
	ft_printf("[aa%04dbb]\n", -42);
	printf("[aa%04dbb]\n", -42);
	ft_printf("[%007d]\n", -21);
	printf("[%007d]\n", -21);
	ft_printf("[%0000--8d]\n", -21);
	printf("[%0000--8d]\n", -21);
	ft_printf("[%---6.5d]\n", 21);
	printf("[%---6.5d]\n", 21);
	ft_printf("[%---6.7d]\n", -21);
	printf("[%---6.7d]\n", -21);
	printf("-------\n");

	return (0);
}