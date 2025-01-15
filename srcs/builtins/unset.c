/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:24:01 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/01/15 16:06:10 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void free_env_node(t_env *env);

int	ft_unset(char **args, t_data *data)
{
	int		i;
	t_env	*current;
	t_env	*previous;

	i = 0;
	while (args[++i])
	{
		current = data->env_ll;
		previous = NULL;
		while (current)
		{
			if (strcmp(args[i], current->key) == 0)
			{
				if (previous)
					previous->next = current->next;
				else
					data->env_ll = current->next;
				free_env_node(current);
				break ;
			}
			previous = current;
			current = current->next;
		}
	}
	return (EXIT_SUCCESS);
}

static void free_env_node(t_env *env)
{
    free(env->key);
    free(env->value);
    free(env);
}