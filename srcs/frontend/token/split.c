/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:12:26 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/14 14:07:19 by yyan-bin         ###   ########.fr       */
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
            i += skip_quotes(s, i + 1, s[i]) + 1 ;
        else if (s[i] == ' ' && s[i + 1] && s[i + 1] != ' ')
        {
            i++;
            count++;
        }
        else
            i++;
    }
    return (count + 1);
}

static char    *copy(char *s, int *p)
{
    int i;
    int j;
    int pp;
    char    *new;

    i = 0;
    j = 0;
    pp = *p;
    while (s[pp + i] && s[pp + i] != ' ')
    {
        if (is_target(s[pp + i], "'\""))
            i += skip_quotes(s, pp + i + 1, s[pp + i]);
        else
            i++;
    }
    new = ft_calloc(i + 1, sizeof(char));
    while (j < i)
    {
        if (is_target(s[pp], "'\""))
            pp++;
        new[j++] = s[pp++];
    }
    *p = pp;
    return (new);
}

static char    *copy_quotes2(char *s, int *p, char target)
{
    int     i;
    int     pp;
    char    *new;

    i = 0;
    pp = *p;
    new = ft_calloc(ft_strlen(s) - 1, sizeof(char));
    while (s[pp++])
    {
        if (s[pp] == target)
            break ;
        new[i++] = s[pp];
    }
    *p = pp + 1;
    return (new);
}

char    **split(char *s)
{
    int i;
    int j;
    char    **arr;

    i = 0;
    j = 0;
    int counts = count(s);
    arr = ft_calloc(counts + 1, sizeof(char *));
    while (s[i])
    {
        while (s[i] == ' ')
            i++;
        if (is_target(s[i], "'\""))
            arr[j++] = copy_quotes2(s, &i, s[i]);
        else if (s[i])
            arr[j++] = copy(s, &i);
    }
    arr[j] = NULL;
    return (arr);
}
