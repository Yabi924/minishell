/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:23:04 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/26 22:51:46 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	err_msg(t_data *mshell, int exit_status, char *msg, char *args)
{
	int	i;

	i = -1;
	while (msg[++i])
	{
		if (msg[i] == '%' && msg[i + 1] == 's' && args)
		{
			ft_putstr_fd(args, 2);
			++i;
			continue ;
		}
		ft_putchar_fd(msg[i], 2);
	}
	mshell->cmd_exit_no = exit_status;
}