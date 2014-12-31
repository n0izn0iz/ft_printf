#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

#define CMD0 "00_%%c: %c %c %c %c %c %c\n", '0', '3', '7', 'A', 'b', 'C'
#define CMD0a "00a_%%C: %C, %C, %C, %C, %C\n", L'À', L'ï', L'ê', L'ç', 945
#define CMD1 "01_%%s: %s %s %s %s %s %s %s\n", "Hello", "ceci", "est", "un", "test", "", NULL
#define CMD1a "01a_%%S: %S, %S, %S, %S, %S\n", L"cécï", L"è", L"ün", L"têst", L""
#define CMD2 "02_%%i: %i %i %i %i %i %i\n", 0, 42, -7, 7, (int)INT32_MAX, (int)INTMAX_MIN
#define CMD3 "03_%%d: %d %d %d %d %d %d\n", 0, 42, -7, 7, (int)INT32_MAX, (int)INTMAX_MIN
#define CMD3a "03a_%%D: %D %D %D %D %D %D\n", 0, 42, -7, 7, (int)INT32_MAX, (int)INTMAX_MIN
#define CMD4 "04_%%u: %u %u %u %u %u\n", 0, 42, -7, 7, (unsigned int)UINTMAX_MAX
#define CMD4a "04a_%%U: %U %U %U %U %U\n", 0, 42, -7, 7, (unsigned int)UINTMAX_MAX
#define CMD5 "05_%%o: %o %o %o %o\n", 00, 042, 01337,  UINT32_MAX
#define CMD5a "05a_%%O: %O %O %O %O\n", 00, 042, 01337,  UINT32_MAX
#define CMD6 "06_%%x: %x %x %x %x %x %x\n", 42, -7, 7, (int)INTMAX_MAX, (int)INTMAX_MIN, 0xABCD
#define CMD7 "07_%%X: %X %X %X %X %X %X\n", 42, -7, 7, (int)INTMAX_MAX, (int)INTMAX_MIN, 0xABCD
#define CMD8 "08_%%p: %p %p %p %p %p\n", (void*)0, (void*)0x42, (void*)0x1337, (void*)UINTMAX_MAX, (void*)-1

int		std_printf(void)
{
	printf(CMD0);
	printf(CMD0a);
	printf(CMD1);
	printf(CMD1a);
	printf(CMD2);
	printf(CMD3);
	printf(CMD3a);
	printf(CMD4);
	printf(CMD4a);
	printf(CMD5);
	printf(CMD5a);
	printf(CMD6);
	printf(CMD7);
	printf(CMD8);
	return (0);
}

int		own_printf(void)
{
	ft_printf(CMD0);
	ft_printf(CMD0a);
	ft_printf(CMD1);
	ft_printf(CMD1a);
	ft_printf(CMD2);
	ft_printf(CMD3);
	ft_printf(CMD3a);
	ft_printf(CMD4);
	ft_printf(CMD4a);
	ft_printf(CMD5);
	ft_printf(CMD5a);
	ft_printf(CMD6);
	ft_printf(CMD7);
	ft_printf(CMD8);
	return (0);
}
