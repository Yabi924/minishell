

#include "../../include/minishell.h"

void    exec(t_data *data)
{
    if (data->command_arr && !strcmp(data->command_arr[0], "env"))
        show_env(data->env_ll);
    else if (data->command_arr && !strcmp(data->command_arr[0], "echo"))
        echo(data);
    else if (data->command_arr && !strcmp(data->command_arr[0], "pwd"))
        get_pwd();
}