#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

void    input_handler(const char *input, char **env);

#endif