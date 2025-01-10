NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c operations.c sorting.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
