#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	/*
	printf("[%00007d]\n", 21);
	printf("[%0000--8d]\n", 21);
	printf("[%---6d]\n", 21);

	printf("[%---6.5d]\n", 21);
	printf("[%---6.-5d]\n", 21);

	printf("[oh!%!]\n", 21);
	*/
	//printf("%s", NULL);
	
	//printf("[%.-4d]\n", 2);
/*
	printf("[aa%W]\n");
	printf("[%04]\n");
	printf("[%-4.5Woo]\n");
*/
	//zero
	printf("-------\n");
	ft_printf("[%4.d]\n", 0);
	printf("[%4.d]\n", 0); // len = 0
	ft_printf("[%4d]\n", 0);
	printf("[%4d]\n", 0);
	printf("-------\n");

	printf("-------\n");
	ft_printf("[aa%04dbb]\n", -42);
	printf("[aa%04dbb]\n", -42);
	printf("-------\n");

	return (0);
}