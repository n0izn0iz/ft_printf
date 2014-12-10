#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

#define CMD "sharp\t: %#o %#x %#X\n", 042, 0xABCD42, 0xABCD42
#define CMD2 "zero\t: %05i %010i %04i\n", 1234567, 1234567, 1234
#define CMD3 "plus\t: %+i %+i %+i\n", (int)INT32_MIN, (int)INT32_MAX, 0
#define CMD4 "space\t: % i % i % i\n", (int)INT32_MIN, (int)INT32_MAX, 0
#define CMD5 "minus\t: %-10s %-5s %-10s %-5s %-10s %-5s\n", "Hello", "ceci", "est", "un", "test", ""

int		std_printf(void)
{
	printf(CMD);
	printf(CMD2);
	printf(CMD3);
	printf(CMD4);
	printf(CMD5);
	return (0);
}

int		own_printf(void)
{
	ft_printf(CMD);
	ft_printf(CMD2);
	ft_printf(CMD3);
	ft_printf(CMD4);
	ft_printf(CMD5);
	return (0);
}