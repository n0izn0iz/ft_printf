SRCS = $(wildcard tests/*.c)
PRINTF = ../libftprintf.a
LIBFT = ../../libft/libft.a
OBJS = $(patsubst tests/%.c, objs/%.o, $(SRCS))
STD_TEST_BINS = $(patsubst objs/%.o, bins/std_%, $(OBJS))
OWN_TEST_BINS = $(patsubst objs/%.o, bins/own_%, $(OBJS))
CFLAGS = #-Wall -Wextra -Werror

all: test

$(PRINTF):
	make re -C ..

$(LIBFT):
	make re -C ../../libft

objs/%.o: tests/%.c
	gcc -c $^ -o $@ $(CFLAGS) -I ../includes

%.o: %.c
	gcc -c $^ -o $@ $(CLFAGS) -I ../includes

bins/std_%: objs/%.o main_std.o $(PRINTF) $(LIBFT)
	gcc -o $@ $^

bins/own_%: objs/%.o main_own.o $(PRINTF) $(LIBFT)
	gcc -o $@ $^

test: $(STD_TEST_BINS) $(OWN_TEST_BINS)
	./run_tests.sh

clean:
	rm -f objs/*

fclean: clean
	rm -f bins/*

re: fclean all

.PHONY: clean fclean all test re
