/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:23:07 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/26 22:47:00 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_redirect_sign(char *data)
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

	i = -1;
	line = ft_strdup("");
	while (data[++i])
	{
		if (check_redirect_sign(data[i]) == 1)
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
	char	*line;
	int		i;
	int		fd;
	int		newline;

	i = 0;
	fd = 1;
	newline = 1;
	if (!data->list->command[1])
	{
		write(1, "\n", 1);
		return ;
	}
	ft_echo_process1(data, &i, &newline);
	line = retrieve_line(&data->list->command[i]);
	ft_echo_process2(data, line, fd, newline);
}

void	ft_echo_process1(t_data *data, int *i, int *newline)
{
	int	j;

	*i = 1;
	*newline = 1;
	while (data->list->command[*i])
	{
		if (data->list->command[*i][0] == '-' && data->list->command[*i][1])
		{
			j = 1;
			while (data->list->command[*i][j] == 'n')
				j++;
			if (data->list->command[*i][j] != '\0')
				break ;
		}
		else
			break ;
		(*newline) = 0;
		(*i)++;
	}
}

void	ft_echo_process2(t_data *data, char *line, int fd, int newline)
{
	if (data->list->out_path)
	{
		if (data->list->append)
			fd = open(data->list->out_path, \
					O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd = open(data->list->out_path, \
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			err_msg(data, 1, "Failed to open file for redirection.\n", \
					data->list->out_path);
			free(line);
			return ;
		}
	}
	write(fd, line, ft_strlen(line));
	free(line);
	if (newline)
		write(fd, "\n", 1);
}