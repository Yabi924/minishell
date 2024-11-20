CFLAGS = -Wall -Wextra -Werror

NAME = minishell

SRCS = main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	gcc $(CFLAGS) -o $< -c $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)