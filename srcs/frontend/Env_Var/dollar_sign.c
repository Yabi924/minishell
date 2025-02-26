/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:58:54 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/26 23:14:10 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	init_dollar(t_data *data)
{
	data->dollar.env = copy_env(data->env, 0);
	data->dollar.input = ft_strdup(data->new_input);
	data->dollar.new = ft_calloc(1, 1);
	if (data->first_run_init_dollar)
		return ;
	data->first_run_init_dollar = 1;
	data->dollar.temp = NULL;
	data->dollar.i = 0;
	data->dollar.j = -1;
	data->dollar.quotes = 0;
}

void	free_dollar(t_dollar *dollar)
{
	if (dollar->env)
	{
		free_arr(dollar->env);
		dollar->env = NULL;
	}
	if (dollar->input)
	{
		free(dollar->input);
		dollar->input = NULL;
	}
	if (dollar->new)
	{
		free(dollar->new);
		dollar->new = NULL;
	}
	dollar->temp = NULL;
	dollar->i = 0;
	dollar->j = -1;
	dollar->quotes = 0;
}

void	explan(t_dollar *d, int j)
{
	int	i;

	i = 0;
	d->i++;
	if (d->quotes)
		while (d->input[d->i + i] && d->input[d->i + i] != ' ' && \
			d->input[d->i + i] != '"' && d->input[d->i + i] != '$' && \
			d->input[d->i + i] != '\'')
			i++;
	else
		while (d->input[d->i + i] && d->input[d->i + i] != ' ' && \
			d->input[d->i + i] != '"' && d->input[d->i + i] != '$')
			i++;
	while (d->env[++j])
	{
		if (is_env(d->input + d->i, d->env[j]))
		{
			d->temp = ft_strdup(d->env[j] + i + 1);
			d->new = ft_strjoin_free(d->new, d->temp);
			if (d->temp)
				free(d->temp);
			break ;
		}
	}
	d->i += i;
}

void	explan_dollar_sign(t_dollar *d)
{
	while (d->input[d->i])
	{
		if (d->input[d->i] && d->input[d->i] == '"')
			d->quotes++;
		if ((d->input[d->i] && d->input[d->i] == '$') && \
			(d->input[d->i + 1] && d->input[d->i + 1] != ' '))
			explan(d, d->j);
		else if (d->input[d->i] && d->input[d->i] == '\'' && !d->quotes)
			d->i += copy_quotes(&d->new, d->input, d->i, '\'');
		else
		{
			d->temp = ft_substr(d->input, d->i++, 1);
			d->new = ft_strjoin_free(d->new, d->temp);
			if (d->temp)
			{
				free(d->temp);
				d->temp = NULL;
			}
			if (d->quotes == 2)
				d->quotes = 0;
		}
	}
}

void	dollar_sign(t_data *data)
{
	init_dollar(data);
	explan_dollar_sign(&data->dollar);
	if (data->new_input)
		free(data->new_input);
	data->new_input = ft_strdup(data->dollar.new);
	free_dollar(&data->dollar);
}
