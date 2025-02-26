/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:36:57 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/26 22:41:00 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*collect_path(t_data *data, t_list *list)
{
	char	**env_path;
	char	*temp;
	char	*path;
	int		i;

	i = -1;
	env_path = ft_split(collect_env(data, "PATH"), ':');
	while (env_path && env_path[++i])
	{
		temp = ft_strjoin(env_path[i], "/");
		path = ft_strjoin(temp, list->command[0]);
		free(temp);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_arr(env_path);
			return (path);
		}
		free(path);
	}
	free_arr(env_path);
	return (NULL);
}

char	*collect_env(t_data *data, char *env_var)
{
	char	*value;
	int		i;

	i = -1;
	value = NULL;
	if (!ft_strncmp(env_var, "?\0", 2))
		return (ft_itoa(data->cmd_exit_no));
	while (data->env[++i])
	{
		if (!ft_strncmp(data->env[i], env_var, ft_strlen(env_var)) && \
				data->env[i][ft_strlen(env_var)] == '=')
		{
			value = ft_strchr(data->env[i], '=') + 1;
			break ;
		}
	}
	if (!value)
		return ("");
	return (value);
}
