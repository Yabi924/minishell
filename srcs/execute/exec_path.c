
#include "../../include/minishell.h"

void    path_to_execve(t_data *data, t_list *list)
{
    pid_t	p_id;

	if (access(list->command[0], F_OK | X_OK) == 0)
	{
		p_id = fork();
		if (p_id == 0)
		{
			ft_signal(1);
			execve(list->command[0], list->command, data->env);
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
		perror(list->command[0]);
		data->cmd_exit_no = 127;
		return ;
	}
}