/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:52:25 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/06/08 14:11:57 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t		i;
	char		*cpy;
	const char	*ori;

	i = 0;
	cpy = (char *)dest;
	ori = (const char *)src;
	if (!cpy && !ori)
		return (NULL);
	if (cpy < ori)
	{
		while (i < len)
		{
			cpy[i] = ori[i];
			i++;
		}
	}
	else
	{
		while (len--)
		{
			cpy[len] = ori[len];
		}
	}
	return (dest);
}

/*
int main()
{
    char ori[10] = "abcdwxyz";
    char dest[10] = "12345678";
    
    ft_memmove(dest, ori, 2);
    printf("%s\n", dest);
    
    ft_memmove(dest+4, ori, 2);
    printf("%s\n", dest);
    
    ft_memmove(dest+6, ori, 2);
    printf("%s\n", dest);
    return 0;
}
*/
