#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

#define CMD "ints\t: %.5d %.10d %.0d %.5d\n", 7, 7, 0, 5

int		std_printf(void)
{
	
	printf(CMD);
	return (0);
}

int		own_printf(void)
{
	ft_printf(CMD);
	return (0);
}