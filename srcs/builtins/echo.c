/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:23:07 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/01/18 17:54:29 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check(char *data)
{
	if (!ft_strncmp(data, "<", 2)
		|| !ft_strncmp(data, "<<", 3)
		|| !ft_strncmp(data, ">", 2)
		|| !ft_strncmp(data, ">>", 3))
		return (1);
	return (0);
}

char	*retrieve_line(char **data)
{
	char	*temp;
	char	*line;
	int		i;

	i = 0;
	line = ft_strdup("");
	while (data[++i])
	{
		if (!ft_strncmp(data[i], "-n", 2))
			continue ;
		else if (check(data[i]) == 1)
			break ;
		else if (data[i] != 0)
		{
			temp = strjoin_helper(line, data[i], 1, 0);
			if (!data[i + 1])
			{
				line = ft_strdup(temp);
				free(temp);
			}
			else
				line = strjoin_helper(temp, " ", 1, 0);
		}
	}
	return (line);
}

void	ft_echo(t_data *data)
{
	char	*temp;
	char	*line;

	if (!data->list->command[1])
	{
		write(1, "\n", 1);
		return ;
	}
	line = retrieve_line(data->list->command);
	if (ft_strncmp(data->list->command[1], "-n", 2))
	{
		temp = strjoin_helper(line, "\n", 1, 0);
		line = ft_strdup(temp);
		free(temp);
	}
	write(1, line, ft_strlen(line));
	free(line);
	data->cmd_exit_no = 0;
}