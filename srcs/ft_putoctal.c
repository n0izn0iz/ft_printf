#include <stdio.h>
#include <stdint.h>
#include "libft.h"

int 			ft_octlen(uintmax_t oct, int prefix)
{
	int result;

	result = 1;
	if (prefix)
		result ++;
	while (oct >= 8)
	{
		result++;
		oct /= 8;
	}
	return (result);
}

static void putoctal_recursion(uintmax_t octal)
{
	if (octal >= 8)
		putoctal_recursion(octal / 8);
	ft_putchar((octal % 8) + '0');
}

void	ft_putoctal(uintmax_t octal, int prefix)
{
	if (prefix)
		ft_putchar('0');
	putoctal_recursion(octal);
}