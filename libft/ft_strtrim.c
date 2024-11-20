/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:52:01 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/06/23 20:31:29 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(const char *c, const char *check)
{
	while (*check)
	{
		if (*c == *check)
			return (1);
		check++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	size_t		len;
	char		*cpy;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && check(s1 + start, set))
		start++;
	end = ft_strlen(s1);
	while (end > start && check(s1 + (end - 1), set))
		end--;
	len = end - start;
	cpy = (char *)malloc(len + 1);
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s1 + start, len + 1);
	return (cpy);
}
/*
int main()
{
    char str[10] = "12341";
    char set[10] = "1";
    char *trimmed = ft_strtrim(str, set);
    if (trimmed)
    {
        printf("Original: '%s'\n", str);
        printf("Trimmed: '%s'\n", trimmed);
        free(trimmed);
    }
    else
    {
        printf("Trimming failed.\n");
    }

    return 0;
}
*/
