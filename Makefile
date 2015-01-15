NAME = libftprintf.a
SRCS = ./srcs/casts.c \
./srcs/ft_atoi.c \
./srcs/ft_hexlen.c \
./srcs/ft_lltoa.c \
./srcs/ft_octulltoa.c \
./srcs/ft_printf.c \
./srcs/ft_puthex.c \
./srcs/ft_putoctal.c \
./srcs/ft_putstr.c \
./srcs/ft_putwchar.c \
./srcs/ft_putwstr.c \
./srcs/ft_strsub.c \
./srcs/ft_ulltoa.c \
./srcs/ft_wcrtomb.c \
./srcs/misc.c \
./srcs/print.c \
./srcs/printchars.c \
./srcs/split_args.c
OBJS = $(patsubst ./srcs/%.c, objs/%.o, $(SRCS))
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

objs/%.o: srcs/%.c
	gcc -c $< -o $@ $(FLAGS) -Iincludes

clean:
	rm -f objs/*

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all

