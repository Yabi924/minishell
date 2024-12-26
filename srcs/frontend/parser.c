/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:55:18 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/27 04:19:23 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int copy_quotes(t_data *data, int position, char target)
{
    int     i;
    int     len;
    char    *temp;

    i = 0;
    len = skip_quotes(data->input, position + 1, target) + 1;
    temp = ft_calloc(len + 1, sizeof(char));
    while (data->input[position + i])
    {
        temp[i] = data->input[position + i];
        if (data->new_input[position + i] == target)
            break ;
        i++;
    }
    data->new_input = ft_strjoin_free(data->new_input, temp);
    free(temp);
    return (len);
}

static int count_len(char *s, int p)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[p + i] && !is_target(s[p + i], "\'\""))
    {
        if (s[p + i] && \
            (s[p + i] == '|' || s[p + i] == '<' || s[p + i] == '>'))
        {
            if (s[p + i] && s[p + i - 1] != ' ')
                count++;
            if (s[p + i] && s[p + i + 1] != ' ')
                count++;
        }
        i++;
    }
    return (i + count);
}

int copy_wold(t_data *data, int p)
{
    int     len;
    int     i;
    int     j;
    char    *temp;

    len = count_len(data->input, p);
    temp = ft_calloc(len + 1, sizeof(char));
    i = 0;
    j = 0;
    while (data->input[p + i] && !is_target(data->input[p + i], "'\""))
    {
        if (data->input[p + i + 1] && data->input[p + i] && \
            data->input[p + i - 1] != ' ' && is_target(data->input[p + i], "<>|"))
            temp[j++] = ' ';
        else if (data->input[p + i - 1] && data->input[p + i] && \
            data->input[p + i] != ' ' && is_target(data->input[p + i - 1], "<>|"))
            temp[j++] = ' ';
        temp[j++] = data->input[p + i++];
    }
    data->new_input = ft_strjoin_free(data->new_input, temp);
    free(temp);
    return (i);
}

void    split(t_data *data)
{
    int     i;

    i = 0;
    // ft_printf("%d\n", word_count);
    data->new_input = ft_calloc(2, sizeof(char));
    while (data->input[i])
    {
        if (data->input[i] == '"' || data->input[i] == '\'')
            i += copy_quotes(data, i, data->input[i]);
        else
            i += copy_wold(data, i);
    }
}

void    parser(t_data *data)
{
    split(data);
    ft_printf("%s\n", data->new_input);
}
