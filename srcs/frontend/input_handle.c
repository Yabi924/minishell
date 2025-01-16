/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:44 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/16 21:40:36 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void    exe(t_data *data)
// {
//     if (!ft_strncmp(data->list->command[0], "unset\0", 6))
//         unset(data, data->list, data->env);
//     else if (!ft_strncmp(data->list->command[0], "env\0", 4))
//         env(data);
//     else if (!ft_strncmp(data->list->command[0], "export\0", 7))
//         export(data, data->list);
//     else
//         printf("other\n");
// }

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
        parser(data);
        exec(data); //Function that will execute the command
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &data->ori_terminal);
    free_data(data);
    return (0);
}
