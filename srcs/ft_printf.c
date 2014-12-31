/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:21:05 by nmeier            #+#    #+#             */
/*   Updated: 2014/12/31 12:42:20 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

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
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			count++;
			if (*(str + 1) != '\0')
				str++;
		}
		str++;
	}
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list			valist;
	t_printf_args	args;

	args.spec_count = count_specifiers(format);
	args.strings = (char**)ft_memalloc(sizeof(char*)
		* (args.spec_count + 1 + 1));
	args.data = (t_printf_var*)ft_memalloc(sizeof(t_printf_var)
		* (args.spec_count + 1));
	va_start(valist, format);
	split_args(format, &valist, &args);
	va_end(valist);
	free(args.data);
	return (0);
}
