CFLAGS = -Wall -Wextra -Werror

#program name
NAME = minishell

#path
PATH_SRCS = ./srcs/

PATH_BUILTIN = $(PATH_SRCS)Builtin/
PATH_CTRL = $(PATH_SRCS)CTRL/
PATH_History = $(PATH_SRCS)History/
PATH_Pipe = $(PATH_SRCS)Pipe/
PATH_Quotes = $(PATH_SRCS)Quotes_handling/
PATH_Redirection = $(PATH_SRCS)Redirection/

#src
s_builtin = $(PATH_BUILTIN)

s_ctrl = $(PATH_CTRL)

s_his = $(PATH_History)

s_pipe = $(PATH_Pipe)

s_quotes = $(PATH_Quotes)

s_rdrt = $(PATH_Redirection)

main= ./srcs/main.c

SRCS = $(main) #$(s_builtin) $(s_ctrl) $(s_his) $(s_pipe) $(s_quotes) $(s_rdrt) 

#objs
OBJS = $(SRCS:.c=.o)

#lib
LIBS = ./libft/libft.a -L./libft -lft

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/ --no-print-directory
	@gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@echo Hi $(NAME)
	@make clean --no-print-directory
	@make clean -C libft/ --no-print-directory

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo clean *.obj

fclean: clean
	@make fclean -C libft/ --no-print-directory
	@rm -rf $(NAME)
	@echo clean $(NAME)