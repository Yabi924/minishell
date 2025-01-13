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

void builtin_exit(t_data *shell, t_list *list)
{
    printf("exit\n");

    if (list->command[1] && list->command[2]) // Too many arguments
    {
        fprintf(stderr, "Minishell: exit: too many arguments\n");
        shell->cmd_exit_no = 1;
        return;
    }
    else if (list->command[1]) // Argument provided
    {
        for (int i = 0; list->command[1][i]; i++)
        {
            if (!ft_isdigit(list->command[1][i]))
            {
                fprintf(stderr, "Minishell: exit: %s: numeric argument required\n", list->command[1]);
                exit(2);
            }
        }
        shell->cmd_exit_no = ft_atoi(list->command[1]) % 256;
    }
    exit(shell->cmd_exit_no);
}

