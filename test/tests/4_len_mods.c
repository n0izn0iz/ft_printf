#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

#define CMD "ints\t: %hhi %hi %li %lli %ji %zi\n", INT8_MAX, INT16_MAX, (long int)INT32_MAX, INT64_MAX, (intmax_t)INT64_MAX, (size_t)INT64_MAX
#define CMD2 "uints\t: %hhu %hu %lu %llu %ju %zu\n", UINT8_MAX, UINT16_MAX, (long int)UINT32_MAX, UINT64_MAX, (intmax_t)UINT64_MAX, (size_t)UINT64_MAX
#define CMD3 "chars\t: %c %lc\n", 0x00E0, 0x00E0
int		std_printf(void)
{
	
	printf(CMD);
	printf(CMD2);
	printf(CMD3);
	return (0);
}

int		own_printf(void)
{
	ft_printf(CMD);
	ft_printf(CMD2);
	ft_printf(CMD3);
	return (0);
}