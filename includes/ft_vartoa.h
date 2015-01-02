/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartoa.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 14:34:16 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/02 14:34:37 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VARTOA_H
# define FT_VARTOA_H

char				*ft_ulltoa(unsigned long long int nbr);
char				*ft_lltoa(long long int nbr);
char				*ft_hextoa(uintmax_t hex, int prefix, int caps);
char				*ft_octulltoa(unsigned long long octal, int prefix);

#endif
