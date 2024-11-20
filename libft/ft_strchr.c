/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:53:46 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/06/23 14:50:12 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
/*
int main() {
    const char testStr[30] = "Hello, world!";
    char ch = 'o';
    char *result = ft_strchr(testStr, ch);

    if (result) {
        printf("Character '%c' found at position: %td\n", ch, result - testStr);
    } else {
        printf("Character '%c' not found.\n", ch);
    }

    return 0;
}
*/
