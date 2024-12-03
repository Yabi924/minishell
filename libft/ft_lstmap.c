/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:46:50 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/03 17:46:51 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;

	new_node = NULL;
	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
#include <string.h>
void *f(void *lst)
{
    char *str = strdup((char *)lst);
    int i = 0;

    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    return ((void *)str);
}

void ft_del(void *lst)
{
    free(lst);
}

void ftprint(void *lst)
{
    printf("%s\n", (char *)lst);
}

int main()
{
    t_list *node = ft_lstnew(strdup("hello"));
    ft_lstadd_back(&node, ft_lstnew(strdup("good")));
    ft_lstadd_back(&node, ft_lstnew(strdup("hell!")));

    t_list *new = ft_lstmap(node, &f, &ft_del);
    if (!new)
        printf("gg\n");
    ft_lstiter(new, &ftprint);
    ft_lstclear(&new, &ft_del);
    ft_lstclear(&node, &ft_del);

    return 0;
}
*/
