#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>

typedef				enum e_typevar
{
	T_NULL = 0,
	T_INT,
	T_UINT,
	T_STR,
	T_OCT,
	T_VOID,
	T_HEX,
	T_CHAR,
	T_PERCENT
}					t_typevar;

typedef				enum e_len_mod
{
	LM_NULL = 0,
	LM_HH,
	LM_H,
	LM_L,
	LM_LL,
	LM_J,
	LM_Z
} t_len_mod;

typedef				struct s_spec_flags
{
	int 	sharp;
	int 	minus;
	int 	plus;
	int 	space;
	int 	zero;
	int 	caps;
	t_len_mod 	len_mod;
} t_spec_flags;

typedef				union u_typeunion
{
	char 	c;
	int 	i;
	unsigned int ui;
	char 	*str;
	void	*vp;
}					t_typeunion;

typedef 			struct s_printf_var
{
	t_typevar	type;
	t_typeunion	var;
	t_spec_flags flags;
} t_printf_var;

typedef				struct s_printf_args
{
	int 		spec_count;
	char		**strings;
	t_printf_var *data;
}					t_printf_args;

int					ft_printf(const char * format, ...);
void				ft_puthex(size_t hex, int prefix, int caps);
void				ft_putoctal(int octal, int prefix);
int 				split_args(const char *str, va_list *valist, t_printf_args *args);

#endif