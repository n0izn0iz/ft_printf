#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

#define CMD "strs\t: %10s %5s %10s %5s %10s %5s\n", "Hello", "ceci", "est", "un", "test", ""

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