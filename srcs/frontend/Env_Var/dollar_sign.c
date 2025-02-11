/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:58:54 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/11 17:53:23 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void init_dollar(t_data *data)
{
    if (data->dollar.f)
        return ;
    data->dollar.env = data->env;
    data->dollar.input = data->new_input;
    data->dollar.new = NULL;
    data->dollar.temp = NULL;
    data->dollar.f = 1;
    data->dollar.i = 0;
    data->dollar.j = 0;
}

void    free_dollar(t_dollar *dollar)
{
    if (dollar->env)
        dollar->env = NULL;
    if (dollar->input)
        dollar->input = NULL;
    if (dollar->new)
        free(dollar->new);
    if (dollar->temp)
        free(dollar->temp);
    dollar->i = 0;
    dollar->j = 0;
    dollar->quotes = 0;
}

void    explan(t_dollar *d)
{
    int i;
    int j;
    char    *temp;

    i = 0;
    j = -1;
    d->i++;
    while (d->input[d->i + i] && d->input[d->i + i] != ' ' && \
        d->input[d->i + i] != '"' && d->input[d->i + i] != '$')
        i++;
    while (d->env[++j])
    {
        if (is_env(d->input[d->i], d->env[j]))
        {
            temp = ft_strdup(d->env + i + 1);
            d->new = ft_strjoin_free(d->new, temp);
            d->i += i;
            break ;
        }
    }
}

void    explan_dollar_sign(t_dollar *d)
{
    while (d->input[d->i])
    {
        if (d->input[d->i] && d->input[d->i] == '"')
            d->quotes = 1;
        if ((d->input[d->i] && d->input[d->i] == '$') && \
            (d->input[d->i + 1] && d->input[d->i + 1] != ' '))
            explan(d);
    }
}

void    dollar_sign(t_data *data)
{
    init_dollar(data);
    explan_dollar_sign(&data->dollar);
    free_dollar(&data->dollar);
}
