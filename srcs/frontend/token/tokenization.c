/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:51:20 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/17 18:26:03 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	tokenization(t_data *data, t_list **list)
{
	int		i;
	int		j;
	char	**temp;

	i = -1;
	j = -1;
	temp = malloc((ft_arrlen(data->command_arr) + 1) * sizeof(char *));
	while (data->command_arr[++i])
	{
		if (!ft_strncmp(data->command_arr[i], "|\0", 2))
		{
			temp[++j] = NULL;
			ft_lstadd_back(list, ft_lstnew(temp));
			temp = malloc((ft_arrlen(data->command_arr) + 1) * sizeof(char *));
			j = -1;
		}
		else
			temp[++j] = ft_strdup(data->command_arr[i]);
	}
	temp[++j] = NULL;
	ft_lstadd_back(list, ft_lstnew(temp));
}
