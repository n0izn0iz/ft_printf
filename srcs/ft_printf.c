#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int 	count_specifiers(const char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			count++;
			if (*(str + 1) != '\0')
				str++;
		}
		str++;
	}
	return (count);
}

static void		print(t_printf_args *args)
{
	int j;
	j = 0;
	ft_putstr(args->strings[j]);
	while(j < args->spec_count)
	{
		if (args->data[j].type == T_INT)
		{
			if (args->data[j].flags.len_mod == LM_HH)
				args->data[j].var.i = (char)args->data[j].var.i;
			ft_putnbr(args->data[j].var.i);
		}
		else if (args->data[j].type == T_UINT)
			ft_putnbr(args->data[j].var.ui);
		else if (args->data[j].type == T_STR)
			ft_putstr(args->data[j].var.str);
		else if (args->data[j].type == T_OCT)
			ft_putoctal(args->data[j].var.ui, args->data[j].flags.sharp);
		else if (args->data[j].type == T_VOID)
			ft_puthex((size_t)(args->data[j].var.vp), 1, 0);
		else if (args->data[j].type == T_HEX)
			ft_puthex(args->data[j].var.ui, args->data[j].flags.sharp, args->data[j].flags.caps);
		else if (args->data[j].type == T_CHAR)
			ft_putchar(args->data[j].var.c);
		else if (args->data[j].type == T_PERCENT)
			ft_putchar('%');
		ft_putstr(args->strings[j + 1]);
		j++;
	}
}

int		ft_printf(const char * format, ...)
{
	va_list			valist;
	t_printf_args	args;

	args.spec_count = count_specifiers(format);
	args.strings = (char**)ft_memalloc(sizeof(char*) * (args.spec_count + 1 + 1));
	args.data = (t_printf_var*)ft_memalloc(sizeof(t_printf_var) * (args.spec_count + 1));
	va_start(valist, format);
	split_args(format, &valist, &args);
	va_end(valist);
	print(&args);
	return (0);
}