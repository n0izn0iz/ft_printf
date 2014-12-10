#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

#define CMD0  "20_sharp : %#o %#x %#X %#o %#x %#X\n", 042, 0xABCD42, 0xABCD42, 0, 0, 0
#define CMD1  "21_zero  : %04i %010d %05u %07o %03x\n", 42, 42, 42, 42, 42
#define CMD2  "22_plus  : %+i %+d %+i %+d %+i %+d \n", 42, 42, 0, 0, -42, -42
#define CMD3  "23_space : % i % d % i % d % i % d\n", 42, 42, 0, 0, -42, -42
#define CMD4  "24_min%%s : %-10s %-5s %-10s %-5s %-10s %-5s\n", "Hello", "ceci", "est", "un", "test", ""
#define CMD5  "25_min%%i : %-10i %-5i %-10i %-5i %-10i\n", 123567, 1234567, 0, INT32_MAX, INT32_MIN
#define CMD6  "26_min%%d : %-10d %-5d %-10d %-5d %-10d\n", 123567, 1234567, 0, INT32_MAX, INT32_MIN
#define CMD7  "27_min%%u : %-5u %-10u %-5u %-10u\n", 1234567, 0, UINT32_MAX, INT32_MIN
#define CMD8  "28_min%%c : %-1c %-5c %-10c %-5c %-10c\n", 'A', '0', 'b', '1', 'C'
#define CMD9  "29_min%%p : %-10p %-30p %-10p\n", &tmp, &tmp, &tmp
#define CMD10 "210_min%%x: %-10x %-30x %-10x\n", (unsigned int)(size_t)&tmp, (unsigned int)(size_t)&tmp, (unsigned int)(size_t)&tmp
#define CMD11 "211_min%%X: %-10X %-30X %-10X\n", (unsigned int)(size_t)&tmp, (unsigned int)(size_t)&tmp, (unsigned int)(size_t)&tmp
#define CMD12 "212_min%%o: %-5o %-10o %-5o %-10o\n", 1234567, 0, UINT32_MAX, INT32_MIN

int		std_printf(void)
{
	int tmp = 0;
	printf(CMD0);
	printf(CMD1);
	printf(CMD2);
	printf(CMD3);
	printf(CMD4);
	printf(CMD5);
	printf(CMD6);
	printf(CMD7);
	printf(CMD8);
	printf(CMD9);
	printf(CMD10);
	printf(CMD11);
	printf(CMD12);
	return (0);
}

int		own_printf(void)
{
	int tmp = 0;
	ft_printf(CMD0);
	ft_printf(CMD1);
	ft_printf(CMD2);
	ft_printf(CMD3);
	ft_printf(CMD4);
	ft_printf(CMD5);
	ft_printf(CMD6);
	ft_printf(CMD7);
	ft_printf(CMD8);
	ft_printf(CMD9);
	ft_printf(CMD10);
	ft_printf(CMD11);
	ft_printf(CMD12);
	return (0);
}