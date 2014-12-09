#include <stdarg.h>
#include <stdint.h>
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

static intmax_t 	len_cast(intmax_t var, t_len_mod len_mod)
{
	if (len_mod == LM_HH)
		return ((char)var);
	else if (len_mod == LM_H)
		return ((short)var);
	else if (len_mod == LM_L)
		return ((long)var);
	else if (len_mod == LM_LL)
		return ((long long)var);
	else if (len_mod == LM_Z)
		return ((size_t)var);
	return (var);
}

/*static uintmax_t 	ulen_cast(uintmax_t var, t_len_mod len_mod)
{
	if (len_mod == LM_HH)
		return ((unsigned char)var);
	else if (len_mod == LM_H)
		return ((unsigned short)var);
	else if (len_mod == LM_L)
		return ((unsigned long)var);
	else if (len_mod == LM_LL)
		return ((unsigned long long)var);
	else if (len_mod == LM_Z)
		return ((size_t)var);
	return (var);
}*/

static void		print(t_printf_args *args)
{
	int j;

	j = 0;
	ft_putstr(args->strings[j]);
	while(j < args->spec_count)
	{
		args->data[j].var.imax = len_cast(args->data[j].var.imax, args->data[j].flags.len_mod);
		if (args->data[j].type == T_INT)
			ft_putstr(ft_lltoa(args->data[j].var.imax));
		else if (args->data[j].type == T_UINT)
			ft_putstr(ft_ulltoa(args->data[j].var.uimax));
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