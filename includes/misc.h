/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 11:20:46 by nmeier            #+#    #+#             */
/*   Updated: 2015/01/15 11:21:10 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_H
# define MISC_H

# include <stdlib.h>

int		ft_strlen(const char *str);
char	*ft_strdup(char *str);
int		ft_isdigit(char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
void	ft_bzero(void *ptr, int size);
void	ft_putchar(char c);
void	ft_putstr(char const *s);

#endif
