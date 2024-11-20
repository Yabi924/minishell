/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:52:58 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/06/23 12:55:37 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ttllen;
	char	*str;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	ttllen = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(ttllen + 1);
	if (!str)
		return (NULL);
	ptr = str;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (str);
}
/*
int main() {
    char s1[] = "1";
    char s2[] = "2";
    char *result = ft_strjoin(s1, s2);

    if (result)
    {
        printf("Result: %s\n", result);
        free(result);
    }
    else
    {
        printf("Memory allocation failed\n");
    }
    return 0;
}
*/
