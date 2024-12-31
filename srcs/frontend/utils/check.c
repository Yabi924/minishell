/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:27:01 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/27 01:21:05 by yyan-bin         ###   ########.fr       */
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

int check_redrct_pipe(char *s)
{
    int i;

    i = -1;
    while (s[++i])
    {
        if (s[i] == '|' || s[i] == '<' || s[i] == '>')
            return (1);
    }
    return (0);
}