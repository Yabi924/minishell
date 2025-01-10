/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:40:04 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/11 00:40:40 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    free_arr(char **arr)
{
    int i;

    i = 0;
    if (!arr)
        return ;
    if (arr[i])
        free(arr[i++]);
    free(arr);
}

void    free_linked_list(t_list **list)
{
    t_list *temp;
    t_list *p;

    p = *list;
    while (p)
    {
        temp = p->next;
        ft_lstdelone(p, &free_arr);
        p = temp;
    }
    free(list);
    *list = NULL;
}

void    free_data(t_data *data)
{
    free_arr(data->command_arr);
    free_linked_list(data->list);
}
