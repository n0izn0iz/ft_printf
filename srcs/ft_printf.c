/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:21:05 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/02 15:08:06 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf_impl.h"

<<<<<<< HEAD
static void	split_args(const char *str, va_list *valist)
=======
static int	split_args(const char *str, va_list *valist, t_printf_args *args)
{
	int				strstart;
	int				index;
	int				i;
	t_printf_var	*spec;
	char			c;

	i = 0;
	index = 0;
	strstart = 0;
	while ((c = str[i]) != '\0')
	{
		if (c == '%')
		{
			spec = args->data + index;
			args->strings[index] = ft_strsub(str, strstart, i - strstart);
			ft_putstr(args->strings[index]);
			i = fill_arg(i, valist, str, spec);
			strstart = i + 1;
			++index;
		}
		++i;
	}
	args->strings[index] = ft_strsub(str, strstart, i - strstart);
	ft_putstr(args->strings[index]);
	return (index);
}

int		count_specifiers(const char *str)
>>>>>>> d3686981f0450660f05684c16fc6741578e4cfaf
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
			free(tmp);
			i = fill_arg(i, valist, str);
			strstart = i + 1;
		}
		++i;
	}
	tmp = ft_strsub(str, strstart, i - strstart);
	ft_putstr(tmp);
	free(tmp);
}

int			ft_printf(const char *format, ...)
{
	va_list			valist;

	va_start(valist, format);
	split_args(format, &valist);
	va_end(valist);
	return (0);
}
