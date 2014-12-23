/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcrtomb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:47:18 by nmeier            #+#    #+#             */
/*   Updated: 2014/12/23 14:47:20 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

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

static inline int	get_msb(unsigned long long x)
{
	int r;

	r = 0;
	if (x < 1)
		return (0);
	while (x >>= 1)
		r++;
	return (r);
}

static inline void	two_bytes(char *s, wchar_t wchar)
{
	s[0] = ((wchar >> 6) & PF_16BIT_AND) | PF_16BIT_MASK;
	s[1] = (wchar & PF_GEN_AND) | PF_GEN_MASK;
}

static inline void	three_bytes(char *s, wchar_t wchar)
{
	s[0] = ((wchar >> 12) & PF_24BIT_AND) | PF_24BIT_MASK;
	s[1] = ((wchar >> 6) & PF_GEN_AND) | PF_GEN_MASK;
	s[2] = (wchar & PF_GEN_AND) | PF_GEN_MASK;
}

static inline void	four_bytes(char *s, wchar_t wchar)
{
	s[0] = ((wchar >> 18) & PF_32BIT_AND) | PF_32BIT_MASK;
	s[1] = ((wchar >> 12) & PF_GEN_AND) | PF_GEN_MASK;
	s[2] = ((wchar >> 6) & PF_GEN_AND) | PF_GEN_MASK;
	s[3] = (wchar & PF_GEN_AND) | PF_GEN_MASK;
}

size_t				ft_wcrtomb(char *s, wchar_t wchar)
{
	int	msb;

	msb = get_msb(wchar);
	if (msb <= 6)
	{
		s[0] = wchar;
		return (1);
	}
	else if (msb <= 10)
	{
		two_bytes(s, wchar);
		return (2);
	}
	else if (msb <= 15)
	{
		three_bytes(s, wchar);
		return (3);
	}
	else
	{
		four_bytes(s, wchar);
		return (4);
	}
}
