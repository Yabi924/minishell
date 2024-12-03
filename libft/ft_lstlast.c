/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:46:47 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/03 17:46:48 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
int main()
{
    t_list *node1 = ft_lstnew("omg");
    t_list *node2 = ft_lstnew("is");
    t_list *node3 = ft_lstnew("xxxxx");

    ft_lstadd_front(&node3, node2);
    ft_lstadd_front(&node2, node1);

    t_list *last = ft_lstlast(node1);
    printf("%s\n", (char *)last->content);
    
    return 0;
}
*/
