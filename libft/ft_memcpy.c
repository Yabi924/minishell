/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:51:43 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/06/08 02:51:58 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*cpy;
	const char		*ori;

	cpy = (unsigned char *)dest;
	ori = (const char *)src;
	if (!cpy && !ori)
		return (NULL);
	while (n--)
		*cpy++ = *ori++;
	return (dest);
}
/*
int main()
{
	char dest[10];
	char src[10] = "abc123xyz";

	ft_memcpy(dest, src, 4);

	printf("%s\n", dest);
	return 0;
}
*/
