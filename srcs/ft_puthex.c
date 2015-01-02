/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:21:09 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/02 14:15:54 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "ft_vartoa.h"
#include "ft_varlen.h"
#include "libft.h"

void			ft_puthex(uintmax_t hex, int prefix, int caps)
{
	char		*str;

	str = ft_hextoa(hex, prefix, caps);
	ft_putstr(str);
	free(str);
}

static char		convert_digit(int digit, int caps)
{
	if (digit < 10)
		return (digit + '0');
	else
	{
		if (caps)
			return (digit - 10 + 'A');
		else
			return (digit - 10 + 'a');
	}
}

char			*ft_hextoa(uintmax_t hex, int prefix, int caps)
{
	char		*str;
	int			len;

	len = ft_hexlen(hex, prefix);
	str = malloc(sizeof(char) * (len + 1 + (prefix ? 2 : 0)));
	str[len] = '\0';
	if (prefix)
	{
		str[0] = '0';
		if (caps)
			str[1] = 'X';
		else
			str[1] = 'x';
	}
	str += len - 1;
	while (hex >= 16)
	{
		*str = convert_digit(hex % 16, caps);
		hex /= 16;
		str--;
	}
	*str = convert_digit(hex % 16, caps);
	return (str - (prefix ? 2 : 0));
}
