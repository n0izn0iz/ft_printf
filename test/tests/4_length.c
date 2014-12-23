#include <stdio.h>
#include <stdint.h>
#include "ft_printf.h"

#define CMD0 "40_%%i: %hhi %hi %li %lli %ji %zi\n", INT8_MAX, INT16_MAX, (long int)INT32_MAX, (long long int)INT64_MAX, (intmax_t)INT64_MAX, (size_t)INT64_MAX
#define CMD1 "41_%%d: %hhd %hd %ld %lld %jd %zd\n", INT8_MAX, INT16_MAX, (long int)INT32_MAX, (long long int)INT64_MAX, (intmax_t)INT64_MAX, (size_t)INT64_MAX
#define CMD2 "42_%%u: %hhu %hu %lu %llu %ju %zu\n", UINT8_MAX, UINT16_MAX, (long int)UINT32_MAX, (long long unsigned int)UINT64_MAX, (intmax_t)UINT64_MAX, (size_t)UINT64_MAX
#define CMD3 "43_%%o: %hho %ho %lo %llo %jo %zo\n", UINT8_MAX, UINT16_MAX, (long int)UINT32_MAX, (long long unsigned int)UINT64_MAX, (intmax_t)UINT64_MAX, (size_t)UINT64_MAX
#define CMD4 "44_%%x: %hhx %hx %lx %llx %jx %zx\n", UINT8_MAX, UINT16_MAX, (long int)UINT32_MAX, (long long unsigned int)UINT64_MAX, (intmax_t)UINT64_MAX, (size_t)UINT64_MAX
#define CMD5 "45_%%X: %hhX %hX %lX %llX %jX %zX\n", UINT8_MAX, UINT16_MAX, (long int)UINT32_MAX, (long long unsigned int)UINT64_MAX, (intmax_t)UINT64_MAX, (size_t)UINT64_MAX
#define CMD6 "46_%%c: %c %lc\n", 0x00E0, 0x00E0
#define CMD7 "47_%%s: %s %ls\n", L"test", L"tést"

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
	return (0);
}