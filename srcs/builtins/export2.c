/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:41:18 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/25 11:41:20 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
 
void    arrange_env(char **env, int size)
{
    char    *temp;
    int     i;
    int     j;

    i = -1;
    while (++i < size)
    {
        j = -1;
        while (++j < (size - 1) - i)
        {
            if (ft_strncmp(env[j], env[j + 1], BUFFER) > 0)
            {
                temp = env[j];
                env[j] = env[j + 1];
                env[j + 1] = temp;
            }
        }
    }
}

int	ft_strpos(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	if (*needle == '\0' || needle == NULL)
		return (0);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == '\0')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}