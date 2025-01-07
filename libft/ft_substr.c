/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:42:05 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/26 23:01:01 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(const char *s, unsigned int start, size_t len)
{
	int	actual_len;

	if (!s)
		return (0);
	if (ft_strlen(s) - start < len)
		actual_len = ft_strlen(s) - start;
	else
		actual_len = len;
	return (actual_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		actual_len;
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	actual_len = count(s, start, len);
	str = (char *)malloc(sizeof(char) * (actual_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, actual_len + 1);
	return (str);
}
/*
int main()
{
	char *s = "1234 abcd";
	printf("%s\n", ft_substr(s, 6, 5));
	return 0;
}
*/
