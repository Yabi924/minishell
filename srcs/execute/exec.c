

#include "../../include/minishell.h"

void    exec(t_data *data)
{
    if (!data->command_arr[0])
        return ;
    if (data->command_arr && !strncmp(data->command_arr[0], "echo\0", 5))
        echo(data);
    else if (data->command_arr && !strcmp(data->command_arr[0], "pwd"))
        get_pwd();
    else if (!ft_strncmp(data->list->command[0], "exit\0", 5))
        exit_shell();
    else if (!ft_strncmp(data->list->command[0], "unset\0", 6))
        unset(data, data->list, data->env);
    else if (!ft_strncmp(data->list->command[0], "env\0", 4))
        env(data);
    else if (data->command_arr && !strcmp(data->command_arr[0], "cd"))
        ft_cd(data);
    else
        executable(data, data->list);
}

void exit_shell(void)
{
    write(1, "exit\n", 5);
    exit(0);
}