/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:21:09 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/15 11:28:23 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "misc.h"
#include "ft_vartoa.h"
#include "ft_varlen.h"

void			ft_puthex(uintmax_t hex, int caps)
{
	char		*str;

	str = ft_hextoa(hex, caps);
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

char			*ft_hextoa(uintmax_t hex, int caps)
{
	char		*str;
	int			len;

	len = ft_hexlen(hex);
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	str += len - 1;
	while (hex >= 16)
	{
		*str = convert_digit(hex % 16, caps);
		hex /= 16;
		str--;
	}
	*str = convert_digit(hex % 16, caps);
	return (str);
}
