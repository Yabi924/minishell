/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:46:00 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/03 17:46:22 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (lst && del)
	{
		while (*lst)
		{
			ptr = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = ptr;
		}
		*lst = NULL;
	}
}

/*
#include <string.h>
void del(void *content)
{
    free(content);
}

int main()
{
    t_list *head = ft_lstnew(strdup("Hello"));
    ft_lstadd_back(&head, ft_lstnew(strdup("World")));

    if (head)
        printf("%s,%s\n", (char *)head->content, 
	(char *)head->next->content);        
    else
        printf("nothing\n");
    
    ft_lstclear(&head, del);

    if (head)
        printf("%s,%s\n", (char *)head->content, 
	(char *)head->next->content);        
    else
        printf("nothing\n");
    return 0;
} 
*/
