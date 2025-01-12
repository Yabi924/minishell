/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:22:56 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/01/08 20:22:58 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void update_oldpwd(t_data *data)
{
    char    cwd[1024];
    t_data  *current;

    current = data->env;
    if (getcwd(cwd, sizeof(cwd)) == NULL)
        err_exit("getcwd", errno);
    while (current)
    {
        if (strcmp(current->env, "OLDPWD") == 0)
        {
            free(current->command_arr);
            current->command_arr = ft_strdup(cwd);
            return ;
        }
        current = current->command_arr;
    }
}

static void update_pwd(t_data *data)
{
    char    cwd[1024];
    t_data  *current;

    current = data->env;
    if (getcwd(cwd, sizeof(cwd)) == NULL)
        err_exit("getcwd", errno);
    while (current)
    {
        if (strcmp(current->env, "PWD") == 0)
        {
            free(current->command_arr);
            current->command_arr = ft_strdup(cwd);
            return ;
        }
        current = current->command_arr;
    }
}
