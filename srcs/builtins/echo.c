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

	i = -1;
	line = ft_strdup("");
	while (data[++i])
	{
		// if (data[i][0] == '-' && check(&data[i][1]))
		// 	continue ;
		if (check(data[i]) == 1)
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
	//char	*temp;
	char	*line;
	int newline;
	int i;
	int j;
	int flag = 0; 

	i = 0;
	newline = 1;
	if (!data->list->command[1])
	{
		write(1, "\n", 1);
		return ;
	}

	while (data->list->command[++i]) 
	{
        j = 0;
        if (data->list->command[i][0] == '-' && data->list->command[i][1]) 
		{
            while (data->list->command[i][++j])
			{
                if (data->list->command[i][j] != 'n')
				{
                    flag = 1;
                    break;
                }
            }
        } 
		else 
            break;
        if (flag)
            break;
        newline = 0;
    }
	
	line = retrieve_line(&data->list->command[i]);
	write(1, line, ft_strlen(line));
	free(line);
	if (newline)
		write(1, "\n", 1);

	/*
		New method:
	*/
	
	
	//data->cmd_exit_no = 0;
}