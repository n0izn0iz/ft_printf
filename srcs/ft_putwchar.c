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

int			ft_wstrlen (wint_t* wstr)
{
	int i;

	i = 0;
	while (wstr[i] != L'\0')
		i++;
	return (i);
}

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
	int	msb = getmsb(wchar) + 1;
	char	temp[4];

	if (msb <= 7)
	{
		write(1, &(wchar), 1);
	}
	else if (msb <= 11)
	{
		temp[0] = (((wchar >> 6) & PF_GEN_AND) & PF_16BIT_AND) | PF_16BIT_MASK;
		temp[1] = (wchar & PF_GEN_AND) | PF_GEN_MASK;
		write(1, temp, 2);
	}
	else if (msb <= 16)
	{ 
		temp[0] = (((wchar >> 12) & PF_GEN_AND) & PF_32BIT_AND) | PF_32BIT_MASK;
		temp[1] = ((wchar >> 6) & PF_GEN_AND) | PF_GEN_MASK;
		temp[2] = (wchar & PF_GEN_AND) | PF_GEN_MASK;
		write(1, temp, 3);
	}
	else
	{

		write(1, temp, 4);
	}
}

void		ft_putwstr(wchar_t *str)
{
	while (*str)
	{
		ft_putwchar(*str);
		str++;
	}
}

int			ft_min(int a, int b)
{
	return (a < b ? a : b);
}

void		ft_putnstr(char *str, int n)
{
	write(1, str, ft_min(ft_strlen(str), n));
}

void		ft_putnwchar(wchar_t *wchar, int n)
{
	int i;

	i = 0;
	while (*wchar && i < n)
	{
		ft_putwchar(*wchar);
		i++;
	}
}