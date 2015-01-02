#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

#define CMD0  "20_sharp : %#o %#x %#X %#o %#x %#X\n", 042, 0xABCD42, 0xABCD42, 0, 0, 0
#define CMD1  "21_zero  : %04i %010d %05u %07o %03x\n", 42, 42, 42, 42, 42
#define CMD2  "22_plus  : %+i %+d %+i %+d %+i %+d \n", 42, 42, 0, 0, -42, -42
#define CMD3  "23_space : % i % d % i % d % i % d\n", 42, 42, 0, 0, -42, -42
#define CMD4  "24_-%%s   : %-10s   %-5s   %-10s   %-5s   %-10s   %-5s\n", "Hello", "ceci", "est", "un", "test", ""
#define CMD4a "24a_-%%S  : %-3S %-5S %-1S %-10S %-5S\n", L"cécï", L"è", L"ün", L"têst", L""
#define CMD5  "25_-%%i   : %-1i %-1i %-10i %-5i %-10i %-5i %-10i\n", 1337, 0, 123567, 1234567, 0, INT32_MAX, INT32_MIN
#define CMD6  "26_-%%d   : %-1d %-1d %-10d %-5d %-10d %-5d %-10d\n", 1337, 0, 123567, 1234567, 0, INT32_MAX, INT32_MIN
#define CMD6a "26a_-%%D  : %-1D %-1D %-10D %-5D %-10D %-5D\n", 0, 42, -7, 7, (int)INT32_MAX, (int)INTMAX_MIN
#define CMD7  "27_-%%u   : %-1u %-5u %-10u %-5u %-10u\n", 123567, 1234567, 0, UINT32_MAX, INT32_MIN
#define CMD7a "27a_-%%U  : %-1U %-5U %-10U %-5U %-10U\n", 0, 42, -7, 7, (unsigned int)UINTMAX_MAX
#define CMD8  "28_-%%c   : %-1c %-5c %-10c %-5c %-10c\n", 'A', '0', 'b', '1', 'C'
#define CMD8a "28a_-%%C  : %-1C, %-5C, %-1C, %-5C, %-1C\n", L'À', L'ï', L'ê', L'ç', 945
#define CMD9  "29_-%%p   : %-10p %-30p %-10p %-30p %-10p\n", (void*)0, (void*)0x42, (void*)0x1337, (void*)UINTMAX_MAX, (void*)-1
#define CMD10 "210_-%%x  : %-10x %-30x %-10x %-10x %-30x %-10x\n", 42, -7, 7, (int)INTMAX_MAX, (int)INTMAX_MIN, 0xABCD
#define CMD11 "211_-%%X  : %-10X %-30X %-10X %-10X %-30X %-10X\n", 42, -7, 7, (int)INTMAX_MAX, (int)INTMAX_MIN, 0xABCD
#define CMD12 "212_-%%o  : %-1o %-5o %-10o %-5o %-10o\n", 123567, 1234567, 0, UINT32_MAX, INT32_MIN
#define CMD12a "212a_-%%O : %-1O %-5O %-10O %-5O\n", 00, 042, 01337,  UINT32_MAX

int		std_printf(void)
{
	int tmp = 0;
	printf(CMD0);
	printf(CMD1);
	printf(CMD2);
	printf(CMD3);
	printf(CMD4);
	printf(CMD4a);
	printf(CMD5);
	printf(CMD6);
	printf(CMD6a);
	printf(CMD7);
	printf(CMD7a);
	printf(CMD8);
	printf(CMD8a);
	printf(CMD9);
	printf(CMD10);
	printf(CMD11);
	printf(CMD12);
	printf(CMD12a);
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
	ft_printf(CMD4a);
	ft_printf(CMD5);
	ft_printf(CMD6);
	ft_printf(CMD6a);
	ft_printf(CMD7);
	ft_printf(CMD7a);
	ft_printf(CMD8);
	ft_printf(CMD8a);
	ft_printf(CMD9);
	ft_printf(CMD10);
	ft_printf(CMD11);
	ft_printf(CMD12);
	ft_printf(CMD12a);
	return (0);
}
