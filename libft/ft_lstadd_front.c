/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:45:57 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/03 17:46:22 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

/*
int main()
{
    int v1 = 1;
    int v2 = 2;


    t_list *node1 = ft_lstnew(&v1);
    ft_lstadd_front(&node1, ft_lstnew(&v2));
    printf("%d, %d\n", *(int *)node1->content, *(int *)node1->next->content);
    return 0;
}
*/
