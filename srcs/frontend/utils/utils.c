/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:57 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/25 19:54:07 by yyan-bin         ###   ########.fr       */
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
