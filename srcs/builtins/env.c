/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:57:24 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/26 23:03:51 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env(t_data *data)
{
	int	i;

	i = 0;
	if (!data->env)
		return ;
	// if (data->list->command[1])
	// {
	// 	err_msg(data, 127, "env: '%s': No such file or directory\n", 
	// 			data->list->command[1]);
	// 	return ;
	// }
	while (data->env[i])
		ft_printf("%s\n", data->env[i++]);
	data->cmd_exit_no = 0;
}