/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:46:41 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/20 17:10:12 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(t_list *))
{
	if (lst && del)
	{
		del(lst);
		free(lst);
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
    t_list *node1 = ft_lstnew(strdup("omg"));
    
    printf("%s\n", (char *)node1->content);

    ft_lstdelone(node1, del);
    if (!node1)
        printf("nothing");
    else
        printf("ehhh");
    return 0;
}
*/
