/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:57:24 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/27 16:31:35 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env(t_data *data)
{
	int	i;
	int p;

	i = 0;
	p = -1;
	if (!data->env)
		return ;
	while (data->list->command[++p])
	{
		if (ft_strncmp(data->list->command[p], "env\0", 4))
		{
			printf("env: ‘%s’: No such file or directory\n", data->list->command[p]);
			data->cmd_exit_no = 127;
			return ;
		}
	}
	while (data->env[i])
		ft_printf("%s\n", data->env[i++]);
	data->cmd_exit_no = 0;
}