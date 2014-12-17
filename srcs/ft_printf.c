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
	free(args.data);
	return (0);
}