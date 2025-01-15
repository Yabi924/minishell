/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:23:17 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/01/15 17:57:51 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:57:24 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/15 17:57:25 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    env(t_data *data)
{
    int     i;

    i = 0;
    if (!data->env)
        return ;
    if (data->list->command[1])
    {
        printf("env: '%s': No such file or directory\n", data->list->command[1]);
        return ;
    }
    while (data->env[i])
        printf("%s\n", data->env[i++]);
    //exit code
}
