/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:21:14 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/15 11:28:33 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "misc.h"
#include "ft_printf_impl.h"
#include "ft_vartoa.h"

void	ft_putoctal(uintmax_t octal)
{
	char *tmp;

	tmp = ft_octulltoa(octal);
	ft_putstr(tmp);
	free(tmp);
}
