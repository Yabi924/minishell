/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:51:20 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/07 19:05:55 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int count(char *s)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i])
    {
        if (is_target(s[i], "'\""))
        {
            i += skip_quotes(s, i + 1, s[i]);
            printf("i:%d\n", i);
        }
        if (s[i] == ' ' && s[i + 1] && s[i + 1] != ' ')
            count++;
        i++;
    }
    return (count);
}

static char    *copy(char *s, int p)
{
    int i;
    int j;

    i = 0;
    while (s[p + i] != ' ')
    {
        if (is_target(s[p + i], "'\""))
                i += skip_quotes(s, p + i + 1, s[p + i]);
        i++;
    
    }
}

char    **split(char *s)
{
    int i;
    int k;
    // char    **arr;

    i = 0;
    k = 0;
    // arr = ft_calloc(count(s) + 1, sizeof(char *));
    while (s[i])
    {
        if (s[i] != ' ')
        {
            
        }
        // arr[k] = ft_calloc(j + 1, sizeof(char));
        // ft_strlcpy(arr[k++], s + i, j);
        while (s[i] == ' ')
            i++;
    }
    return NULL;
}
