#include <stdio.h>
#include "ft_printf.h"

int				main()
{
	printf("Test0\nstd:\n");
	printf("yowyowyow");
	printf("\nft:\n");
	ft_printf("yowyowyow");
	printf("\n");
	printf("Test1\nstd:\n");
	printf("un ptit int : %d", 42);
	printf("\nft:\n");
	ft_printf("un ptit int : %d", 42);
	printf("\n");
	printf("Test2\nstd:\n");
	printf("%d pl%d%dn de pt%dts %dn%ds : %d", 1337, 1, 3, 1, 1, 7, 42);
	printf("\nft:\n");
	ft_printf("%d pl%d%dn de pt%dts %dn%ds : %d", 1337, 1, 3, 1, 1, 7, 42);
	printf("\n");
	printf("Test3\nstd:\n");
	printf("%s", "une chaine de char");
	printf("\nft:\n");
	ft_printf("%s", "une chaine de char");
	printf("\n");
	printf("Test4\nstd:\n");
	printf("%sl%sd%sde %s", "p", "ein ", "e chaines ", "char");
	printf("\nft:\n");
	ft_printf("%sl%sd%sde %s", "p", "ein ", "e chaines ", "char");
	printf("\n");
	printf("Test1\nstd:\n");
	printf("un octal : %o", 0640);
	printf("\nft:\n");
	ft_printf("un octal : %o", 0640);
	printf("\n");
	printf("%o pl%o%on de pt%ots oct%ol : %o", -1337, 1, 3, 1, 4, 42);
	printf("\nft:\n");
	ft_printf("%o pl%o%on de pt%ots oct%ol : %o", -1337, 1, 3, 1, 4, 42);
	printf("\n");
	return (0);
}