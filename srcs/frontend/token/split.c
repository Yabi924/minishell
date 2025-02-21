/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:12:26 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/20 15:18:53 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	count(char *s)
{
	int	i;
	int	count;

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
	// printf("debug: count>%d\n", count + 1);
	return (count + 1);
}

void	copy(t_split *split, char *input)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	if (is_target(input[split->i], "\""))
	{
		f = 1;
		split->i++;
		while (input[split->i + i] && !is_target(input[split->i + i], "\""))
			i++;
	}
	else
		while (input[split->i + i] && !is_target(input[split->i + i], " \"'"))
			i++;
	if (i != 0)
		split->temp = ft_substr(input, split->i, i);
	split->i += i + f;
}

void	singel_quotes(t_split *split, char *input)
{
	int	i;

	i = 0;
	split->i++;
	while (input[split->i + i] && !is_target(input[split->i + i], "'"))
		i++;
	if (i != 0)
		split->temp = ft_substr(input, split->i, i);
	split->i += i + 1;
}

void	end(t_split *split, char **arr, char *input)
{
	if (!input[split->i] || (input[split->i] == ' ' && \
		input[split->i + 1] != ' '))
		split->end++;
	if (split->temp)
		arr[split->j] = ft_strjoin_free(arr[split->j], split->temp);
	if (split->temp)
		free(split->temp);
	split->temp = NULL;
	if (split->end)
	{
		split->j++;
		split->end = 0;
	}
}

char	**split(t_split *split, char *input)
{
	char	**arr;

	arr = ft_calloc(count(input) + 1, sizeof(char *));
	while (input[split->i])
	{
		if (input[split->i] && input[split->i] == ' ')
			split->i++;
		else if (!is_target(input[split->i], "'"))
			copy(split, input);
		else
			singel_quotes(split, input);
		end(split, arr, input);
	}
	return (arr);
}
