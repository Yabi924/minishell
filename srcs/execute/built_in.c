/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:14:48 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/22 08:33:49 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	built_in(t_data *data, t_list *list)
{
	if (list->command[0] == NULL)
		return ;
	else if (!ft_strncmp(list->command[0], "echo\0", 5))
		ft_echo(data);
	else if (!ft_strncmp(list->command[0], "cd\0", 3))
		ft_cd(data, data->list);
	else if (!ft_strncmp(list->command[0], "pwd\0", 4))
		ft_pwd();
	else if (!ft_strncmp(list->command[0], "env\0", 4))
		ft_env(data);
	else if (!ft_strncmp(list->command[0], "exit\0", 5))
		ft_exit(data, data->list);
	else if (!ft_strncmp(list->command[0], "export\0", 7))
		ft_export(data, data->list);
	else if (!ft_strncmp(list->command[0], "unset\0", 4))
		ft_unset(data, data->list, data->env);
	else if (!ft_strncmp(list->command[0], "./", 2) || \
			!ft_strncmp(list->command[0], "/", 1))
		execve_command(data, data->list);
}

int	confirm_built_in(t_list *list)
{
	if (list == NULL || list->command == NULL
			|| list->command[0] == NULL)
		return (0);
	else if (!ft_strncmp(list->command[0], "echo\0", 5))
		return (1);
	else if (!ft_strncmp(list->command[0], "cd\0", 3))
		return (1);
	else if (!ft_strncmp(list->command[0], "pwd\0", 4))
		return (1);
	else if (!ft_strncmp(list->command[0], "export\0", 7))
		return (1);
	else if (!ft_strncmp(list->command[0], "unset\0", 4))
		return (1);
	else if (!ft_strncmp(list->command[0], "env\0", 4))
		return (1);
	else if (!ft_strncmp(list->command[0], "exit\0", 5))
		return (1);
	else if (!ft_strncmp(list->command[0], "./", 2) || \
			!ft_strncmp(list->command[0], "/", 1))
		return (1);
	return (0);
}
