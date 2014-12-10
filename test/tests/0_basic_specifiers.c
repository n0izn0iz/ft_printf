#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

#define CMD3 "strs\t: %s %s %s %s %s %s\n", "Hello", "ceci", "est", "un", "test", ""
#define CMD4 "ptrs\t: %p %p %p %p\n", (void*)0, (void*)0x42, (void*)0x1337, (void*)UINTMAX_MAX
#define CMD5 "ints\t: %i %d %d %d %d %d %d\n", 42, 42, -7, 7, (int)INTMAX_MAX, (int)INTMAX_MAX, (int)INTMAX_MIN
#define CMD6 "octaux\t: %o %o %o %o %o\n", 00, 042, 01337, (int)UINTMAX_MAX, (unsigned int)UINTMAX_MAX
#define CMD7 "uints\t: %u %u %u %u %u %u\n", 0, 42, -7, 7, (unsigned int)UINTMAX_MAX, (unsigned int)4294967295
#define CMD8 "uhexs\t: %x %x %x %x %x %x %X %x\n", 42, 42, -7, 7, (int)INTMAX_MAX, (int)INTMAX_MIN, 0xABCD, 0xABCD
#define CMD9 "uchar\t: %c %c %c %c %c %c\n", '0', '3', '7', 'A', 'b', 'C'

int		std_printf(void)
{
	
	printf(CMD3);
	printf(CMD4);
	printf(CMD5);
	printf(CMD6);
	printf(CMD7);
	printf(CMD8);
	printf(CMD9);
	return (0);
}

int		own_printf(void)
{
	ft_printf(CMD3);
	ft_printf(CMD4);
	ft_printf(CMD5);
	ft_printf(CMD6);
	ft_printf(CMD7);
	ft_printf(CMD8);
	ft_printf(CMD9);
	return (0);
}
