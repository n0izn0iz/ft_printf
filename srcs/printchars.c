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

void					print_str(va_list *valist, t_spec_flags *opts)
{
	int		len;
	char	*str;
	wchar_t	*wstr;

	if (opts->len_mod == LM_L)
	{
		wstr = va_arg(*valist, wchar_t*);
		len = ft_wstrlen(wstr);
	}
	else
	{
		str = va_arg(*valist, char*);
		len = ft_strlen(str);
	}
	if (!opts->minus)
		ft_putnchar(opts->width - len, opts->zero ? '0' : ' ');
	if (opts->len_mod == LM_L)
		ft_putnwchar(wstr, opts->precision_set ? opts->precision : len);
	else
		ft_putnstr(str, opts->precision_set ? opts->precision : len);
	if (opts->minus)
		ft_putnchar(opts->width - len, opts->zero ? '0' : ' ');
}

void					print_char(va_list *valist, t_spec_flags *opts)
{
	char	mb[MB_CUR_MAX];
	int		len;

	len = 1;
	if (opts->len_mod == LM_L)
		len = ft_wcrtomb(mb, va_arg(*valist, wint_t));
	if (!opts->minus)
		ft_putnchar(opts->width - len, opts->zero ? '0' : ' ');
	if (opts->len_mod == LM_L)
		write(1, mb, len);
	else
		ft_putchar(va_arg(*valist, int));
	if (opts->minus)
		ft_putnchar(opts->width - len, opts->zero ? '0' : ' ');
}
