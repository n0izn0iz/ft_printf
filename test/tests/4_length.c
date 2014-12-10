#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

#define CMD0 "40_ints: %hhi %hi %li %lli %ji %zi\n", INT8_MAX, INT16_MAX, (long int)INT32_MAX, (long long int)INT64_MAX, (intmax_t)INT64_MAX, (size_t)INT64_MAX
#define CMD1 "41_uints: %hhu %hu %lu %llu %ju %zu\n", UINT8_MAX, UINT16_MAX, (long int)UINT32_MAX, (long long unsigned int)UINT64_MAX, (intmax_t)UINT64_MAX, (size_t)UINT64_MAX
#define CMD2 "42_chars: %c %lc\n", 0x00E0, 0x00E0

int		std_printf(void)
{
	
	printf(CMD0);
	printf(CMD1);
	/*printf(CMD2);*/
	return (0);
}

int		own_printf(void)
{
	ft_printf(CMD0);
	ft_printf(CMD1);
	/*ft_printf(CMD2);*/
	return (0);
}