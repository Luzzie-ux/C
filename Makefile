NAME = struct.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
OBJS = $(SRCS: .c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
