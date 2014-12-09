#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

int 	fill_flags(const char *str, t_spec_flags *flags)
{
	int i;

	ft_bzero(flags, sizeof(t_spec_flags));
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
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'h')
		{
			if (str[i + 1] == 'h')
			{
				i++;
				flags->len_mod = LM_HH;
			}
			else
				flags->len_mod = LM_H;
		}
		else if (str[i] == 'l')
		{
			if (str[i + 1] == 'l')
			{
				i++;
				flags->len_mod = LM_LL;
			}
			else
				flags->len_mod = LM_L;
		}
		else if (str[i] == 'j')
			flags->len_mod = LM_J;
		else if (str[i] == 'z')
			flags->len_mod = LM_Z;
		else
			break ;
		i++;
	}
	return i;
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
			i += fill_flags(str + i + 1, &(spec->flags)) + 1;
			i += fill_lenght(str + i, &(spec->flags));
			if (str[i] == 'd' || str[i] == 'i' || str[i] == 'D')
			{
				spec->type = T_INT;
				spec->var.i = va_arg(*valist, int);
			}
			else if (str[i] == 'u')
			{
				spec->type = T_UINT;
				spec->var.ui = va_arg(*valist, unsigned int);
			}
			else if (str[i] == 's')
			{
				spec->type = T_STR;
				spec->var.str = va_arg(*valist, char*);
			}
			else if (str[i] == 'o')
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
			else if (str[i] == 'c')
			{
				spec->type = T_CHAR;
				spec->var.c = va_arg(*valist, int);
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