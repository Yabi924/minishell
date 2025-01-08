/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:32 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/25 19:50:33 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int get_signal_code = 0;

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    (void)env;
    t_data minishell_data;

    while (1)
    {
        input_handle(&minishell_data);
    }
    return (0);
}
