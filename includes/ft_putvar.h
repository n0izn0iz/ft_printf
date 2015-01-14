/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvar.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 14:33:20 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/14 13:09:38 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTVAR_H
# define FT_PUTVAR_H

void	ft_puthex(unsigned long long hex, int caps);
void	ft_putoctal(uintmax_t octal);
void	ft_putnstr(char *str, int n);
void	ft_putnwchar(wchar_t *wchar, int n);
void	ft_putwchar(wint_t wchar);
void	ft_putwstr(wint_t *str);

#endif
