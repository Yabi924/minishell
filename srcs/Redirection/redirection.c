/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:17:59 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/26 22:41:50 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	redirect_config(t_list *list, int i, int status)
{
	status = check_if_redirect(list, i);
	if (status)
	{
		if (status == 1)
		{
			if (list->in_path)
				free(list->in_path);
		}
		else if (status == 2 || status == 4)
		{
			if (list->out_path)
			{
				open(list->out_path, O_WRONLY | O_CREAT, 0644);
				free(list->out_path);
			}
			if (status == 4)
				list->append = 1;
		}
		else if (status == 3)
		{
			if (list->delimiter)
				free(list->delimiter);
		}
	}
}

void	redirect_config2(t_list *list, int i, int status)
{
	status = check_if_redirect(list, i);
	if (status == 1)
		list->in_path = ft_strdup(list->command[i + 1]);
	else if (status == 2 || status == 4)
		list->out_path = ft_strdup(list->command[i + 1]);
	else if (status == 3)
		list->delimiter = ft_strdup(list->command[i + 1]);
	if (list->in_path || list->out_path || list->delimiter)
		command_updater(&list, i);
}

int	redirection(t_data *data, t_list *list)
{
	t_list	*temp;
	int		i;
	int		value;
	int		status;

	temp = list;
	status = 0;
	while (temp)
	{
		i = -1;
		while (temp->command && temp->command[++i])
		{
			value = check_redirect_syntax(data, temp, i);
			if (!value)
				return (0);
			else if (value == 1)
			{
				redirect_config(temp, i, status);
				redirect_config2(temp, i, status);
				++i;
			}
		}
		temp = temp->next;
	}
	return (1);
}
