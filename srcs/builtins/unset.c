/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:23:41 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/18 17:55:10 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char    **del_env(char **env, char *target)
{
    int     i;
    int     j;
    char    **new;

    i = -1;
    j = 0;
    new = malloc(ft_arrlen(env) * sizeof(char *));
    if (!new)
        return NULL;
    while (env[++i])
    {
        if (!is_env(target, env[i]))
            new[j++] = ft_strdup(env[i]);
    }
    new[j] = NULL;
    free_arr(env);
    return (new);
}

void    ft_unset(t_data *data, t_list *list, char **env)
{
    int i;

    i = 0;
    (void)data;
    if (!list->command[0] || !list->command[1])
        return ;
    while (env[i])
    {
        if (is_env(list->command[1], env[i]))
        {
            data->env = del_env(data->env, list->command[1]);
            break ;
        }
        i++;
    }
    data->cmd_exit_no = 0;
}
