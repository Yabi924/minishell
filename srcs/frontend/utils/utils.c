/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:57 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/27 03:39:34 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// void    input_handler(const char *input, char **env)
// {
//     (void)env;
//     ft_printf("%s\n", input);
// }

// int ft_quotes(int i, char *str)
// {
//     if (!str[i] || str[i] != '"')
//         return (-1);
//     i++;
//     while (str[i] && str[i] != '"')
//         i++;
//     if (!str[i])
//         return (-1);
//     return (i + 1);
// }

int unprint_index(int i, char *str)
{
    if (!str)
        return (-1);
    while (str[i] && !(str[i] <= '~' && str[i] > ' '))
        i++;
    return (i);
}

void    skip_unprint(t_data *data)
{
    int i;
    char    *copy;

    if (!data->input)
        return ;
    i = unprint_index(0, data->input);
    copy = ft_substr(data->input, i, ft_strlen(data->input));
    free(data->input);
    data->input = ft_strdup(copy);
    free(copy);
}

char    *ft_strjoin_free(char *s1, char *s2)
{
    char    *new;

    if (!s1 || !s2)
        return NULL;
    new = ft_strjoin(s1, s2);
    free(s1);
    return (new);
}

int is_target(char c, char *target)
{
    int i;

    i = -1;
    while (target[++i])
    {
        if (c == target[i])
            return (1);
    }
    return (0);
}
