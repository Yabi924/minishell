/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:45:30 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/25 20:55:50 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_input(char *command)
{
	int	i;
	int	f;

	i = -1;
	f = 0;
	if (command[0] == '=')
		return (-1);
	while (command[++i])
		if (command[i] == '=')
			f = 1;
	if (!f)
		return (1);
	return (0);
}

char	**add_env(t_data *data, char *set)
{
	int		i;
	char	**new;

	i = -1;
	new = (char **)malloc((ft_arrlen(data->env) + 2) * sizeof(char *));
	if (!new)
		return (NULL);
	while (data->env[++i])
		new[i] = ft_strdup(data->env[i]);
	new[i++] = ft_strdup(set);
	new[i] = NULL;
	free_arr(data->env);
	return (new);
}

int	del_same_env(t_data *data, char *target)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	j = 0;
	while (target[j] != '=' && target[j])
		j++;
	temp = ft_substr(target, 0, j);
	if (!temp)
		return (1);
	while (data->env[++i])
	{
		if (is_env(temp, data->env[i]))
		{
			data->env = del_env(data->env, temp);
			break ;
		}
	}
	free(temp);
	return (0);
}

void	ft_export(t_data *data, t_list *list)
{
	int i;
	int f;

	i = -1;
	if (!list->command[0] || !list->command[1])
		return ;
	while (list->command[++i])
	{
		f = check_input(list->command[i]);
		if (f == -1)
		{
			printf("minishell : export: `%s': not a valid identifier\n", \
				list->command[i]);
			data->cmd_exit_no = 1;
		}
		else if (f == 0)
		{
			if (del_same_env(data, list->command[i]))
				return ;
			data->env = add_env(data, list->command[i]);
		}
	}
	data->cmd_exit_no = 0;
}
