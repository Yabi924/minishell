/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:46:44 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/03 17:46:46 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
void ftprint(void *lst)
{
    printf("%s\n", (char *)lst);
}

int main()
{
    t_list *node = ft_lstnew("hello");
    ft_lstadd_back(&node, ft_lstnew("good"));
    ft_lstadd_back(&node, ft_lstnew("morning"));
    ft_lstadd_back(&node, ft_lstnew("girl"));

    ft_lstiter(node, &ftprint);
    // printf("%s %s\n", (char *)node->content, (char *)node->next->content);
    return 0;
}
*/
