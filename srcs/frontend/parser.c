/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:55:18 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/18 12:11:44 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_split(t_data *data)
{
	data->split.temp = NULL;
	data->split.i = 0;
	data->split.j = 0;
	data->split.end = 0;
}

void	reset_split(t_split *split)
{
	if (split->temp)
	{
		free(split->temp);
		split->temp = NULL;
	}
	split->end = 0;
	split->i = 0;
	split->j = 0;
}

void	parser(t_data *data)
{
	add_space(data);
	if (ft_strchr(data->new_input, '$'))
		dollar_sign(data);
	init_split(data);
	data->command_arr = split(&data->split, data->new_input);
	reset_split(&data->split);
	// print_arr(data->command_arr);
	tokenization(data, &data->list);
}
