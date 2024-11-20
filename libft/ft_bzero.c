/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:44:50 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/06/24 18:51:11 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ch;

	if (n == 0)
		return ;
	ch = (unsigned char *)s;
	while (n-- > 0)
		*ch++ = 0;
}
/*
int main()
{
	char n[10] = "abcabcabc";
	int i = 0;

	ft_bzero(n, 5);

	while (i != 10)
	{
		if (n[i] == 0)
			printf("\\0");
		else
			printf("%c", n[i]);
		i++;
	}
	return(0);
}
*/
