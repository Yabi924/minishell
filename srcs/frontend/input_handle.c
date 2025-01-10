/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:44 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/11 00:40:20 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int input_handle(t_data *data)
{
    print_prompt(data);
    skip_unprint(data);
    // ft_printf("%s\n", data->input);
    if (lexer(data->input))
    {
        //free data
        ft_putstr_fd("Syntax error\n", 2);
        //set exit code
        return (1);
    }
    else
    {
        //init(data, env);
        parser(data);
    }
    //free linked list
    return (0);
}
