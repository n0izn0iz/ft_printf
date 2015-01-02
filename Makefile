NAME = libftprintf.a
LIBFT = objs/libft.a
SRCS = $(wildcard srcs/*.c)
OBJS = $(patsubst srcs/%.c, objs/%.o, $(SRCS))
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

objs/%.o: srcs/%.c
	gcc -c $< -o $@ $(FLAGS) -Iincludes -I../libft

$(LIBFT):
	make -C ../libft re
	cp ../libft/libft.a objs

clean:
	rm -f objs/*

fclean: clean
	rm -f $(NAME)

test: all
	make -C test

re: fclean all

.PHONY: clean fclean re all test
