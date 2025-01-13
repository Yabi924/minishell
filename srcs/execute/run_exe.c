

#include "../../include/minishell.h"

int     exit_num(char **in)
{
    int     x;

    x = 0;
    while(in[x++])
        return;
    if (x > 2 && !ft_strncmp(in[0], "exit", 5))
        return (ft_atoi(in[1]));
    return (0);
}

void    command_handle(t_data *mini, int exit_if_zero)
{
    if (mini->command_arr && !ft_strncmp(mini->command_arr[0], "env", 4))
        print_env(mini->env_ll);
    else if (mini->command_arr && !ft_strncmp(mini->command_arr[0], "pwd", 4))
        get_pwd();
    else if (mini->command_arr && !ft_strncmp(mini->command_arr[0], "cd", 3))
        change_dir(mini);
    else if (mini->command_arr && !ft_strncmp(mini->command_arr[0], "unset", 6))
        unset(mini);
    else if (mini->command_arr && !ft_strncmp(mini->command_arr[0], "export", 7))
        export(mini);
    else if (mini->command_arr && !ft_strncmp(mini->command_arr[0], "echo", 7))
        echo(mini);
    else if (mini->command_arr && !ft_strncmp(mini->command_arr[0], "exit", 5) && \
            exit_if_zero == 0)
        exit(0);
    else if (mini->command_arr && !ft_strncmp(mini->command_arr[0], "exit", 5))
		end(mini, 1, exit_num(mini->command_arr));
}

int     builtin_check(t_data *mini)
{
    if (mini->command_arr && !ft_strncmp(mini->command_arr[0], "env", 4))
        return (1);
    else if (mini->command_arr && !ft_strncmp(mini->command_arr[0], "pwd", 4))
        return (1);
    else if (mini->command_arr && !ft_strncmp(mini->command_arr[0], "cd", 3))
        return (1);
    else if (mini->command_arr && !ft_strncmp(mini->command_arr[0], "unset", 6))
        return (1);
    else if (mini->command_arr && !ft_strncmp(mini->command_arr[0], "export", 7))
        return (1);
    else if (mini->command_arr && !ft_strncmp(mini->command_arr[0], "echo", 7))
        return (1);
    else if (mini->command_arr && !ft_strncmp(mini->command_arr[0], "exit", 5))
        return (1);
    return (0);
}

void    array_dup(t_data *mini)
{
    char    **dup;
    int     x;
    int     y;

    x = 0;
    y = 0;
    dup = mal_dup(mini);
    while (mini->command_arr[x])
    {
        if (!is_redir(mini->command_arr[x]))
            x += 2;
        else
            dup[y++] = ft_strdup(mini->command_arr[x++]);
    }
    x = -1;
    while (mini->command_arr[++x])
    {
        if (!is_redir(mini->command_arr[x]))
        {
            dup[y++] = ft_strdup(mini->command_arr[x++]);
            dup[y++] = ft_strdup(mini->command_arr[x]);
        }
    }
    free(mini->command_arr);
    mini->command_arr = dup;
}