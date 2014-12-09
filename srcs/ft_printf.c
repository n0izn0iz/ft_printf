#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>


void	ft_putoctal(int octal)
{
	if (octal > 8)
	{
		ft_putoctal(octal / 8);
		ft_putchar((octal % 8) + '0');
	}
	else
		ft_putchar(octal + '0');
}

int 	split_args(const char *str, va_list *valist, t_printf_args *args)
{
	int 	strstart;
	int index;
	int i;

	i = 0;
	index = 0;
	strstart = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			args->strings[index] = ft_strsub(str, strstart, i - strstart);
			if (str[++i] == 'd')
			{
				args->types[index] = T_INT;
				args->vars[index].i = va_arg(*valist, int);
			}
			else if (str[i] == 'u')
			{
				args->types[index] = T_UINT;
				args->vars[index].ui = va_arg(*valist, unsigned int);
			}
			else if (str[i] == 's')
			{
				args->types[index] = T_STR;
				args->vars[index].str = va_arg(*valist, char*);
			}
			else if (str[i] == 'o')
			{
				args->types[index] = T_OCT;
				args->vars[index].ui = va_arg(*valist, unsigned int);
			}
			strstart = i + 1;
			++index;
		}
		++i;
	}
	args->strings[index] = ft_strsub(str, strstart, i - strstart);
	return (index);
}

int		ft_printf(const char * format, ...)
{
	va_list			valist;
	t_printf_args	args;
	int 			j;

	args.strings = (char**)ft_memalloc(sizeof(char*) * (args.spec_count + 1 + 1));
	args.types = (t_typevar*)ft_memalloc(sizeof(t_typevar) * (args.spec_count + 1));
	args.vars = (t_typeunion*)ft_memalloc(sizeof(t_typeunion) * (args.spec_count + 1));
	va_start(valist, format);
	args.spec_count = split_args(format, &valist, &args);
	va_end(valist);
	j = 0;
	ft_putstr(args.strings[j]);
	while(j < args.spec_count)
	{
		if (args.types[j] == T_INT)
			ft_putnbr(args.vars[j].i);
		if (args.types[j] == T_UINT)
			ft_putnbr(args.vars[j].ui);
		if (args.types[j] == T_STR)
			ft_putstr(args.vars[j].str);
		if (args.types[j] == T_OCT)
			ft_putoctal(args.vars[j].ui);
		ft_putstr(args.strings[j + 1]);
		j++;
	}
	return (0);
}