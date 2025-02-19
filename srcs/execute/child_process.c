/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:22:00 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/15 08:22:05 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	This file handle the child process.
*/

void	child_process(t_data *data, t_list *list);
int		input_config(t_data *data, t_list *list);
void	output_config(t_data *data, t_list *list);
void	shell_cmd(t_data *data, t_list *list);

/*
	input_config

	This function configures the input for the command based on redirection
	or pipes.
*/
int	input_config(t_data *data, t_list *list)
{
	if (list->in_path && list->delimiter == NULL)
		data->in_fd = open(list->in_path, O_RDONLY);
	else if (list->in_path == NULL && list->delimiter)
		data->in_fd = open(".tmp", O_RDONLY);
	else if (list->fd[0] != -1 && list->fd[0] != 0)
		data->in_fd = list->fd[0];
	else
		data->in_fd = dup(data->in_first);
	if (data->heredoc && data->cmd_exit_no == 42)
		return (1);
	if (data->in_fd == -1 && !data->heredoc)
	{
		perror("Minishell: Infile");
		return (1);
	}
	if (dup2(data->in_fd, 0) == -1 && !data->heredoc)
	{
		ft_printf("%d\n", data->in_fd);
		perror("Error: infile fd");
		return (1);
	}
	close(data->in_fd);
	return (0);
}

/*
	output_config

	This function configures the output for the command based on redirection
	or pipes.
*/
void	output_config(t_data *data, t_list *list)
{
	if (list->out_path && list->append == 0)
		data->out_fd = open(list->out_path, \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (list->out_path && list->append == 1)
		data->out_fd = open(list->out_path, \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (list->next)
	{
		data->out_fd = list->next->fd[1];
		close(list->next->fd[0]);
	}
	else
		data->out_fd = dup(data->out_first);
	if (dup2(data->out_fd, 1) == -1)
	{
		perror("Error: outfile fd");
		return ;
	}
	close(data->out_fd);
}

/*
	This function waits for child processes to finish and handles their exit statuses.
*/
void	transit_end(pid_t *children, t_data *mshell)
{
	int	status;
	int	i;

	i = -1;
	while (children[++i] != -1)
	{
		waitpid(children[i], &status, 0);
		if (WIFSIGNALED(status))
			mshell->cmd_exit_no = 128 + WTERMSIG(status);
		else if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
			mshell->cmd_exit_no = status;
		}
	}
}

/*
	shell_cmd

	This function executes the actual command in the shell by either running
	a built-in command or an external executable.
*/
void     shell_cmd(t_data *data, t_list *list)
{
	char	*path;
	if (confirm_built_in(list))
		return ;
	if (list->command && list->command[0])
	{
		path = collect_path(data, list);
		if (!ft_strncmp(list->command[0], ".", 1) \
			|| !ft_strncmp(list->command[0], "..", 2))
			path = NULL;
		if (!path)
		{
			err_msg(data, 127, "Minishell: '%s': command not found\n", \
						  list->command[0]);
			free(path);
			return ;
		}
		execve(path, list->command, data->env);
		free(path);
		data->cmd_exit_no = 1;
	}
}

/*
	child_process

	This function is executed in a child process created by fork().
	It handles input/output redirection
*/
void	child_process(t_data *data, t_list *list)
{
	if (input_config(data, list) == 0)
	{
		if (data->heredoc)
			exit(data->cmd_exit_no);
		output_config(data, list);
		ft_signal(1);
		if (confirm_built_in(list))
			built_in(data, list);
		shell_cmd(data, list);
	}
	else
		data->cmd_exit_no = 1;
	exit(data->cmd_exit_no);
}