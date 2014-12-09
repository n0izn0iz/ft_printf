#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "libft.h"

int			ll_len(long long int nbr)
{
	int result;

	result = 0LL;
	if (nbr < 0)
	{
		nbr = -nbr;
		result++;
	}
	while (nbr >= 10LL)
	{
		nbr /= 10LL;
		result++;
	}
	return (result + 1);
}

char		*ft_lltoa(long long int nbr)
{
	char *result;
	char *str;
	int len;

	if (nbr < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	len = ll_len(nbr);
	str = (char*)malloc(sizeof(char) * (len + 1));
	result = str;
	str[len] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		*str = '-';
	}
	str += len - 1;
	while (nbr >= 10LL)
	{
		*str = (nbr % 10LL) + '0';
		nbr /= 10LL;
		str--;
	}
	*str = (nbr % 10LL) + '0';
	return (result);
}