SRCS = $(wildcard tests/*.c)
PRINTF_OBJS = $(wildcard ../objs/*.o)
LIBFT = ../../libft/bins/libft.a
OBJS = $(patsubst tests/%.c, objs/%.o, $(SRCS))
TEST_BINS = $(patsubst objs/%.o, bins/%, $(OBJS))
CFLAGS = -Wall -Wextra -Werror

all: test

$(PRINTF_OBJS):
	make re -C ..

$(LIBFT):
	make re -C ../../libft

objs/%.o: tests/%.c
	gcc -c $^ -o $@ $(CFLAGS) -I ../includes

bins/%: objs/%.o $(PRINTF_OBJS) $(LIBFT)
	gcc -o $@ $^

test: $(TEST_BINS)
	./run_tests.sh

clean:
	rm -f objs/*

fclean: clean
	rm -f bins/*

re: fclean all

.PHONY: clean fclean all test re