/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_updater.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:16:30 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/20 22:16:34 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    command_updater(t_list **list, int i);

void    command_updater(t_list **list, int i)
{
    t_list  *temp;

    free((*list)->command[i]);
    free((*list)->command[i + 1]);
    while ((*list)->command[i + 2])
    {
        (*list)->command[i] = (*list)->command[i + 2];
        ++i;
    }
    (*list)->command[i] = NULL;
    if ((*list)->command == NULL)
    {
        temp = (*list)->next;
        free_arr((*list)->command);
        free(*list);
        *list = temp;
    }
}
