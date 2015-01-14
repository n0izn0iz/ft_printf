#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

#define CMD0 "30_%%d: %.5d %.10d %.0d %.5d\n", 7, 7, 0, 5
#define CMD1 "30_%%i: %.5i %.10i %.0i %.5i\n", 7, 7, 0, 5
#define CMD2 "30_%%o: %.5o %.10o %.0o %.5o\n", 7, 7, 0, 5
#define CMD3 "30_%%u: %.5u %.10u %.0u %.5u\n", 7, 7, 0, 5
#define CMD4 "30_%%x: %.5x %.10x %.0x %.5x\n", 7, 7, 0, 5
#define CMD5 "30_%%X: %.5X %.10X %.0X %.5X\n", 7, 7, 0, 5
#define CMD6 "30_%%s: %.5s %.10s %.0s %.5s\n", "testtes", "testtes", "none", "jam"

int		std_printf(void)
{
	
	printf(CMD0);
	printf(CMD1);
	printf(CMD2);
	printf(CMD3);
	printf(CMD4);
	printf(CMD5);
	printf(CMD6);
	return (0);
}

int		own_printf(void)
{
	ft_printf(CMD0);
	ft_printf(CMD1);
	ft_printf(CMD2);
	ft_printf(CMD3);
	ft_printf(CMD4);
	ft_printf(CMD5);
	ft_printf(CMD6);
	return (0);
}
