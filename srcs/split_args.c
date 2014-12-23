#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"
#include <wchar.h>

int 	fill_width(const char *str, t_spec_flags *flags)
{
	int i;
	char *tmp;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	tmp = ft_strsub(str, 0, i);
	flags->width = ft_atoi(tmp);
	free(tmp);
	return (i);
}

int 	fill_flags(const char *str, t_spec_flags *flags)
{
	int i;

	
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			flags->sharp = 1;
		else if (str[i] == '+')
			flags->plus = 1;
		else if (str[i] == '-')
			flags->minus = 1;
		else if (str[i] == ' ')
			flags->space = 1;
		else if (str[i] == '0')
			flags->zero = 1;
		else
			break ;
		i++;
	}
	return i;
}

int 	fill_lenght(const char *str, t_spec_flags *flags)
{
	if (str[0] == 'h')
	{
		if (str[1] == 'h')
		{
			flags->len_mod = LM_HH;
			return (2);
		}
		flags->len_mod = LM_H;
		return (1);
		
	}
	else if (str[0] == 'l')
	{
		if (str[1] == 'l')
		{
			flags->len_mod = LM_LL;
			return (2);
		}
		flags->len_mod = LM_L;
		return (1);
	}
	else if (str[0] == 'j')
	{
		flags->len_mod = LM_J;
		return (1);
	}
	else if (str[0] == 'z')
	{
		flags->len_mod = LM_Z;
		return (1);
	}
	return (0);
}

int 	fill_precision(const char *str, t_spec_flags *flags)
{
	int i;
	char *tmp;

	i = 0;
	if (str[i++] != '.')
		return (0);
	flags->precision_set = 1;
	while (ft_isdigit(str[i]))
		i++;
	flags->precision = ft_atoi((tmp = ft_strsub(str, 1, i)));
	free(tmp);
	return (i);
}

int 	split_args(const char *str, va_list *valist, t_printf_args *args)
{
	int 	strstart;
	int 	index;
	int 	i;
	t_printf_var	*spec;
	char 	c;

	i = 0;
	index = 0;
	strstart = 0;
	while ((c = str[i]) != '\0')
	{
		if (c == '%')
		{	
			spec = args->data + index;
			args->strings[index] = ft_strsub(str, strstart, i - strstart);
			ft_putstr(args->strings[index]);
			ft_bzero(&(spec->flags), sizeof(t_spec_flags));
			i += fill_flags(str + i + 1, &(spec->flags)) + 1;
			i += fill_width(str + i, &(spec->flags));
			i += fill_precision(str + i, &(spec->flags));
			i += fill_lenght(str + i, &(spec->flags));
			c = str[i];
			if (c == 'S' || c == 'C' || c == 'D' || c == 'U' || c == 'O')
				spec->flags.len_mod = LM_L;
			if (c == 'd' || c == 'i' || c == 'D')
				print_int(valist, &(spec->flags));
			else if (c == 'u' || c == 'U')
				print_uint(valist, &(spec->flags));
			else if (c == 's' || c == 'S')
				print_str(valist, &(spec->flags));
			else if (c == 'c' || c == 'C')
				print_char(valist, &(spec->flags));
			else if (c == 'p' || c == 'x' || c == 'X')
				print_hex(valist, &(spec->flags), c);
			else if (c == 'o' || c == 'O')
				print_octal(valist, &(spec->flags));
			else if (c == '%')
				ft_putchar(c);
			strstart = i + 1;
			++index;
		}
		++i;
	}
	args->strings[index] = ft_strsub(str, strstart, i - strstart);
	ft_putstr(args->strings[index]);
	return (index);
}