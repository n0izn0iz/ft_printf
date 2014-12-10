#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

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

	flags->precision = 1;
	i = 0;
	if (str[i++] != '.')
		return (0);
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

	i = 0;
	index = 0;
	strstart = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{	
			spec = args->data + index;
			args->strings[index] = ft_strsub(str, strstart, i - strstart);
			ft_bzero(&(spec->flags), sizeof(t_spec_flags));
			i += fill_flags(str + i + 1, &(spec->flags)) + 1;
			i += fill_width(str + i, &(spec->flags));
			i += fill_precision(str + i, &(spec->flags));
			i += fill_lenght(str + i, &(spec->flags));
			if (str[i] == 'd' || str[i] == 'i' || str[i] == 'D')
			{
				spec->type = T_INT;
				if (spec->flags.len_mod >= LM_L)
					spec->var.imax = va_arg(*valist, intmax_t);
				else
					spec->var.imax = va_arg(*valist, int);
			}
			else if (str[i] == 'u' || str[i] == 'U')
			{
				spec->type = T_UINT;
				if (spec->flags.len_mod >= LM_L)
					spec->var.uimax = va_arg(*valist, uintmax_t);
				else
					spec->var.uimax = va_arg(*valist, unsigned int);
			}
			else if (str[i] == 's' || str[i] == 'S')
			{
				spec->type = T_STR;
				spec->var.str = va_arg(*valist, char*);
			}
			else if (str[i] == 'o' || str[i] == 'O')
			{
				spec->type = T_OCT;
				spec->var.ui = va_arg(*valist, unsigned int);
			}
			else if (str[i] == 'p')
			{
				spec->type = T_VOID;
				spec->var.vp = va_arg(*valist, void*);
			}
			else if (str[i] == 'x' || str[i] == 'X')
			{
				if (str[i] == 'X')
					spec->flags.caps = 1;
				spec->type = T_HEX;
				spec->var.ui = va_arg(*valist, unsigned int);
			}
			else if (str[i] == 'c' || str[i] == 'C')
			{
				spec->type = T_CHAR;
				spec->var.uimax = va_arg(*valist, uintmax_t);
			}
			else if (str[i] == '%')
			{
				spec->type = T_PERCENT;
			}
			
			strstart = i + 1;
			++index;
		}
		++i;
	}
	args->strings[index] = ft_strsub(str, strstart, i - strstart);
	return (index);
}