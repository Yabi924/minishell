/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:17:36 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/26 22:41:42 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_if_redirect(t_list *list, int i)
{
	if (!ft_strncmp(list->command[i], "<\0", 2))
		return (1);
	else if (!ft_strncmp(list->command[i], ">\0", 2))
		return (2);
	else if (!ft_strncmp(list->command[i], "<<\0", 3))
		return (3);
	else if (!ft_strncmp(list->command[i], ">>\0", 3))
		return (4);
	else
		return (0);
}

int	check_redirect_syntax(t_data *data, t_list *list, int i)
{
	if (!list->command || !(*list->command))
		return (0);
	if (check_if_redirect(list, i))
	{
		if (!list->command[i + 1] || check_if_redirect(list, i + 1))
		{
			err_msg(data, 2, "Syntax error near redirection.\n", NULL);
			return (0);
		}
		return (1);
	}
	return (2);
}