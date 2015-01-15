/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:21:05 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/15 11:14:39 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf_impl.h"
#include "misc.h"

static void	split_args(const char *str, va_list *valist)
{
	int				strstart;
	int				i;
	char			*tmp;

	i = 0;
	strstart = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			tmp = ft_strsub(str, strstart, i - strstart);
			ft_putstr(tmp);
			i = fill_arg(i, valist, str);
			strstart = i + 1;
		}
		++i;
	}
	tmp = ft_strsub(str, strstart, i - strstart);
	ft_putstr(tmp);
}

int			ft_printf(const char *format, ...)
{
	va_list			valist;

	va_start(valist, format);
	split_args(format, &valist);
	va_end(valist);
	return (0);
}
