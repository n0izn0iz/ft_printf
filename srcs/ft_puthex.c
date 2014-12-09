#include "libft.h"

static void	puthex_recursion(size_t hex, int caps)
{
	if (hex >= 16)
		puthex_recursion(hex / 16, caps);
	if ((hex = hex % 16) < 10)
		ft_putchar(hex + '0');
	else
	{
		if (caps)
			ft_putchar(hex - 10 + 'A');
		else
			ft_putchar(hex - 10 + 'a');
	}
}

void		ft_puthex(size_t hex, int prefix, int caps)
{
	if (prefix)
	{
		ft_putchar('0');
		if (caps)
			ft_putchar('X');
		else
			ft_putchar('x');
	}
	puthex_recursion(hex, caps);
}