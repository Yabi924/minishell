/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:45:30 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/21 15:23:33 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_input(char *command)
{
	int	i;
	int	f;

	i = -1;
	f = 0;
	if (!command)
		return (1);
	if (command[0] == '=')
		return (1);
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
			//free(temp);
			return (0);
		}
		// free(temp);
	}
	free(temp);
	return (0);
}

void	ft_export(t_data *data, t_list *list)
{
	if (!list->command[1])
	{
		print_export(data);
		return ;
	}
	if (check_input(list->command[1]))
	{
		ft_printf("minishell : export: `%s': not a valid identifier\n", \
				list->command[1]);
		return ;
	}
	if (del_same_env(data, list->command[1]))
		return ;
	data->env = add_env(data, list->command[1]);
	if (!data->env)
	{
		ft_printf("minishell: memory allocation error\n");
		return ;
	}
	data->cmd_exit_no = 0;
}

void	print_export(t_data *data)
{
	int		i;
	int		sign;
	int		size;
	char		*temp;

	i = -1;
	while (data->env[++i])
		;
	size = i;
	i = -1;
	arrange_env(data->env, size);
	while (data->env[++i])
	{
		if (ft_strchr(data->env[i], '='))
		{
			sign = ft_strpos(data->env[i], "=");
			temp = ft_substr(data->env[i], 0, sign);
			ft_printf("declare -x %s=\"%s\"\n", temp, \
						ft_strchr(data->env[i], '=') + 1);
			free(temp);
		}
		else
			ft_printf("declare -x %s\n", data->env[i]);
	}
	//free(temp);
	data->cmd_exit_no = 0;
}
