/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:04:18 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/02 21:49:24 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int copy_quotes(t_data *data, int position, char target)
{
    int     i;
    int     len;
    char    *temp;
    int     q;

    i = 0;
    q = 0;
    len = skip_quotes(data->input, position + 1, target) + 1;
    temp = ft_calloc(len + 1, sizeof(char));
    while (data->input[position + i] && q != 2)
    {
        temp[i] = data->input[position + i];
        if (data->input[position + i] == target)
            q++ ;
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
            if (s[p + i] && (s[p + i - 1] != ' ' && s[p + i - 1] != '<' \
                && s[p + i - 1] != '>'))
                count++;
            if (s[p + i] && (s[p + i + 1] != ' ' && s[p + i + 1] != '<') \
                && s[p + i + 1] != '>')
                count++;
        }
        i++;
    }
    return (i + count);
}

void copy_wold_help(char *s, char *temp, int p, int *j)
{
    if (s[p - 1] && s[p - 1] != ' ' && !is_target(s[p - 1], "<>"))
        temp[(*j)++] = ' ';
    temp[(*j)++] = s[p];
    if (s[p + 1] && s[p + 1] != ' ' && !is_target(s[p + 1], "<>"))
        temp[(*j)++] = ' ';
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
        if (is_target(data->input[p + i], "<>|"))
            copy_wold_help(data->input, temp, p + i++, &j);
        else
            temp[j++] = data->input[p + i++];
            
    }
    data->new_input = ft_strjoin_free(data->new_input, temp);
    free(temp);
    return (i);
}

void    add_space(t_data *data)
{
    int     i;

    i = 0;
    data->new_input = ft_calloc(1, sizeof(char));
    while (data->input[i])
    {
        if (data->input[i] == '"' || data->input[i] == '\'')
            i += copy_quotes(data, i, data->input[i]);
        else
            i += copy_wold(data, i);
        // printf("sp: %s$\n", data->new_input);
    }
}
