/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:21:23 by nmeier            #+#    #+#             */
/*   Updated: 2014/12/23 14:22:24 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int			ft_ull_len(unsigned long long int nbr)
{
	int result;

	result = 1LL;
	while (nbr >= 10LL)
	{
		nbr /= 10LL;
		result++;
	}
	return (result);
}

char		*ft_ulltoa(unsigned long long int nbr)
{
	char	*result;
	char	*str;
	int		len;

	len = ft_ull_len(nbr);
	str = (char*)malloc(sizeof(char) * (len + 1));
	result = str;
	str[len] = '\0';
	str += len - 1;
	while (nbr >= 10LL)
	{
		*str = (nbr % 10LL) + '0';
		nbr /= 10LL;
		str--;
	}
	*str = (nbr % 10LL) + '0';
	return (result);
}
