/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:21:41 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/15 11:12:28 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>
#include "ft_printf_impl.h"
#include "ft_printvar.h"
#include "misc.h"

int		fill_width(const char *str, t_spec_flags *flags)
{
	int		i;
	char	*tmp;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	tmp = ft_strsub(str, 0, i);
	flags->width = ft_atoi(tmp);
	free(tmp);
	return (i);
}

int		fill_flags(const char *str, t_spec_flags *flags)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '#')
			flags->sharp = 1;
		else if (str[i] == '+')
		{
			flags->space = 0;
			flags->plus = 1;
		}
		else if (str[i] == '-')
		{
			flags->zero = 0;
			flags->minus = 1;
		}
		else if (str[i] == ' ' && !flags->plus)
			flags->space = 1;
		else if (str[i] == '0' && !flags->minus)
			flags->zero = 1;
		else
			break ;
	}
	return (i);
}

int		fill_lenght(const char *str, t_spec_flags *flags)
{
	if (str[0] == 'h')
	{
		if (str[1] == 'h')
		{
			flags->len_mod = LM_HH;
			return (2);
		}
		flags->len_mod = LM_H;
	}
	else if (str[0] == 'l')
	{
		if (str[1] == 'l')
		{
			flags->len_mod = LM_LL;
			return (2);
		}
		flags->len_mod = LM_L;
	}
	else if (str[0] == 'j')
		flags->len_mod = LM_J;
	else if (str[0] == 'z')
		flags->len_mod = LM_Z;
	else
		return (0);
	return (1);
}

int		fill_precision(const char *str, t_spec_flags *flags)
{
	int		i;
	char	*tmp;

	i = 0;
	if (str[i++] != '.')
		return (0);
	flags->precision_set = 1;
	flags->zero = 0;
	while (ft_isdigit(str[i]))
		i++;
	tmp = ft_strsub(str, 1, i);
	flags->precision = ft_atoi(tmp);
	free(tmp);
	return (i);
}

int		fill_arg(int i, va_list *valist, const char *str)
{
	char			c;
	t_spec_flags	opts;

	ft_bzero(&opts, sizeof(t_spec_flags));
	i += fill_flags(str + i + 1, &opts) + 1;
	i += fill_width(str + i, &opts);
	i += fill_precision(str + i, &opts);
	i += fill_lenght(str + i, &opts);
	if ((c = str[i]) == 'S' || c == 'C' || c == 'D' || c == 'U' || c == 'O')
		opts.len_mod = LM_L;
	if (c == 'd' || c == 'i' || c == 'D')
		print_int(valist, &opts);
	else if (c == 'u' || c == 'U')
		print_uint(valist, &opts);
	else if (c == 's' || c == 'S')
		print_str(valist, &opts);
	else if (c == 'c' || c == 'C')
		print_char(valist, &opts);
	else if (c == 'p' || c == 'x' || c == 'X')
		print_hex(valist, &opts, c);
	else if (c == 'o' || c == 'O')
		print_octal(valist, &opts);
	else if (c == '%')
		ft_putchar(c);
	return (i);
}
