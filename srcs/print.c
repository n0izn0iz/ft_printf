/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:21:33 by nmeier            #+#    #+#             */
/*   Updated: 2014/12/23 14:21:56 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static inline void		ft_putnchar(int nbr, char c)
{
	while (nbr > 0)
	{
		ft_putchar(c);
		nbr--;
	}
}

void					print_int(va_list *valist, t_spec_flags *opts)
{
	char *str;

	if (opts->len_mod == LM_HH)
		str = ft_lltoa((char)va_arg(*valist, int));
	else if (opts->len_mod == LM_H)
		str = ft_lltoa((short)va_arg(*valist, int));
	else if (opts->len_mod == LM_L)
		str = ft_lltoa(va_arg(*valist, long));
	else if (opts->len_mod == LM_LL)
		str = ft_lltoa(va_arg(*valist, long long));
	else if (opts->len_mod == LM_J)
		str = ft_lltoa(va_arg(*valist, intmax_t));
	else if (opts->len_mod == LM_Z)
		str = ft_lltoa(va_arg(*valist, size_t));
	else
		str = ft_lltoa(va_arg(*valist, int));
	if (!opts->minus)
		ft_putnchar(opts->width - ft_strlen(str) + (((opts->plus || opts->space) && *str != '-') ? 1 : 0), opts->zero ? '0' : ' ');
	ft_putnchar(opts->precision - ft_strlen(str), '0');
	if (opts->plus && *str != '-')
		ft_putchar('+');
	else if (opts->space && *str != '-')
		ft_putchar(' ');
	if (!opts->precision_set || (ft_strcmp(str, "0") && opts->precision > 0))
		ft_putstr(str);
	if (opts->minus)
		ft_putnchar(opts->width - ft_strlen(str) + (((opts->plus || opts->space) && *str != '-') ? 1 : 0), opts->zero ? '0' : ' ');
	free(str);
}

void					print_uint(va_list *valist, t_spec_flags *opts)
{
	char *str;

	if (opts->len_mod == LM_HH)
		str = ft_ulltoa((unsigned char)va_arg(*valist, unsigned int));
	else if (opts->len_mod == LM_H)
		str = ft_ulltoa((unsigned short)va_arg(*valist, unsigned int));
	else if (opts->len_mod == LM_L)
		str = ft_ulltoa(va_arg(*valist, unsigned long));
	else if (opts->len_mod == LM_LL)
		str = ft_ulltoa(va_arg(*valist, unsigned long long));
	else if (opts->len_mod == LM_J)
		str = ft_ulltoa(va_arg(*valist, uintmax_t));
	else if (opts->len_mod == LM_Z)
		str = ft_ulltoa(va_arg(*valist, size_t));
	else
		str = ft_ulltoa(va_arg(*valist, unsigned int));
	if (!opts->minus)
		ft_putnchar(opts->width - ft_strlen(str) + (opts->plus ? 1 : 0), opts->zero ? '0' : ' ');
	ft_putnchar(opts->precision - ft_strlen(str), '0');
	if (opts->plus)
		ft_putchar('+');
	else if (opts->space)
		ft_putchar(' ');
	if (!opts->precision_set || (ft_strcmp(str, "0") && opts->precision > 0))
		ft_putstr(str);
	if (opts->minus)
		ft_putnchar(opts->width - ft_strlen(str) + (opts->plus ? 1 : 0), opts->zero ? '0' : ' ');
	free(str);
}

void					print_hex(va_list *valist, t_spec_flags *opts, char c)
{
	uintmax_t	hex;
	char		*str;
	int			len;

	if (opts->len_mod == LM_HH)
		hex = (unsigned char)va_arg(*valist, unsigned int);
	else if (opts->len_mod == LM_H)
		hex = (unsigned short)va_arg(*valist, unsigned int);
	else if (opts->len_mod == LM_L)
		hex = va_arg(*valist, unsigned long);
	else if (opts->len_mod == LM_LL)
		hex = va_arg(*valist, unsigned long long);
	else if (opts->len_mod == LM_J)
		hex = va_arg(*valist, uintmax_t);
	else if (opts->len_mod == LM_Z || c == 'p')
		hex = va_arg(*valist, size_t);
	else
		hex = va_arg(*valist, unsigned int);
	str = ft_hextoa(hex, c == 'p' || (opts->sharp && hex != 0), c == 'X');
	len = ft_strlen(str);
	ft_putnchar(opts->precision - len, '0');
	if (!opts->minus)
		ft_putnchar(opts->width - len, opts->zero ? '0' : ' ');
	if (!opts->precision_set || (hex != 0 && opts->precision > 0))
		ft_putstr(str);
	if (opts->minus)
		ft_putnchar(opts->width - len, opts->zero ? '0' : ' ');
}

void					print_octal(va_list *valist, t_spec_flags *opts)
{
	uintmax_t octal;

	if (opts->len_mod == LM_HH)
		octal = (unsigned char)va_arg(*valist, unsigned int);
	else if (opts->len_mod == LM_H)
		octal = (unsigned short)va_arg(*valist, unsigned int);
	else if (opts->len_mod == LM_L)
		octal = va_arg(*valist, unsigned long);
	else if (opts->len_mod == LM_LL)
		octal = va_arg(*valist, unsigned long long);
	else if (opts->len_mod == LM_J)
		octal = va_arg(*valist, uintmax_t);
	else if (opts->len_mod == LM_Z)
		octal = va_arg(*valist, size_t);
	else
		octal = va_arg(*valist, unsigned int);
	if (!opts->minus)
		ft_putnchar(opts->width - ft_octlen(octal, (opts->sharp && octal != 0)), opts->zero ? '0' : ' ');
	ft_putnchar(opts->precision - ft_octlen(octal, (opts->sharp && octal != 0)), '0');
	if (!opts->precision_set || (octal != 0 && opts->precision > 0))
		ft_putoctal(octal, (opts->sharp && octal != 0));
	if (opts->minus)
		ft_putnchar(opts->width - ft_octlen(octal, (opts->sharp && octal != 0)), opts->zero ? '0' : ' ');
}
