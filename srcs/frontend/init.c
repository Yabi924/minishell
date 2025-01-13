

#include "../../include/minishell.h"

t_data g_minishell;

void init(char **env)
{
    ft_memset(&g_minishell, 0, sizeof(t_data));
    g_minishell.env = env;
    ft_init_envlst();
    g_minishell.stdin = dup(0);
    g_minishell.stdout = dup(1);
    tcgetattr(STDIN_FILENO, &g_minishell.ori_terminal);
}