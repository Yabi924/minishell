/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:58:54 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/12 15:07:34 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// char    *copy_env(char *env, int len)
// {
//     int     i;
//     char *temp;

//     i = -1;
//     temp = ft_calloc(len + 1, sizeof(char));
//     while (env[++i])
//         temp[i] = env[i];
//     return (temp);
// }

int explan(char **new, char *s, int p, char **env)
{
    int         i;
    int         j;
    char    *temp;

    i = 0;
    j = -1;
    while (s[p + i] && s[p + i] != ' ' && s[p + i] != '$' && s[p + i] != '"')
        i++;
    while (env[++j])
    {
        if (is_env(s + p, env[j]))
        {
            temp = ft_strdup(env[j] + i + 1);
            *new = ft_strjoin_free(*new, temp);
            if (temp)
                free(temp);
            break ;
        }
    }
    return (i + 1);
}

int copy(char **new, char *s, int p)
{
    int i;
    int j;
    char *temp;

    i = 0;
    j = 0;
    if (s[p + i] == '$')
        i = 1;
    else
        while (s[p + i] && s[p + i] != '$' && s[p + i] != '\'')
            i++;
    temp = ft_calloc(i + 1, sizeof(char));
    while (j < i)
    {
        temp[j] = s[p + j];
        j++;
    }
    *new = ft_strjoin_free(*new, temp);
    if (temp)
        free(temp);
    return (i);
}

char    *explan_dollar_sign(char *s, char **env)
{
    int i;
    char    *new;

    i = 0;
    new = ft_calloc(calculate_len(s, env) + 1, sizeof(char));
    while (s[i])
    {
        if (s[i] == '\'')
        {
            i += copy_quotes(&new, s, i, '\'');
        }
        else if (s[i] == '$' && s[i + 1] && s[i + 1] != ' ')
            i += explan(&new, s, i + 1, env);
        else
            i += copy(&new, s, i);
    }
    if (s)
        free(s);
    return (new);
}