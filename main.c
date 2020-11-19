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
	printf("[%4.3d]\n", -62);

	return (0);
}