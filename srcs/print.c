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
	char		*str;
	intmax_t	nbr;

	nbr = printf_intcast(valist, opts);
	str = ft_lltoa(nbr);
	if (!opts->minus)
		ft_putnchar(opts->width - ft_strlen(str) + (((opts->plus || opts->space)
			&& *str != '-') ? 1 : 0), opts->zero ? '0' : ' ');
	ft_putnchar(opts->precision - ft_strlen(str), '0');
	if (opts->plus && *str != '-')
		ft_putchar('+');
	else if (opts->space && *str != '-')
		ft_putchar(' ');
	if (!opts->precision_set || (ft_strcmp(str, "0") && opts->precision > 0))
		ft_putstr(str);
	if (opts->minus)
		ft_putnchar(opts->width - ft_strlen(str) + (((opts->plus || opts->space)
			&& *str != '-') ? 1 : 0), opts->zero ? '0' : ' ');
	free(str);
}

void					print_uint(va_list *valist, t_spec_flags *opts)
{
	char		*str;
	uintmax_t	nbr;

	nbr = printf_uintcast(valist, opts);
	str = ft_ulltoa(nbr);
	if (!opts->minus)
		ft_putnchar(opts->width - ft_strlen(str) +
			(opts->plus ? 1 : 0), opts->zero ? '0' : ' ');
	ft_putnchar(opts->precision - ft_strlen(str), '0');
	if (opts->plus)
		ft_putchar('+');
	else if (opts->space)
		ft_putchar(' ');
	if (!opts->precision_set || (ft_strcmp(str, "0") && opts->precision > 0))
		ft_putstr(str);
	if (opts->minus)
		ft_putnchar(opts->width - ft_strlen(str) +
			(opts->plus ? 1 : 0), opts->zero ? '0' : ' ');
	free(str);
}

void					print_hex(va_list *valist, t_spec_flags *opts, char c)
{
	uintmax_t	hex;
	char		*str;
	int			len;

	if (c == 'p')
		hex = va_arg(*valist, size_t);
	else
		hex = printf_uintcast(valist, opts);
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

	octal = printf_uintcast(valist, opts);
	if (!opts->minus)
		ft_putnchar(opts->width - ft_octlen(octal,
			(opts->sharp && octal != 0)), opts->zero ? '0' : ' ');
	ft_putnchar(opts->precision - ft_octlen(octal,
		(opts->sharp && octal != 0)), '0');
	if (!opts->precision_set || (octal != 0 && opts->precision > 0))
		ft_putoctal(octal, (opts->sharp && octal != 0));
	if (opts->minus)
		ft_putnchar(opts->width - ft_octlen(octal,
			(opts->sharp && octal != 0)), opts->zero ? '0' : ' ');
}
