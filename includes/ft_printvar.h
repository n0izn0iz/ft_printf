/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvar.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 14:32:15 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/02 14:39:13 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTVAR_H
# define FT_PRINTVAR_H

# include <stdarg.h>
# include "ft_printf.h"

void		print_uint(va_list *valist, t_spec_flags *opts);
void		print_int(va_list *valist, t_spec_flags *opts);
void		print_hex(va_list *valist, t_spec_flags *opts, char c);
void		print_str(va_list *valist, t_spec_flags *opts);
void		print_char(va_list *valist, t_spec_flags *opts);
void		print_octal(va_list *valist, t_spec_flags *opts);

#endif
