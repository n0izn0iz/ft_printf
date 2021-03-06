/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:20:33 by nmeier            #+#    #+#             */
/*   Updated: 2014/12/23 14:24:16 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

int		ft_hexlen(uintmax_t hex, int prefix)
{
	int result;

	result = 1;
	if (prefix)
		result += 2;
	while (hex >= 16)
	{
		result++;
		hex /= 16;
	}
	return (result);
}
