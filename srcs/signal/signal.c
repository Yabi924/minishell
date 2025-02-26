/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:51:58 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/26 22:43:32 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    ft_signal(int flag)
{
    if (flag == 0)
        flag_0();
    else if (flag == 1)
        flag_1();
    else if (flag == 2)
        flag_2();
}

void    flag_0(void)
{
    signal(SIGINT, signal_int);
    signal(SIGQUIT, SIG_IGN);
}

void    flag_1(void)
{
    signal(SIGINT, quit_subshell);
    signal(SIGQUIT, quit_3);
}

void    flag_2(void)
{
    signal(SIGINT, hd_action);
    signal(SIGQUIT, SIG_IGN);
}