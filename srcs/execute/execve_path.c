/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:57:57 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/22 08:59:51 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execve_command(t_data *data, t_list *list)
{
	char	*temp;

	if (access(list->command[0], F_OK | X_OK) == 0)
		temp = ft_strdup(list->command[0]);
	else
	{
		temp = add_path(data, list->command[0]);
		if (!temp)
			return ;
		if (list->command[0])
			free(list->command[0]);
		list->command[0] = ft_strdup(temp);
		if (temp)
			free(temp);
	}
	child_parent(data, list);
}

void	child_parent(t_data *data, t_list *list)
{
	pid_t	p_id;
	char	**env;
	int		status;

	p_id = fork();
	if (p_id < 0)
	{
		perror("minishell");
		return ;
	}
	if (p_id == 0)
	{
		env = data->env;
		if (execve(list->command[0], list->command, env) == -1)
		{
			perror("minishell");
			exit(127);
		}
	}
	else
		waitpid(p_id, &status, 0);
}
