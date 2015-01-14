/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 15:07:47 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/14 12:58:11 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf_impl.h"
#include "ft_varlen.h"
#include "ft_putvar.h"
#include "libft.h"

static inline void		ft_putnchar(int nbr, char c)
{
	while (nbr > 0)
	{
		ft_putchar(c);
		nbr--;
	}
}

static char				*caststr(va_list *valist, int *len)
{
	char *str;

	str = va_arg(*valist, char*);
	if (!str)
	{
		ft_putstr("(null)");
		return (NULL);
	}
	*len = ft_strlen(str);
	return (str);
}

static wchar_t			*castwstr(va_list *valist, int *len)
{
	wchar_t		*wstr;

	wstr = va_arg(*valist, wchar_t*);
	if (!wstr)
	{
		ft_putstr("(null)");
		return (NULL);
	}
	*len = ft_wstrlen(wstr);
	return (wstr);
}

void					print_str(va_list *valist, t_spec_flags *opts)
{
	int		len;
	void	*str;

	str = NULL;
	if (opts->len_mod == LM_L)
		str = castwstr(valist, &len);
	else
		str = caststr(valist, &len);
	if (!str)
		return ;
	if (!opts->minus)
		ft_putnchar(opts->width - len, opts->zero ? '0' : ' ');
	if (opts->len_mod == LM_L)
		ft_putnwchar((wchar_t*)str, \
			opts->precision_set ? opts->precision : len);
	else
		ft_putnstr((char*)str, opts->precision_set ? opts->precision : len);
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
