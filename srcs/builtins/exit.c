/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:23:27 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/01/08 20:23:29 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    ft_exit(t_data *data)
{
    // int i;

    // i = -1;
    // ft_printf("");
    ft_printf("exit\n");
    free_data(data);
    exit(0);
}

void    builtin_exit(t_data *shell, t_list *list)
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
                ft_printf("Testing1");
                free(list->command);
                exit(shell->cmd_exit_no);
            }
        }
        shell->cmd_exit_no = ft_atoi(list->command[1]);
        shell->cmd_exit_no %= 256;
    }
    else if (list->command[1] && list->command[2])
        ft_printf("Testing2");
    else
        shell->cmd_exit_no = 0;
    exit(shell->cmd_exit_no);
}
