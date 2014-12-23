#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

#define CMD0 "10_%%s: %10s   %5s   %10s   %5s   %10s   %5s\n", "Hello", "ceci", "est", "un", "test", ""
#define CMD0a "01a_%%S: %3S %5S %1S %10S %5S\n", L"cécï", L"è", L"ün", L"têst", L""
#define CMD1 "11_%%i: %1i %1i %10i %5i %10i %5i %10i\n", 1337, 0, 123567, 1234567, 0, INT32_MAX, INT32_MIN
#define CMD2 "12_%%d: %1d %1d %10d %5d %10d %5d %10d\n", 1337, 0, 123567, 1234567, 0, INT32_MAX, INT32_MIN
#define CMD2a "03a_%%D: %1D %1D %10D %5D %10D %5D\n", 0, 42, -7, 7, (int)INT32_MAX, (int)INTMAX_MIN
#define CMD3 "13_%%u: %1u %5u %10u %5u %10u\n", 123567, 1234567, 0, UINT32_MAX, INT32_MIN
#define CMD3a "04a_%%U: %1U %5U %10U %5U %10U\n", 0, 42, -7, 7, (unsigned int)UINTMAX_MAX
#define CMD4 "14_%%c: %1c %5c %10c %5c %10c\n", 'A', '0', 'b', '1', 'C'
#define CMD4a "14a_%%C: %1C, %5C, %1C, %5C, %1C\n", L'À', L'ï', L'ê', L'ç', 945
#define CMD5 "15_%%p: %10p %30p %10p %30p %10p\n", (void*)0, (void*)0x42, (void*)0x1337, (void*)UINTMAX_MAX, (void*)-1
#define CMD6 "16_%%x: %10x %30x %10x %10x %30x %10x\n", 42, -7, 7, (int)INTMAX_MAX, (int)INTMAX_MIN, 0xABCD
#define CMD7 "17_%%X: %10X %30X %10X %10X %30X %10X\n", 42, -7, 7, (int)INTMAX_MAX, (int)INTMAX_MIN, 0xABCD
#define CMD8 "18_%%o: %1o %5o %10o %5o %10o\n", 123567, 1234567, 0, UINT32_MAX, INT32_MIN
#define CMD8a "05a_%%O: %1O %5O %10O %5O\n", 00, 042, 01337,  UINT32_MAX

int		std_printf(void)
{
	int tmp = 0;
	printf(CMD0);
	printf(CMD0a);
	printf(CMD1);
	printf(CMD2);
	printf(CMD2a);
	printf(CMD3);
	printf(CMD3a);
	printf(CMD4);
	printf(CMD4a);
	printf(CMD5);
	printf(CMD6);
	printf(CMD7);
	printf(CMD8);
	printf(CMD8a);
	return (0);
}

int		own_printf(void)
{
	int tmp = 0;
	ft_printf(CMD0);
	ft_printf(CMD0a);
	ft_printf(CMD1);
	ft_printf(CMD2);
	ft_printf(CMD2a);
	ft_printf(CMD3);
	ft_printf(CMD3a);
	ft_printf(CMD4);
	ft_printf(CMD4a);
	ft_printf(CMD5);
	ft_printf(CMD6);
	ft_printf(CMD7);
	ft_printf(CMD8);
	ft_printf(CMD8a);
	return (0);
}