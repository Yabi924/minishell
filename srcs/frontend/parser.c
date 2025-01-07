/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:55:18 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/07 17:37:18 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int count(char *s)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i])
    {
        if (is_target(s[i], "'\""))
        {
            i += skip_quotes(s, i + 1, s[i]);
            printf("i:%d\n", i);
        }
        if (s[i] == ' ' && s[i + 1] && s[i + 1] != ' ')
            count++;
        i++;
    }
    return (count);
}

char    **split(char *s)
{
    int i;
    int j;
    char    **arr;

    i = 0;
    j = 0;
    arr = ft_calloc(count(s) + 1, sizeof(char *));
    while (s[i])
    {
        j = 0;
        while (s[i + j] != ' ')
        {
            j++;
        }
    }
    return NULL;
}

void    parser(t_data *data)
{
    add_space(data);
    ft_printf("%s\n", data->new_input);
    data->command_arr = split(data->new_input);
    // tokenization(data);
}
