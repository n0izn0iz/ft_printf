#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

#define CMD0 "00_%%#0 -10.5: %#0 -10.5i, %#0 -10.5i, %#0 -10.5u, %#0 -10.5o, %#0 -10.5x\n", 1337, -1337, 1234, 01234, 0x1234

int		std_printf(void)
{
	printf(CMD0);
	/*printf(CMD1);
	printf(CMD2);
	printf(CMD3);
	printf(CMD4);
	printf(CMD5);
	printf(CMD6);
	printf(CMD7);
	printf(CMD8);*/
	return (0);
}

int		own_printf(void)
{
	ft_printf(CMD0);
	/*ft_printf(CMD1);
	ft_printf(CMD2);
	ft_printf(CMD3);
	ft_printf(CMD4);
	ft_printf(CMD5);
	ft_printf(CMD6);
	ft_printf(CMD7);
	ft_printf(CMD8);*/
	return (0);
}
