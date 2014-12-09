NAME = test_printf
LIBFT = objs/libft.a
SRCS = $(wildcard srcs/*.c)
OBJS = $(patsubst srcs/%.c, objs/%.o, $(SRCS))
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

objs/%.o : srcs/%.c
	gcc -c $< -o $@ $(FLAGS) -I includes -I ../libft/includes

$(NAME) : $(OBJS) $(LIBFT)
	gcc -o $(NAME) $^

$(LIBFT) :
	make -C ../libft re
	cp ../libft/bins/libft.a objs

clean :
	rm -f objs/*

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean