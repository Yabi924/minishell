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

/*
	Idriss test case
*/
/*
void	free_data(t_data *data)
{
	free_arr(data->command_arr);
    free(data->input);
    free(data->new_input);
	if (ft_lstsize(data->list) == 1)
	{
		ft_lstdelone(data->list, &free_arr);
		data->list = NULL;
	}
	else
		free_linked_list(&data->list);

}
*/

/*
	Idriss test case:
*/
void	free_lst(t_data *mshell, t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp_next;

	if (!mshell->flag || !lst || !(*lst))
		return ;
	tmp = *lst;
	tmp_next = NULL;
	while (tmp)
	{
		tmp_next = tmp->next;
		free_arr(tmp->command);
		if (tmp->in_path)
			free(tmp->in_path);
		if (tmp->out_path)
			free(tmp->out_path);
		if (tmp->delimiter)
			free(tmp->delimiter);
		free(tmp);
		tmp = tmp_next;
	}
	*lst = tmp;
	*lst = NULL;
	if (mshell->flag)
		mshell->flag = 0;
}
