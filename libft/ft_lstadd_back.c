/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:45:52 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/03 17:46:22 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

/*
#include "string.h"
int main()
{
    t_list *node1 = NULL;
    t_list *node2 = ft_lstnew(strdup("is"));
    t_list *node3 = ft_lstnew(strdup("xxxxx"));

    ft_lstadd_back(&node1, node2);
    ft_lstadd_back(&node1, node3);

    printf("%s,%s\n", (char *)node1->content, (char *)node1->next->content);
  
    return 0;
}
*/
