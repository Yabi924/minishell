/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:51:58 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/01/18 17:17:53 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/*
void    signal_int(int signal_no)
{
    (void)signal_no;
    ft_printf("\n");
    rl_on_new_line();
    rl_replace_line("", 0); //0 for standard input
    rl_redisplay();
    g_exit_code = 130;
}

void    signal_quit(int signal_no)
{
    (void)signal_no;
    //ft_printf("Quit\n");
}

void    signal_int_child(int signal_no)
{
    (void)signal_no;
    ft_printf("\n");
    exit(130);
}

void    signal_quit_child(int signal_no)
{
    (void)signal_no;
    ft_printf("\nQuit (core dumped)\n");
    exit(131);
}

void    heredoc(int signal_no)
{
    (void)signal_no;
    ft_printf("SIGINT\n");
    exit(130);
}
*/

void    quit_3(int sigquit)
{
    (void)sigquit;
    ft_printf("Quit (core dumped)\n");
    g_exit_code = 131;
}

void    quit_subshell(int sigint)
{
    (void)sigint;
    ft_printf("\n");
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

void    ft_signal(int flag)
{
    if (flag == 0)
        flag_0();
    else if (flag == 1)
        flag_1();
    else if (flag == 2)
        flag_2();
}

void    flag_0()
{
    signal(SIGINT, signal_int);
    signal(SIGQUIT, SIG_IGN);
}

void    flag_1()
{
    signal(SIGINT, quit_subshell);
    signal(SIGQUIT, quit_3);
}

void    flag_2()
{
    signal(SIGINT, hd_action);
    signal(SIGQUIT, SIG_IGN);
}
