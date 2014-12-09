#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

#define CMD "ints\t: %i %d %d %d %d %d\n", 42, 42, -7, 7, (int)INTMAX_MAX, (int)INTMAX_MIN
#define CMD2 "uints\t: %u %u %u %u %u %u\n", 42, 42, -7, 7, (unsigned int)UINTMAX_MAX, (unsigned int)4294967295
#define CMD3 "uhexs\t: %x %x %x %x %x %x\n", 42, 42, -7, 7, (int)INTMAX_MAX, (int)INTMAX_MIN

int		std_printf(void)
{
	printf(CMD);
	printf(CMD2);
	printf(CMD3);
	return (0);
}

int		own_printf(void)
{
	ft_printf(CMD);
	ft_printf(CMD2);
	ft_printf(CMD3);
	return (0);
}

int 	main(int argc, char **argv)
{
	(void)argv;
	if (argc > 1)
		own_printf();
	else
		std_printf();
	return (0);
}
