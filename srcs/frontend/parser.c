/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:55:18 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/14 14:55:46 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void    print_arr(char **s)
// {
//     int i = -1;
//     while (s[++i])
//         printf("i:%d str:%s\n", i + 1, s[i]);
// }

// void    pll(t_list *list)
// {
//     int i = 0;

//     while (list)
//     {
//         printf("\nlinked list:%d\n", i++);
//         print_arr(list->command);
//         list = list->next;
//     }
// }

void	parser(t_data *data)
{
	add_space(data);
	if (ft_strchr(data->new_input, '$'))
		dollar_sign(data);
	tokenization(data, &data->list);
	// pll(data->list);
}