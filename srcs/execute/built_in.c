/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:14:48 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/15 19:14:51 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*built in*/
void    built_in(t_data *data, t_list *list)
{
    if (list == NULL || list->command == NULL || list->command[0] == NULL)
    {
        ft_putstr_fd("Error: list or command is NULL\n", 2); // For debug only
        return ;
    }
    /*echo*/
    else if (!ft_strncmp(list->command[0], "echo\0", 5))
        ft_echo(data);
    /*pwd*/
    else if (!ft_strncmp(list->command[0], "pwd\0", 4))
        ft_pwd();
    /*env*/
    else if (!ft_strncmp(list->command[0], "env\0", 4))
        ft_env(data);
    /*exit*/
    else if (!ft_strncmp(list->command[0], "exit\0", 5))
        ft_exit(data);
    /*cd*/
    else if (!ft_strncmp(list->command[0], "cd\0", 3))
        ft_cd(data, data->list);
    /*export*/
    else if (!ft_strncmp(list->command[0], "export\0", 7))
        ft_export(data, data->list);
    /*unset*/
    else if (!ft_strncmp(list->command[0], "unset\0", 4))
        ft_unset(data, data->list, data->env);
    else
        execve_command(data, data->list);
}

/*
    Confirm built in

    To check if the built in command is there in prompt
*/

int    confirm_built_in(t_list *list)
{
    if (!list->command[0])
        return (0);
    /*echo*/
    else if (!ft_strncmp(list->command[0], "echo\0", 5))
        return (1);
    /*cd*/
    else if (!ft_strncmp(list->command[0], "cd\0", 3))
        return (1);
    /*pwd*/
    else if (!ft_strncmp(list->command[0], "pwd\0", 4))
        return (1);
    /*export*/
    else if (!ft_strncmp(list->command[0], "export\0", 7))
         return (1);
    /*unset*/
    else if (!ft_strncmp(list->command[0], "unset\0", 4))
        return (1);
    /*env*/
    else if (!ft_strncmp(list->command[0], "env\0", 4))
        return (1);
    /*exit*/
    else if (!ft_strncmp(list->command[0], "exit\0", 5))
        return (1);
    return (0);
}