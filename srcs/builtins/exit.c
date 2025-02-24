/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:23:27 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/21 15:28:43 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void	ft_exit(t_data *data)
// {
// 	ft_printf("exit\n");
// 	free_data(data);
// 	exit(0);
// }

void    ft_exit(t_data *data, t_list *list)
{
    int i;

    i = -1;
    ft_printf("exit\n");
    if (list->command[1] && !list->command[2])
    {
        while (list->command[1][++i])
        {
            if (!ft_isdigit(list->command[1][i]))
            {
                err_msg(data, 2, \
                        "Minishell: exit: %s: numeric argument required\n", \
                        list->command[1]);
                free_arr(list->command);
                exit(data->cmd_exit_no);
            }
        }
        data->cmd_exit_no = ft_atoi(list->command[1]);
        data->cmd_exit_no %= 256;
    }
    else if (list->command[1] && list->command[2])
        err_msg(data, 1, "Minishell: exit: too many arguments\n", NULL);
    else
        data->cmd_exit_no = 0;
    exit(data->cmd_exit_no);
}