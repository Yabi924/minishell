/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:23:07 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/01/08 20:23:08 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    echo_builtin(char **args)
{
    int i = 1;
    int no_newline = 0;

    //Check for the "-n" option
    if (args[1] && strcmp(args[1], "-n") == 0)
    {
        no_newline = 1;
        i = 2;
    }
    while (args[i])
    {
        ft_putstr_fd(args[i], STDOUT_FILENO);
        if (args[i + 1])
            ft_putchar_fd(' ', STDOUT_FILENO);
        i++;
    }
    if (!no_newline)
        ft_putchar_fd('\n', STDOUT_FILENO);
}