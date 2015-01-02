/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 15:05:27 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/02 14:39:58 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdarg.h>

#include "ft_printf_impl.h"

intmax_t		printf_intcast(va_list *valist, t_spec_flags *opts)
{
	intmax_t result;

	if (opts->len_mod == LM_HH)
		result = (char)va_arg(*valist, int);
	else if (opts->len_mod == LM_H)
		result = (short)va_arg(*valist, int);
	else if (opts->len_mod == LM_L)
		result = va_arg(*valist, long);
	else if (opts->len_mod == LM_LL)
		result = va_arg(*valist, long long);
	else if (opts->len_mod == LM_J)
		result = va_arg(*valist, intmax_t);
	else if (opts->len_mod == LM_Z)
		result = va_arg(*valist, size_t);
	else
		result = va_arg(*valist, int);
	return (result);
}

uintmax_t		printf_uintcast(va_list *valist, t_spec_flags *opts)
{
	uintmax_t result;

	if (opts->len_mod == LM_HH)
		result = (unsigned char)va_arg(*valist, unsigned int);
	else if (opts->len_mod == LM_H)
		result = (unsigned short)va_arg(*valist, unsigned int);
	else if (opts->len_mod == LM_L)
		result = va_arg(*valist, unsigned long);
	else if (opts->len_mod == LM_LL)
		result = va_arg(*valist, unsigned long long);
	else if (opts->len_mod == LM_J)
		result = va_arg(*valist, uintmax_t);
	else if (opts->len_mod == LM_Z)
		result = va_arg(*valist, size_t);
	else
		result = va_arg(*valist, unsigned int);
	return (result);
}
