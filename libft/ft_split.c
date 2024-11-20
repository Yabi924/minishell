/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:10:29 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/06/24 17:10:30 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_substr(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 1;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (s[i + 1] != c)
				count++;
		}
		i++;
	}
	if (s[0] == c)
		count--;
	if (s[i - 1] == c)
		count--;
	return (count);
}

size_t	str_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

void	putstr(char *dest, char const *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	count = count_substr(s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	while (i < ft_strlen(s) && j < count)
	{
		while (s[i] == c)
			i++;
		str[j] = (char *)malloc((str_len(s + i, c) + 1) * sizeof(char));
		if (!str[j])
			return (NULL);
		putstr(str[j++], s + i, str_len(s + i, c));
		i = i + str_len(s + i, c);
	}
	str[j] = NULL;
	return (str);
}
