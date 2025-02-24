/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal2.c                                         :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:16:08 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/01/18 17:17:53 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    quit_3(int sigquit)
{
    (void)sigquit;
    ft_printf("^""\\""Quit (core dumped)\n");
    g_exit_code = 131;
}

void    quit_subshell(int sigint)
{
    (void)sigint;
    ft_printf("^C\n");
}

void    signal_int(int sigint)
{
    (void)sigint;
    ft_printf("\n");
    rl_replace_line("", 0);
    rl_on_new_line();
    rl_redisplay();
    g_exit_code = 130;
}

void    hd_action(int sigint)
{
    (void)sigint;
    unlink(".tmp");
    exit(42);
}