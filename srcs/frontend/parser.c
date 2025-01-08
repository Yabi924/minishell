/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:55:18 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/08 20:47:50 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void    print_arr(char **s)
{
    int i = -1;
    while (s[++i])
        printf("i:%d str:%s\n", i + 1, s[i]);
}

void    parser(t_data *data, t_list **list)
{
    int i = 0;

    add_space(data);
    ft_printf("%s\n", data->new_input);
    tokenization(data, list);

    while (*list)
    {
        printf("i: %d", i++);
        print_arr((*list)->command);
        *list = (*list)->next;
    }
}
