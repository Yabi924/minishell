/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:55:18 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/02 14:07:08 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void    split(t_data *data)
// {
    
// }

void    parser(t_data *data)
{
    add_space(data);
    // split(data);
    ft_printf("%s\n", data->new_input);
    // tokenization(data);
}
