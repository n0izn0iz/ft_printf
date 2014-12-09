#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int			ull_len(unsigned long long int nbr)
{
	int result;

	result = 0LL;
	while (nbr >= 10LL)
	{
		nbr /= 10LL;
		result++;
	}
	return (result + 1);
}

char		*ft_ulltoa(unsigned long long int nbr)
{
	char *result;
	char *str;
	int len;

	len = ull_len(nbr);
	str = (char*)malloc(sizeof(char) * (len + 1));
	result = str;
	str[len] = '\0';
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