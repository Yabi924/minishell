#flags
CFLAGS = -Wall -Wextra -Werror

#program name
NAME = minishell

#src path
PATH_SRCS = ./srcs/
PATH_fn = $(PATH_SRCS)frontend/

#function path
PATH_BUILTINS = $(PATH_SRCS)builtins/
PATH_CTRL = $(PATH_SRCS)CTRL/
PATH_History = $(PATH_SRCS)History/
PATH_Pipe = $(PATH_SRCS)Pipe/
PATH_Quotes = $(PATH_SRCS)Quotes_handling/
PATH_signal = $(PATH_SRCS)signal/
PATH_Redirection = $(PATH_SRCS)Redirection/
PATH_env = $(PATH_fn)Env_Var/
PATH_token = $(PATH_fn)token/
PATH_utils = $(PATH_fn)utils/

#src
s_builtins = $(PATH_BUILTINS)

s_ctrl = $(PATH_CTRL)

s_his = $(PATH_History)

s_signal = $(PATH_signal)get_stat.c\
			$(PATH_signal)signal.c

s_pipe = $(PATH_Pipe)

s_quotes = $(PATH_Quotes)

s_rdrt = $(PATH_Redirection)

s_env = $(PATH_env)

s_token = $(PATH_token)tokenization.c \
		$(PATH_token)split.c

s_utils = $(PATH_utils)utils.c \
		$(PATH_utils)readline.c \
		$(PATH_utils)check.c \
		$(PATH_utils)check_pipe.c \
		$(PATH_utils)add_space.c

s_input_handle = $(PATH_fn)input_handle.c \
		$(PATH_fn)lexer.c \
		$(PATH_fn)parser.c

main= ./srcs/main.c

SRCS = $(main) $(s_utils) $(s_input_handle) $(s_token) $(s_signal) #$(s_builtins) $(s_ctrl) $(s_his) $(s_pipe) $(s_quotes) $(s_rdrt) $(s_env)

#objs
OBJS = $(SRCS:.c=.o)

#lib
LIBS = -lreadline ./libft/libft.a -L./libft -lft

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/ --no-print-directory
	@make bonus -C libft/ --no-print-directory
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

re: fclean all