/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:40:04 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/22 08:18:50 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	if (!arr || !arr[0])
		return ;
	while (arr[++i])
	{
		if (arr[i])
			free(arr[i]);
	}
	if (arr)
		free(arr);
	arr = NULL;
}

void	free_linked_list_item(t_list *lst)
{
	if (lst->command)
	{
		free_arr(lst->command);
		lst->command = NULL;
	}
	if (lst->delimiter)
	{
		free(lst->delimiter);
		lst->delimiter = NULL;
	}
	if (lst->in_path)
	{
		free(lst->in_path);
		lst->in_path = NULL;
	}
	if (lst->out_path)
	{
		free(lst->out_path);
		lst->out_path = NULL;
	}
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
		ft_lstdelone(p, &free_linked_list_item);
		p = temp;
	}
	*list = NULL;
}

void	free_data(t_data *data)
{
	free_arr(data->command_arr);
	if (data->input)
	{
		free(data->input);
		data->input = NULL;
	}
	if (data->new_input)
	{
		free(data->new_input);
		data->new_input = NULL;
	}
	if (ft_lstsize(data->list) == 1)
	{
		ft_lstdelone(data->list, &free_linked_list_item);
		data->list = NULL;
	}
	else
		free_linked_list(&data->list);
}
/*
	if (!lst->command && !lst->delimiter && !lst->in_path && !lst->out_path)
		ft_printf("debug free linked list complete\n");
*/
