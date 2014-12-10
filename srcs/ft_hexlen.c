#include <stdint.h>

int		ft_hexlen(uintmax_t hex, int prefix)
{
	int result;

	result = 1;
	if (prefix)
		result += 2;
	while (hex >= 16)
	{
		result++;
		hex /= 16;
	}
	return (result);
}