/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:40:04 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/14 14:54:30 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	while (arr[++i])
		free(arr[i]);
	if (arr)
		free(arr);
	arr = NULL;
}

void	free_linked_list(t_list **list)
{
	t_list	*temp;
	t_list	*p;

	if (!list || !(*list))
		return ;
	p = *list;
	while (p)
	{
		temp = p->next;
		ft_lstdelone(p, &free_arr);
		p = temp;
	}
	*list = NULL;
}

void	free_data(t_data *data)
{
	free_arr(data->command_arr);
	if (ft_lstsize(data->list) == 1)
	{
		ft_lstdelone(data->list, &free_arr);
		data->list = NULL;
	}
	else
		free_linked_list(&data->list);
}
