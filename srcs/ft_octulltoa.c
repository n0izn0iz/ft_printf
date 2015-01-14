/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octulltoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:20:59 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/14 12:07:08 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

int			ft_octlen(uintmax_t oct)
{
	int result;

	result = 1;
	while (oct >= 8)
	{
		result++;
		oct /= 8;
	}
	return (result);
}

char		*ft_octulltoa(unsigned long long octal)
{
	char	*str;
	char	*first;
	int		len;

	len = ft_octlen(octal);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		first = str;
		str[len] = '\0';
		str += len - 1;
		while (octal >= 8)
		{
			*str = octal % 8 + '0';
			str--;
			octal /= 8;
		}
		*str = octal % 8 + '0';
	}
	return (first);
}
