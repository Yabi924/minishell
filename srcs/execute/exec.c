

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
        builtin_exit(data);
    else if (!ft_strncmp(data->list->command[0], "unset\0", 6))
        unset(data, data->list, data->env);
    else if (!ft_strncmp(data->list->command[0], "env\0", 4))
        env(data);
    else if (data->command_arr && !strcmp(data->command_arr[0], "cd"))
        ft_cd(data);
    else
        executable(data, data->list);
}

int	builtin_check(t_data *mini)
{
	if (mini->input_arr && !ft_strncmp(mini->input_arr[0], "env", 4))
		return (1);
	else if (mini->input_arr && !ft_strncmp(mini->input_arr[0], "pwd", 4))
		return (1);
	else if (mini->input_arr && !ft_strncmp(mini->input_arr[0], "cd", 3))
		return (1);
	else if (mini->input_arr && !ft_strncmp(mini->input_arr[0], "unset", 6))
		return (1);
	else if (mini->input_arr && !ft_strncmp(mini->input_arr[0], "export", 7))
		return (1);
	else if (mini->input_arr && !ft_strncmp(mini->input_arr[0], "echo", 7))
		return (1);
	else if (mini->input_arr && !ft_strncmp(mini->input_arr[0], "exit", 5))
		return (1);
	return (0);
}

void	array_dup(t_data *mini)
{
	char	**dup;
	int		x;
	int		y;

	y = 0;
	x = 0;
	dup = mal_dup(mini);
	while (mini->input_arr[x])
	{
		if (!is_redir(mini->input_arr[x]))
			x += 2;
		else
			dup[y++] = ft_strdup(mini->input_arr[x++]);
	}
	x = -1;
	while (mini->input_arr[++x])
	{
		if (!is_redir(mini->input_arr[x]))
		{
			dup[y++] = ft_strdup(mini->input_arr[x++]);
			dup[y++] = ft_strdup(mini->input_arr[x]);
		}
	}
	free(mini->input_arr);
	mini->input_arr = dup;
}

void exit_shell(t_data *shell)
{
    write(1, "exit\n", 5);
	free(shell);
    exit(0);
}