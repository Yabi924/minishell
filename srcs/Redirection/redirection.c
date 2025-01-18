
#include "../../include/minishell.h"

int     right_redirect(t_data *mini, int x, char *valid)
{
    int     fd;

    fd = open(mini->command_arr[x + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0)
    {
        g_exit_code = 258;
        ft_putstr_fd("Minishell: syntax error near unexpected taken 'newline\n", 2);
        return (1);
    }
    if (!ft_strncmp(mini->command_arr[0], ">", 2))
        return (1);
    array_dup(mini);
    if (access(valid, X_OK) == 0 || builtin_check(check) == 1)
        dup2(fd, 1);
    close(fd);
    return (0);
}

char    *get_file(char **in, int x)
{
    while (in[x++])
    {
        if (!ft_strncmp(in[x], "<", 2)
                || !ft_strncmp(in[x], ">", 2)
                || !ft_strncmp(in[x], ">>", 3)
                || !ft_strncmp(in[x], "<<", 3))
                return (in[x - 1]);
    }
    return (in[x - 2]);
}

int     left_redirect(t_data *mini, int x, char *valid)
{
    int     fd;
    char    *file;

    file = get_file(mini->command_arr, x);
    if (x == 0)
    {
        g_exit_code = 258;
        ft_putstr_fd("Minishell: syntax error near unexpected taken 'newline\n", 2);
        return (1);
    }
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        g_exit_code = 1;
        ft_printf("Minishell: no such file or directory: %s\n", file);
        return (1);
    }
    if (access(valid, X_OK) == 0 || builtin_check(mini) == 1)
        dup2(fd, 0);
    close(fd);
    return (0);
}

int     redirect_check(t_data *mini, char *valid)
{
    int     x;
    int     err;

    x = 0;
    err = 0;
    while (mini->command_arr[x])
    {
        if (!ft_strncmp(mini->command_arr[x], ">", 2))
                err = right_redirect(mini, x, valid);
        else if (!ft_strncmp(mini->command_arr[x], ">>", 3))
                err = right_redirect(mini, x, valid);
        else if (!ft_strncmp(mini->command_arr[x], "<", 2))
                err = left_redirect(mini, x, valid);
        if (err == 1)
                return (1);
        x++;
    }
    return (0);
}