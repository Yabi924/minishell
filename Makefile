#flags
CFLAGS = -Wall -Wextra -Werror -g3

#program name
NAME = minishell

#src path
PATH_SRCS = ./srcs/
PATH_fn = $(PATH_SRCS)frontend/

#function path
PATH_BUILTIN = $(PATH_SRCS)builtins/
PATH_EXECUTE = $(PATH_SRCS)execute/
PATH_CTRL = $(PATH_SRCS)CTRL/
PATH_History = $(PATH_SRCS)History/
PATH_Pipe = $(PATH_SRCS)Pipe/
PATH_dollar = $(PATH_fn)dollar_sign/
PATH_Redirection = $(PATH_SRCS)Redirection/
PATH_env = $(PATH_fn)Env_Var/
PATH_token = $(PATH_fn)token/
PATH_utils = $(PATH_fn)utils/
PATH_signal = $(PATH_SRCS)signal/

#src
s_builtin = $(PATH_BUILTIN)exit.c\
			$(PATH_BUILTIN)echo.c\
			$(PATH_BUILTIN)unset.c

s_execute = $(PATH_EXECUTE)

s_ctrl = $(PATH_CTRL)

s_his = $(PATH_History)

s_pipe = $(PATH_Pipe)

s_dollar = $(PATH_dollar)dollar_sign.c \
		$(PATH_dollar)count.c

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
		$(PATH_fn)parser.c \
		$(PATH_fn)init.c

s_signal = $(PATH_signal)signal.c \
		   $(PATH_signal)get_stat.c

main= ./srcs/main.c \
	./srcs/free.c

SRCS = $(main) $(s_utils) $(s_input_handle) $(s_token) $(s_dollar) $(s_signal) $(s_builtin) #$(s_execute)#$(s_ctrl) $(s_his) $(s_pipe) $(s_quotes) $(s_rdrt) $(s_env)

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