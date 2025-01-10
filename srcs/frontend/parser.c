/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:55:18 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/10 20:32:07 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    parser(t_data *data)
{
    add_space(data);
    // ft_printf("%s\n", data->new_input);
    tokenization(data, &data->list);
    // pll(data->list);
}