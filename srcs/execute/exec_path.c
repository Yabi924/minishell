
#include "../../include/minishell.h"

void    path_to_execve(t_data *data)
{
    pid_t	p_id;

	if (access(data->command_arr[0], F_OK | X_OK) == 0)
	{
		p_id = fork();
		if (p_id == 0)
		{
			ft_signal(1);
			execve(data->command_arr[0], data->command_arr, data->env);
		}
		else if (p_id)
		{
			waitpid(p_id, &data->cmd_exit_no, 0);
			data->cmd_exit_no = WEXITSTATUS(data->cmd_exit_no);
		}
	}
	else
	{
		ft_putstr_fd("Minishell: ", 2);
		perror(data->command_arr[0]);
		data->cmd_exit_no = 127;
		return ;
	}
}