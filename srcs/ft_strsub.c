/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:54:08 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/15 11:18:06 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	result = malloc(len + 1);
	if (result != NULL)
	{
		i = 0;
		while (i < len)
		{
			result[i] = s[start + i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
