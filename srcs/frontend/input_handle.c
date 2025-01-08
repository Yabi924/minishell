/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:44 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/08 20:36:00 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int input_handle(t_data *data, t_list **list)
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
        // ft_printf("hi\n");
        parser(data, list);
        
    }
    return (0);
}
