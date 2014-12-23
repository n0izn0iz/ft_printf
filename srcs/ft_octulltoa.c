/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octulltoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:20:59 by nmeier            #+#    #+#             */
/*   Updated: 2014/12/23 14:22:16 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

int			ft_octlen(uintmax_t oct, int prefix)
{
	int result;

	result = 1;
	if (prefix)
		result++;
	while (oct >= 8)
	{
		result++;
		oct /= 8;
	}
	return (result);
}

char		*ft_octulltoa(unsigned long long octal, int prefix)
{
	char	*str;
	char	*first;
	int		len;

	len = ft_octlen(octal, prefix);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		first = str;
		if (prefix)
			str[0] = '0';
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
