NAME = codexion
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/codexion.c, srcs/memory.c, srcs/parser.c, srcs/strings.c
MAIN = main.c

OBJS = $(SRCS:.c=.o) $(MAIN: .c=.o)

all: $(NAME) clean
	./$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
