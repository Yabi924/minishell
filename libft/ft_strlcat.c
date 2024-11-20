/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 08:48:11 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/06/23 16:17:46 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (dest == NULL && n == 0)
		return (srclen);
	destlen = ft_strlen(dest);
	if (n == 0 || destlen > n)
		return (srclen + n);
	if (destlen < n - 1 && n > 0)
	{
		while (src[i] && destlen < n - 1)
			dest[destlen++] = src[i++];
		dest[destlen] = '\0';
	}
	i--;
	while (src[++i] != '\0')
		destlen++;
	return (destlen);
}
