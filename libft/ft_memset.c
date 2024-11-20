/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:53:03 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/06/08 02:53:07 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*i;

	i = b;
	while (len != 0)
	{
		*i = (unsigned char)c;
		len--;
		i++;
	}
	return (b);
}
/*
int main()
{
    char n[20] = "abcdefg";
    ft_memset(n, 'a', 3);
    printf("%s\n", n);
	return 0;
}
*/
