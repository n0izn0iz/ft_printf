/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:21:33 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/15 11:29:09 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include "ft_putvar.h"
#include "ft_varlen.h"
#include "ft_vartoa.h"
#include "ft_printf_impl.h"
#include "misc.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

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
	int			len;

	nbr = printf_intcast(valist, opts);
	str = ft_lltoa(nbr);
	len = MAX((int)ft_strlen(nbr < 0 ? str + 1 : str), \
			opts->precision) + (opts->space || opts->plus);
	if (!opts->minus)
		ft_putnchar(opts->width - len, opts->zero ? '0' : ' ');
	if (nbr < 0)
		ft_putchar('-');
	if (opts->plus && *str != '-')
		ft_putchar('+');
	else if (opts->space && *str != '-')
		ft_putchar(' ');
	ft_putnchar(opts->precision - ft_strlen(nbr < 0 ? str + 1 : str), '0');
	if (nbr != 0 || !opts->precision_set || opts->precision > 0)
		ft_putstr(nbr < 0 ? str + 1 : str);
	if (opts->minus)
		ft_putnchar(opts->width - len, ' ');
	free(str);
}

void					print_uint(va_list *valist, t_spec_flags *opts)
{
	char		*str;
	uintmax_t	nbr;
	int			len;

	nbr = printf_uintcast(valist, opts);
	str = ft_ulltoa(nbr);
	len = MAX((int)ft_strlen(str), opts->precision);
	if (!opts->minus)
		ft_putnchar(opts->width - len, opts->zero ? '0' : ' ');
	ft_putnchar(opts->precision - ft_strlen(str), '0');
	if (nbr != 0 || !opts->precision_set || opts->precision > 0)
		ft_putstr(str);
	if (opts->minus)
		ft_putnchar(opts->width - len, ' ');
	free(str);
}

void					print_hex(va_list *valist, t_spec_flags *opts, char c)
{
	uintmax_t	hex;
	char		*str;
	int			len;
	int			prefix;

	prefix = (c == 'p' || opts->sharp);
	if (c == 'p')
		hex = va_arg(*valist, size_t);
	else
		hex = printf_uintcast(valist, opts);
	str = ft_hextoa(hex, c == 'X');
	len = MAX(opts->precision, (int)ft_strlen(str));
	if (!opts->minus)
		ft_putnchar(opts->width - len - (prefix ? 2 : 0), \
				opts->zero ? '0' : ' ');
	if (prefix && (hex != 0 || c == 'p'))
		ft_putstr(c == 'X' ? "0X" : "0x");
	ft_putnchar(opts->precision - ft_strlen(str), '0');
	if (!opts->precision_set || (hex != 0 && opts->precision > 0))
		ft_putstr(str);
	if (opts->minus)
		ft_putnchar(opts->width - len - (prefix ? 2 : 0), ' ');
}

void					print_octal(va_list *valist, t_spec_flags *opts)
{
	uintmax_t	octal;
	int			octlen;

	octal = printf_uintcast(valist, opts);
	octlen = MAX((int)opts->precision, ft_octlen(octal) + opts->sharp);
	if (!opts->minus)
		ft_putnchar(opts->width - octlen, opts->zero ? '0' : ' ');
	ft_putnchar(opts->precision - ft_octlen(octal) - opts->sharp, '0');
	if (opts->sharp && octal != 0)
		ft_putchar('0');
	if (!opts->precision_set || octal != 0)
		ft_putoctal(octal);
	if (opts->minus)
		ft_putnchar(opts->width - octlen, ' ');
}
