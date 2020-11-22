#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	/*
	printf("%di TESTST\n");

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
	*/

/*
printf("%% TEST\n");

printf("set 1\n");
	ft_printf("[%%]\n");
	printf("[%%]\n");

printf("set 2\n");
	ft_printf("[%.6%]\n");
	printf("[%.6%]\n");

printf("set 3\n");
	ft_printf("[%.*%]\n", -9);
	printf("[%.*%]\n", -9);

printf("set 4\n");
	ft_printf("[%.5%]\n");
	printf("[%.5%]\n");

printf("set 5\n");
	ft_printf("[%.*%]\n", 5);
	printf("[%.*%]\n", 5);

printf("set 6\n");
	ft_printf("[%.%]\n");
	printf("[%.%]\n");

printf("set 7\n");
	ft_printf("[%.0%]\n");
	printf("[%.0%]\n");

printf("set 8\n");
	ft_printf("[%.*%]\n", 0);
	printf("[%.*%]\n", 0);

printf("set 9\n");
	ft_printf("[%3%]\n");
	printf("[%3%]\n");

printf("set 10\n");
	ft_printf("[%06%]\n");
	printf("[%06%]\n");

printf("set 11\n");
	ft_printf("[%-6%]\n");
	printf("[%-6%]\n");

printf("set 12\n");
	ft_printf("[%0-6%]\n");
	printf("[%0-6%]\n");

printf("set 13\n");
	ft_printf("[%-06%]\n");
	printf("[%-06%]\n");

printf("set 14\n");
	ft_printf("[%1%]\n");
	printf("[%1%]\n");
*/
/*
printf("%%u TEST\n");

printf("set 1\n");
	ft_printf("[%u]\n", -21);
	printf("[%u]\n", -21);
	ft_printf("[%u]\n", 0);
	printf("[%u]\n", 0);

printf("set 2\n");
	ft_printf("[%-05u]\n", 4294967295);
	printf("[%-05u]\n", 4294967295);

printf("set 3\n");
	ft_printf("[%-5.7u]\n", 4294967297);
	printf("[%-5.7u]\n", 4294967297);

printf("set 4\n");
	ft_printf("[%8.*u]\n", -9, 0);
	printf("[%8.*u]\n", -9, 0);

printf("set 5\n");
	ft_printf("[%.u]\n", 42);
	printf("[%.u]\n", 42);

printf("set 6\n");
	ft_printf("[%.*u]\n", 0, 0);
	printf("[%.*u]\n", 0, 0);

printf("set 7\n");
	ft_printf("[%.0u]\n", 3);
	printf("[%.0u]\n", 3);

printf("set 8\n");
	ft_printf("[%.*u]\n", -9, 0);
	printf("[%.*u]\n", -9, 0);

printf("set 9\n");
	ft_printf("[%.*u]\n", -9, 11);
	printf("[%.*u]\n", -9, 11);

printf("set 10\n");
	ft_printf("[%.u]\n", 0);
	printf("[%.u]\n", 0);

printf("set 11\n");
	ft_printf("[%-6.3u]\n", 4294967290);
	printf("[%-6.3u]\n", 4294967290);

printf("set 12\n");
	ft_printf("[%0-6u]\n", 0);
	printf("[%0-6u]\n", 0);
*/

printf("%%xX TEST\n");

printf("set 1\n");
	ft_printf("[%x]\n", 0);
	printf("[%x]\n", 0);
	ft_printf("[%5.X]\n", 0);
	printf("[%5.X]\n", 0);

printf("set 2\n");
	ft_printf("[%-05x]\n", 4294967295);
	printf("[%-05x]\n", 4294967295);

printf("set 3\n");
	ft_printf("[%-5.7X]\n", 4294967297);
	printf("[%-5.7X]\n", 4294967297);

printf("set 4\n");
	ft_printf("[%8.*x]\n", -9, 0);
	printf("[%8.*x]\n", -9, 0);

printf("set 5\n");
	ft_printf("[%.x]\n", 42);
	printf("[%.x]\n", 42);

printf("set 6\n");
	ft_printf("[%.*X]\n", 0, 0);
	printf("[%.*X]\n", 0, 0);

printf("set 7\n");
	ft_printf("[%.0x]\n", 3);
	printf("[%.0x]\n", 3);

printf("set 8\n");
	ft_printf("[%-10.x]\n", 455);
	printf("[%-10.x]\n", 455);

printf("set 9\n");
	ft_printf("[%012.1x]\n", 111);
	printf("[%012.1x]\n", 111);

printf("set 10\n");
	ft_printf("[%.x]\n", 0);
	printf("[%.x]\n", 0);

printf("set 11\n");
	ft_printf("[%-6.3X]\n", 4294967290);
	printf("[%-6.3X]\n", 4294967290);
	return (0);
}