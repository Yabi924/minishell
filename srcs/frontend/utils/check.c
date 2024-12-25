/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:27:01 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/25 21:57:08 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int check_quotes(char *s)
{
    int i;
    int count;
    int count2;

    i = -1;
    count = 0;
    count2 = 0;
    while (s[++i])
    {
        if (s[i] && s[i] == '"' && (i == 0 || s[i - 1] != '\\'))
            count++;
        if (s[i] && s[i] == '\'' && (i == 0 ||s[i - 1] != '\\'))
            count2++;
    }
    if (count % 2 != 0 || count2 % 2 != 0)
        return (1);
    return (0);
}

int check_pipe(char *s)
{
    int i;
    int j;
    int a;

    i = -1;
    j = 0;
    if (s[0] && s[0] == '|')
        return (1);
    while (s[++i])
    {
        if (s[i] && s[i] == '|')
        {
            if (s[i] && s[i + 1] == '|')
                return (1);
            j = i;
        }
    }
    while (!s[j + 1])
    {
        return (1);
    }
    return (0);
}
