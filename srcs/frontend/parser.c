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

void	parser(t_data *data, t_list *list)
{
	add_space(data);
	if (ft_strchr(data->new_input, '$'))
		dollar_sign(data);
	tokenization(data, &list);
}
