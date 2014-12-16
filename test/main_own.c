#include <locale.h>

int		main(void)
{
	setlocale(LC_CTYPE, "");
	own_printf();
	return (0);
}