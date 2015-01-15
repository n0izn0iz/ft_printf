/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 11:20:19 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/15 11:20:21 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int			ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strdup(char *str)
{
	char	*result;
	int		i;
	int		len;

	if (!str)
		return (str);
	len = ft_strlen(str) + 1;
	result = (char*)malloc(sizeof(char) * len);
	i = 0;
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}

int			ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

void		ft_bzero(void *ptr, int size)
{
	char *data;

	data = ptr;
	if (ptr != NULL)
	{
		while (--size >= 0)
			data[size] = 0;
	}
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}
