/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:44 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/27 01:17:44 by yyan-bin         ###   ########.fr       */
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
        return (1);
    }
    else
    {
        ft_printf("hi\n");
        parser(data);
    }
    return (0);
}

// void    ft_split_input(t_token *token, char *src_input)
// {
//     int i;
//     int j;
//     char    *input;

//     if (!src_input)
//     {
//         printf("error from ft_split_input\n");//debug message
//         return ;
//     }
//     input = copy_input(src_input);
//     i = 0;
//     j = 0;
//     while (input[i] && i != -1)
//     {
//         j = i;
//         while (input[i] && input[i] != ' ')
//             i++;
//         if (input[i] == '"')
//             i = ft_quotes(i, input);
//         if (i == -1)
//             error_message(&token);//to do
//         token->string = ft_substr(input, j, i++ - j);
//         // classification_type(&token);//to do
//     }
// }
