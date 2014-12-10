NAME = test_printf
LIBFT = objs/libft.a
SRCS = $(wildcard srcs/*.c)
OBJS = $(patsubst srcs/%.c, objs/%.o, $(SRCS))
FLAGS = -Wall -Wextra -Werror

all: $(OBJS)

objs/%.o: srcs/%.c
	gcc -c $< -o $@ $(FLAGS) -I includes -I ../libft

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
