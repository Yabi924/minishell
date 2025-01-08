/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:51:58 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/01/08 17:52:00 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void    signal_int(int signal_no)
{
    (void)signal_no;
    ft_printf("\n");
    rl_on_new_line();
    rl_replace_line("", 0); //0 for standard input
    rl_redisplay();
}

void    signal_quit(int signal_no)
{
    (void)signal_no;
    ft_printf("Quit\n");
}

void    signal_int_child(int signal_no)
{
    (void)signal_no;
    ft_printf("Quit\n");
}

void    signal_quit_child(int signal_no)
{
    (void)signal_no;
    ft_printf("\n");
}

void    heredoc(int signal_no)
{
    (void)signal_no;
    ft_printf("SIGINT\n");
    exit(130);
}

/*
    Summary (Thanks to ChatGPT):

    Summary:

    1) signal_int: Handles SIGINT (Ctrl + C) by cleaning up the terminal input and redisplaying the prompt.
    2) signal_quit: Handles SIGQUIT (Ctrl + ) by printing "Quit".
    3) signal_int_child: Handles SIGINT in child processes, printing "Quit", although this seems unusual for SIGINT.
    4) signal_quit_child: Handles SIGQUIT in child processes, printing just a newline.
    5) heredoc: Handles SIGINT during a here document, printing "SIGINT" and exiting with code 130.

    These functions appear to be part of a signal-handling system in a shell program, 
    where each function responds to specific signals (SIGINT and SIGQUIT) depending 
    on whether the signal comes from a parent process or a child process, and whether 
    it's related to a regular input or a special case like a here document.
*/