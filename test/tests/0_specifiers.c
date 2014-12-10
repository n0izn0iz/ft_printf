#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

#define CMD0 "00_%%c: %c %c %c %c %c %c\n", '0', '3', '7', 'A', 'b', 'C'
#define CMD1 "01_%%s: %s %s %s %s %s %s\n", "Hello", "ceci", "est", "un", "test", ""
#define CMD2 "02_%%i: %i %i %i %i %i %i\n", 0, 42, -7, 7, (int)INT32_MAX, (int)INTMAX_MIN
#define CMD3 "03_%%d: %d %d %d %d %d %d\n", 0, 42, -7, 7, (int)INT32_MAX, (int)INTMAX_MIN
#define CMD4 "04_%%u: %u %u %u %u %u\n", 0, 42, -7, 7, (unsigned int)UINTMAX_MAX
#define CMD5 "05_%%o: %o %o %o %o\n", 00, 042, 01337,  UINT32_MAX
#define CMD6 "06_%%x: %x %x %x %x %x %x\n", 42, -7, 7, (int)INTMAX_MAX, (int)INTMAX_MIN, 0xABCD
#define CMD7 "07_%%X: %X %X %X %X %X %X\n", 42, -7, 7, (int)INTMAX_MAX, (int)INTMAX_MIN, 0xABCD
#define CMD8 "08_%%p: %p %p %p %p %p\n", (void*)0, (void*)0x42, (void*)0x1337, (void*)UINTMAX_MAX, (void*)-1

int		std_printf(void)
{
	
	printf(CMD0);
	printf(CMD1);
	printf(CMD2);
	printf(CMD3);
	printf(CMD4);
	printf(CMD5);
	printf(CMD6);
	printf(CMD7);
	printf(CMD8);
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
	ft_printf(CMD7);
	ft_printf(CMD8);
	return (0);
}
