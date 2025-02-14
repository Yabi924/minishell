/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:43:46 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/14 15:34:46 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	quotes_len(char *s)
{
	int	i;
	int	len;
	int	temp;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '\'')
		{
			temp = skip_quotes(s, i + 1, '\'') + 1;
			len += temp;
			i += temp;
		}
		else
			i++;
	}
	return (len);
}

int	is_env(char *s, char *env)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] && s[i] != ' ' && !is_target(s[i], "'\"") && s[i] != '$')
		i++;
	while (env[j] && env[j] != '=')
		j++;
	while (s[k] && env[k] && s[k] == env[k] && (s[k] != ' ' || \
		!is_target(s[k], "'\"")))
		k++;
	if (env[k] == '=' && k == i)
		return (1);
	return (0);
}

static int	find_env_length(char *s, int p, char **env, int *step)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	if (!s || !env || p < 0)
		return (0);
	while (s[p + i] && s[p + i] != ' ' && s[p + i] != '$' && s[p + i] != '"')
		i++;
	*step = i;
	while (env[++j])
		if (env[j] && is_env(s + p, env[j]))
			return (ft_strlen(env[j]) - i - 1);
	return (0);
}

int	calculate_len(char *s, char **env)
{
	int	i;
	int	len;
	int	step;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			i += skip_quotes(s, i + 1, '\'') + 1;
		else if (s[i] == '$' && s[i + 1] && s[i + 1] != ' ')
		{
			len += find_env_length(s, i + 1, env, &step);
			i += step + 1;
		}
		else
		{
			i++;
			len++;
		}
	}
	return (len + quotes_len(s));
}
