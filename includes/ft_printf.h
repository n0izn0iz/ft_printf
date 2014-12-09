#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef				enum e_typevar
{
	T_NULL = 0,
	T_INT,
	T_UINT,
	T_STR,
	T_OCT
}					t_typevar;

typedef				union u_typeunion
{
	char 	c;
	int 	i;
	unsigned int ui;
	char 	*str;
}					t_typeunion;

typedef				struct s_printf_args
{
	int 		spec_count;
	char		**strings;
	t_typevar	*types;
	t_typeunion	*vars;
}					t_printf_args;

int					ft_printf(const char * format, ...);

#endif