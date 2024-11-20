/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:55:34 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/06/23 14:50:35 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int chr )
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)chr)
			return (str + i);
		i--;
	}
	return (NULL);
}
/*
int main() {
    const char testStr[20] = "Hello, world!";
    char ch = 'o';
    char *result = ft_strrchr(testStr, ch);

    if (result) {
        printf("Character '%c' found at position: %td\n", ch, result - testStr);
    } else {
        printf("Character '%c' not found.\n", ch);
    }

    return 0;
}
*/