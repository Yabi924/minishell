/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:44 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/14 14:58:28 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	input_handle(t_data *data, t_list *list)
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
        parser(data, list);
        if (redirection(data, list))
           ft_execute(data, list); //Function that will execute the command
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &data->ori_terminal);
    free_lst(data, &list);
    return (0);
}