

#include "../../include/minishell.h"

void    exec(t_data *data)
{
    if (data->command_arr && !strcmp(data->command_arr[0], "echo"))
        echo(data);
    else if (data->command_arr && !strcmp(data->command_arr[0], "pwd"))
        get_pwd();
    else if (data->command_arr && !strcmp(data->command_arr[0], "env"))
        env(data);
    else
        executable(data, data->list);
//     else if (data->command_arr && !strcmp(data->command_arr[0], "cd"))
//         change_dir(data);
}