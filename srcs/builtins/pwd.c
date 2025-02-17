/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:42:02 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/15 12:42:05 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

void    ft_pwd()
{
    // ft_printf("%s\n", data->cwd);
    // data->cmd_exit_no = 0;
    char    *pwd;
    pwd = getcwd(NULL, 1024);
    ft_printf("%s\n", pwd);
    free(pwd);
}
