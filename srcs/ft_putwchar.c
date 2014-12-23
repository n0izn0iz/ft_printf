/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:21:18 by nmeier            #+#    #+#             */
/*   Updated: 2014/12/23 14:22:22 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <wchar.h>
#include <stdio.h>
#include <stdint.h>

#include "libft.h"
#include "ft_printf.h"

int			ft_wstrlen(wint_t *wstr)
{
	int		i;
	int		result;
	char	tmp[4];

	i = 0;
	while (wstr[i] != L'\0')
	{
		result += ft_wcrtomb(tmp, wstr[i]);
		i++;
	}
	return (result);
}

void		ft_putwchar(wint_t wchar)
{
	char	tmp[MB_CUR_MAX];
	int		i;

	i = ft_wcrtomb(tmp, wchar);
	write(1, tmp, i);
}

int			ft_min(int a, int b)
{
	return (a < b ? a : b);
}

void		ft_putnstr(char *str, int n)
{
	write(1, str, ft_min(ft_strlen(str), n));
}

void		ft_putnwchar(wchar_t *wchar, int n)
{
	int i;

	i = 0;
	while (wchar[i] && i < n)
	{
		ft_putwchar(wchar[i]);
		i++;
	}
}
