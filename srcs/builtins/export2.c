/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:41:18 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/26 22:47:55 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
 
void    arrange_env(char **export_env, int size)
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
            if (ft_strncmp(export_env[j], export_env[j + 1], BUFFER) > 0)
            {
                temp = export_env[j];
                export_env[j] = export_env[j + 1];
                export_env[j + 1] = temp;
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