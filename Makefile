#flags
CFLAGS = -Wall -Wextra -Werror

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
PATH_Redirection = $(PATH_SRCS)Redirection/
PATH_env = $(PATH_fn)Env_Var/
PATH_token = $(PATH_fn)token/
PATH_utils = $(PATH_fn)utils/
PATH_signal = $(PATH_SRCS)signal/
PATH_error = $(PATH_SRCS)error_handler/

#src
s_builtin = $(PATH_BUILTIN)echo.c \
			$(PATH_BUILTIN)pwd.c \
			$(PATH_BUILTIN)env.c \
			$(PATH_BUILTIN)exit.c \
			$(PATH_BUILTIN)cd.c \
			$(PATH_BUILTIN)export.c \
			$(PATH_BUILTIN)export2.c \
			$(PATH_BUILTIN)unset.c \

s_execute =	$(PATH_EXECUTE)built_in.c \
			$(PATH_EXECUTE)execute.c \
			$(PATH_EXECUTE)execve_path.c \
			$(PATH_EXECUTE)add_path.c \
			$(PATH_EXECUTE)child_process.c \
			$(PATH_EXECUTE)get_path.c \

s_ctrl = $(PATH_CTRL)

s_his = $(PATH_History)

s_redirection = $(PATH_Redirection)

s_rdrt = $(PATH_Redirection)redirect_checker.c \
		 $(PATH_Redirection)command_updater.c \
		 $(PATH_Redirection)redirection.c \
		 $(PATH_Redirection)heredoc.c \

s_env = $(PATH_env)dollar_sign.c \
		$(PATH_env)count.c \
		$(PATH_env)env_handle.c

s_token = $(PATH_token)tokenization.c \
		$(PATH_token)split.c

s_utils = $(PATH_utils)utils.c \
		$(PATH_utils)check.c \
		$(PATH_utils)check_pipe.c \
		$(PATH_utils)add_space.c

s_input_handle = $(PATH_fn)input_handle.c \
				 $(PATH_fn)parser.c

s_signal = $(PATH_signal)signal.c \
		$(PATH_signal)signal2.c

s_error = $(PATH_error)error_msg_1.c 

main= ./srcs/main.c \
	  ./srcs/free.c \

SRCS = $(main) $(s_utils) $(s_input_handle) $(s_token) $(s_env) $(s_signal) $(s_execute) $(s_error) $(s_rdrt) $(s_builtin)

#objs
OBJS = $(SRCS:.c=.o)

#lib
LIBS = -lreadline ./libft/libft.a -L./libft -lft

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/ --no-print-directory
	@make bonus -C libft/ --no-print-directory
	@gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@echo $(NAME) good to go.

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

r: $(NAME)
# clear
	valgrind --leak-check=full --track-origins=yes ./minishell

rr: re r