/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_impl.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 14:53:51 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/02 14:53:54 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_IMPL_H
# define FT_PRINTF_IMPL_H

# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>

typedef enum		e_len_mod
{
	LM_NULL = 0,
	LM_HH,
	LM_H,
	LM_L,
	LM_LL,
	LM_J,
	LM_Z
}					t_len_mod;

typedef struct		s_spec_flags
{
	int			sharp;
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			caps;
	t_len_mod	len_mod;
	int			width;
	int			precision;
	int			precision_set;
}					t_spec_flags;

int					fill_arg(int i, va_list *valist, const char *str);
size_t				ft_wcrtomb(char *s, wchar_t wchar);
uintmax_t			printf_uintcast(va_list *valist, t_spec_flags *opts);
intmax_t			printf_intcast(va_list *valist, t_spec_flags *opts);

#endif
