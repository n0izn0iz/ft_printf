#include <unistd.h>
#include <wchar.h>
#include <stdio.h>
#include <stdint.h>

#include "libft.h"
 
#define PF_8BIT_AND			0b01111111
#define PF_8BIT_MASK		0b00000000
#define PF_16BIT_AND		0b00011111
#define PF_16BIT_MASK		0b11000000
#define PF_24BIT_AND		0b00001111
#define PF_24BIT_MASK		0b11100000
#define PF_32BIT_AND		0b00000111
#define PF_32BIT_MASK		0b11110000
#define PF_GEN_AND			0b00111111
#define PF_GEN_MASK			0b10000000

int			getmsb (unsigned long long x)
{
    int r = 0;
    if (x < 1)
    	return 0;
    while (x >>= 1) 
    	r++;
    return r;
}

void		print_bits(uintmax_t bits, int n)
{
	ft_putstr("0b");
	int i = 0;
	while (i < n)
	{
		ft_putchar('0' + ((bits >> (n - i - 1)) & 1));
		i++;
	}
}

void		ft_putwchar(wint_t wchar)
{
	int	msb = getmsb(wchar);
	unsigned int	temp[4];
	unsigned int	conversion;
	if (msb <= 6)
		write(1, &wchar, 1);
	else if (msb <= 11)
	{
		temp[1] = (wchar & PF_GEN_AND) | PF_GEN_MASK;
		temp[0] = (((wchar >> 6) & PF_GEN_AND) & PF_16BIT_AND) | PF_16BIT_MASK;
		write(1, &(temp[0]), 1);
		write(1, &(temp[1]), 1);
	}
	else if (msb <= 16)
	{ 
		ft_putstr("found 3 byte char: ");
		conversion = ((temp[2] & PF_16BIT_AND) | PF_16BIT_MASK) + ((temp[1] & PF_GEN_AND) | PF_GEN_MASK) + ((temp[0] & PF_GEN_AND) | PF_GEN_MASK);
		write(1, &conversion, 3);
	}
	else
	{
		ft_putstr("found 4 byte char\n");
		conversion = ((temp[3] & PF_16BIT_AND) | PF_16BIT_MASK) + ((temp[2] & PF_GEN_AND) | PF_GEN_MASK) + ((temp[1] & PF_GEN_AND) | PF_GEN_MASK) + ((temp[0] & PF_GEN_AND) | PF_GEN_MASK);
		write(1, &conversion, 4);
	}
}

void		ft_putwstr(wint_t *str)
{
	while (*str)
	{
		ft_putwchar(*str);
		str++;
	}
}