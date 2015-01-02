/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varlen.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 14:33:50 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/02 14:34:06 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VARLEN_H
# define FT_VARLEN_H

# include <wchar.h>

int		ft_ull_len(uintmax_t nbr);
int		ft_ll_len(long long int nbr);
int		ft_hexlen(uintmax_t hex, int prefix);
int		ft_octlen(uintmax_t octal, int prefix);
int		ft_wstrlen(wint_t *wstr);

#endif
