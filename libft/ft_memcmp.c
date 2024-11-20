/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:00:31 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/06/08 16:31:42 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	const unsigned char	*ss;

	i = 0;
	s = s1;
	ss = s2;
	while (i < n)
	{
		if (s[i] != ss[i])
			return (s[i] - ss[i]);
		i++;
	}
	return (0);
}
/*
int	main()
{
	char s1[10] = "123456789";
	char s2[10] = "123456689";

	printf("%d\n", ft_memcmp(s1, s2, 10));
	return (0);
}
*/
