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
    if (!list->command[0])
        return ;
    /*echo*/
    else if (data->command_arr && !ft_strncmp(list->command[0], "echo\0", 5))
        ft_echo(data);
    /*cd*/
    else if (data->command_arr && !ft_strncmp(list->command[0], "cd\0", 3))
        ft_cd(data);
    /*pwd*/
    else if (data->command_arr && !ft_strncmp(list->command[0], "pwd\0", 4))
        ft_pwd();
    /*export*/
    else if (data->command_arr && !ft_strncmp(list->command[0], "export\0", 7))
         ft_export(data, data->list);
    /*unset*/
    else if (data->command_arr && !ft_strncmp(list->command[0], "unset\0", 4))
        ft_unset(data, data->list, data->env);
    /*env*/
    else if (data->command_arr && !ft_strncmp(list->command[0], "env\0", 4))
        ft_env(data);
    /*exit*/
    else if (data->command_arr && !ft_strncmp(list->command[0], "exit\0", 5))
        ft_exit(data);
    else
        ft_execute(data, data->list);
}

/*
    Confirm built in
*/
int    confirm_built_in(t_list *list)
{
    if (!list->command[0])
        return (0);
    /*echo*/
    else if (list->command[0] && !ft_strncmp(list->command[0], "echo\0", 5))
        return (1);
    /*cd*/
    else if (list->command[0] && !ft_strncmp(list->command[0], "cd\0", 3))
        return (1);
    /*pwd*/
    else if (list->command[0] && !ft_strncmp(list->command[0], "pwd\0", 4))
        return (1);
    /*export*/
    else if (list->command[0] && !ft_strncmp(list->command[0], "export\0", 7))
         return (1);
    /*unset*/
    else if (list->command[0] && !ft_strncmp(list->command[0], "unset\0", 4))
        return (1);
    /*env*/
    else if (list->command[0] && !ft_strncmp(list->command[0], "env\0", 4))
        return (1);
    /*exit*/
    else if (list->command[0] && !ft_strncmp(list->command[0], "exit\0", 5))
        return (1);
    return (0);
}
