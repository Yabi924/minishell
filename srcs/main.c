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

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    // (void)env;
    t_data minishell_data;
    minishell_data.list = NULL;

    while (1)
    {
        input_handle(&minishell_data, env);
    }
    return (0);
}

void    print_arr(char **s)
{
    int i = -1;
    while (s[++i])
        printf("i:%d str:%s\n", i + 1, s[i]);
}

void    pll(t_list *list)
{
    int i = 0;

    while (list)
    {
        printf("\nlinked list:%d\n", i++);
        print_arr(list->command);
        list = list->next;
    }
}