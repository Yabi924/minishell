/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:13:47 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/06/23 12:57:32 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	str = (char *)malloc(i + 1);
	if (str == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = '\0';
	return ((char *)str);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *s1 = "abcd";
    char *s2;
    s2 = ft_strdup(s1);

    printf("%s\n", s2);
	if (s2)
		free(s2);
    return 0;
}
*/
