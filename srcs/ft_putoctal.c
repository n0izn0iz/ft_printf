#include "libft.h"

static void putoctal_recursion(int octal)
{
	if (octal >= 8)
		putoctal_recursion(octal / 8);
	ft_putchar((octal % 8) + '0');
}

void	ft_putoctal(int octal, int prefix)
{
	if (prefix)
		ft_putchar('0');
	putoctal_recursion(octal);
}