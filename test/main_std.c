#include <locale.h>

int		main(void)
{
	setlocale(LC_CTYPE, "");
	std_printf();
	return (0);
}