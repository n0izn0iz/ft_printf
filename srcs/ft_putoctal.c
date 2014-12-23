/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:21:14 by nmeier            #+#    #+#             */
/*   Updated: 2014/12/23 14:22:21 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_printf.h"
#include "libft.h"

void	ft_putoctal(uintmax_t octal, int prefix)
{
	char *tmp;

	tmp = ft_octulltoa(octal, prefix);
	ft_putstr(tmp);
	free(tmp);
}
