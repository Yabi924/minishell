/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:44 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/12 20:22:17 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int input_handle(t_data *data)
{
    print_prompt(data);
    skip_unprint(data);
    if (lexer(data->input))
    {
        ft_putstr_fd("Syntax error\n", 2);
        return (1);
    }
    else
    {
        // free(data->env); // Free existing environment
        //init(data, env);
        parser(data);
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &data->ori_terminal);
    free_data(data);
    return (0);
}
