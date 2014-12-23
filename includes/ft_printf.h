#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <wchar.h>

typedef enum 		e_typevar
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

typedef enum 		e_len_mod
{
	LM_NULL = 0,
	LM_HH,
	LM_H,
	LM_L,
	LM_LL,
	LM_J,
	LM_Z
} 					t_len_mod;

typedef struct 		s_spec_flags
{
	int 		sharp;
	int 		minus;
	int 		plus;
	int 		space;
	int 		zero;
	int 		caps;
	t_len_mod 	len_mod;
	int 		width;
	int 		precision;
	int 		precision_set;
} 					t_spec_flags;

typedef union 		u_typeunion
{
	char 		 	c;
	int 			i;
	unsigned int 	ui;
	intmax_t		imax;
	uintmax_t		uimax;
	char 			*str;
	void			*vp;
}					t_typeunion;

typedef struct 		s_printf_var
{
	t_typevar		type;
	t_typeunion		var;
	t_spec_flags 	flags;
} 					t_printf_var;

typedef struct 		s_printf_args
{
	int 			spec_count;
	char			**strings;
	t_printf_var 	*data;
}					t_printf_args;

int					ft_printf(const char * format, ...);
void				ft_puthex(size_t hex, int prefix, int caps);
void				ft_putoctal(uintmax_t octal, int prefix);
int 				split_args(const char *str, va_list *valist, t_printf_args *args);
char				*ft_ulltoa(unsigned long long int nbr);
char				*ft_lltoa(long long int nbr);
int					ft_ll_len(long long int nbr);
int					ft_ull_len(unsigned long long int nbr);
int					ft_hexlen(uintmax_t hex, int prefix);
char				*ft_hextoa(uintmax_t hex, int prefix, int caps);
int			ft_wstrlen (wint_t* wstr);
void		ft_putnstr(char *str, int n);
size_t		ft_wcrtomb(char *s, wchar_t wchar);
char	*ft_octulltoa(unsigned long long octal, int prefix);
uintmax_t		printf_uintcast(va_list *valist, t_spec_flags *opts);
intmax_t		printf_intcast(va_list *valist, t_spec_flags *opts);

void		ft_putnwchar(wchar_t *wchar, int n);

void	print_uint(va_list *valist, t_spec_flags *opts);
void	print_int(va_list *valist, t_spec_flags *opts);
void	print_hex(va_list *valist, t_spec_flags *opts, char c);
void	print_str(va_list *valist, t_spec_flags *opts);
void	print_char(va_list *va_list, t_spec_flags *opts);
void	print_octal(va_list *valist, t_spec_flags *opts);
void		ft_putwchar(wint_t wchar);
void		ft_putwstr(wint_t *str);
int		ft_octlen(uintmax_t octal, int prefix);

#endif