/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:46:52 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/26 22:38:02 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char **content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->command = content;
	new->append = 0;
	new->delimiter = NULL;
	new->in_path = NULL;
	new->out_path = NULL;
	new->fd[0] = -1;
	new->fd[1] = -1;
	new->next = NULL;
	return (new);
}

/*
int main()
{
    t_list *node = ft_lstnew("wtf");
    printf("%s\n", (char *)node->content);
    return 0;
}
*/
