#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
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

/*static intmax_t 	len_cast(intmax_t var, t_len_mod len_mod)
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

static uintmax_t 	ulen_cast(uintmax_t var, t_len_mod len_mod)
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

void 			ft_putnchar(int nbr, char c)
{
	while (nbr > 0)
	{
		ft_putchar(c);
		nbr--;
	}
}

int 			ft_octlen(uintmax_t oct, int prefix)
{
	int result;

	result = 1;
	if (prefix)
		result ++;
	while (oct >= 8)
	{
		result++;
		oct /= 8;
	}
	return (result);
}

/*static int 		get_len(t_typeunion *data, t_typevar type, t_spec_flags *flags)
{
	if (type == T_INT)
		return (ft_ll_len(data->imax));
	else if (type == T_UINT)
		return (ft_ull_len(data->uimax));
	else if (type == T_STR)
		return (ft_strlen(data->str));
	else if (type == T_CHAR)
		return (1);
	else if (type == T_PERCENT)
		return (1);
	else if (type == T_HEX || type == T_VOID)
		return (ft_hexlen(data->uimax, (type == T_VOID ? 1 : flags->sharp)));
	else if (type == T_OCT)
		return (ft_octlen(data->uimax, flags->sharp));
	return (0);
}*/

/*static void		print(t_printf_args *args)
{
	int j;
	j = 0;
	ft_putstr(args->strings[j]);
	free(args->strings[j]);
	while (j < args->spec_count)
	{
		t_printf_var *arg = args->data + j;
		int len = get_len(&(arg->var), arg->type, &(arg->flags));
		if (arg->flags.width > 0 && !arg->flags.minus)
		{
			if (arg->flags.zero)
				ft_putnchar(arg->flags.width - len, '0');
			else
				ft_putnchar(arg->flags.width - len, ' ');
		}
		if (arg->type == T_INT)
		{
			arg->var.imax = len_cast(arg->var.imax, arg->flags.len_mod);
			ft_putnchar(arg->flags.precision - ft_ll_len(arg->var.imax), '0');
			if (arg->var.imax != 0 || arg->flags.precision > 0)
			{
				if (arg->flags.plus && arg->var.imax >= 0)
					ft_putchar('+');
				else if (arg->flags.space &&  arg->var.imax >= 0)
					ft_putchar(' ');
				ft_putstr(ft_lltoa(arg->var.imax));
			}
		}
		else if (arg->type == T_UINT)
		{
			arg->var.uimax = ulen_cast(arg->var.uimax, arg->flags.len_mod);
			ft_putstr(ft_ulltoa(arg->var.uimax));
		}
		else if (arg->type == T_STR)
			ft_putstr(arg->var.str);
		else if (arg->type == T_OCT)
			ft_putoctal(arg->var.uimax, (arg->flags.sharp && arg->var.uimax > 0));
		else if (arg->type == T_VOID)
			ft_puthex((size_t)(arg->var.vp), 1, 0);
		else if (arg->type == T_HEX)
			ft_puthex(arg->var.uimax, (arg->flags.sharp && arg->var.uimax > 0), arg->flags.caps);
		else if (arg->type == T_CHAR)
		{
			if (arg->flags.len_mod == LM_L)
				ft_putwchar(arg->var.uimax);
			else
				ft_putchar(arg->var.uimax);
		}
		else if (arg->type == T_PERCENT)
			ft_putchar('%');
		if (arg->flags.width > 0 && arg->flags.minus)
		{
			if (arg->flags.zero)
				ft_putnchar(arg->flags.width - len, '0');
			else
				ft_putnchar(arg->flags.width - len, ' ');
		}
		j++;
		ft_putstr(args->strings[j]);
		free(args->strings[j]);
	}
}*/

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
	/*print(&args);*/
	free(args.data);
	return (0);
}