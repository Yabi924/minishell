/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:23:04 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/01/07 17:23:07 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
    Display error message if change directory (cd) is not correct.

    For example:
    Shell> cd Home
    cd: no such file or directory: Hello
*/
void    errorMsg1(char *built_in, char *args, char *msg)
{
    ft_putstr_fd(built_in, 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd(args, 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd(msg, 2);
    ft_putstr_fd("\n", 2);
}

/*
    Tells user where the error at:
         ↓
    echo "Haha
    Syntax error:
*/
void    errorMsg2(char *input, char *msg, int index)
{
    int i;

    i = 0;
    while (i++ < index)
        ft_putstr_fd(" ", 2);
    ft_putstr_fd("↓\n", 2);
    ft_putstr_fd(input, 2);
    ft_putstr_fd("\nminishell: syntax error: ", 2);
    ft_putstr_fd(msg, 2);
    ft_putstr_fd("\n", 2);
}

/*
    Got more things to handle
*/