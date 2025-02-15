/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:57:06 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/14 15:20:14 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	skip_quotes(char *s, int positoin, char target)
{
	int	i;

	i = 0;
	if (!s || positoin < 0)
		return (0);
	while (s[positoin + i] && s[positoin + i] != target)
		i++;
	return (i + 1);
}

int	check_pipe_help_help(char *s, int pipe, int pipe2)
{
	if (!s[pipe] || !s[pipe2])
		return (1);
	while (pipe < pipe2)
	{
		if (s[pipe] && (s[pipe] >= '!' && s[pipe] <= '~'))
			return (0);
		pipe++;
	}
	return (1);
}

int	check_pipe_help(char *s, int pipe)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	if (!s[pipe] || (s[pipe] && s[pipe] == '|'))
		return (1);
	while (s[pipe + i])
	{
		if (s[pipe + i] == '|')
			return (check_pipe_help_help(s, pipe, pipe + i));
		if (s[pipe + i] && (s[pipe + i] >= '!' && s[pipe + i] <= '~'))
			f = 1;
		i++;
	}
	if (f == 1)
		return (0);
	return (1);
}

int	check_pipe(char *s)
{
	int	i;

	i = -1;
	if (s[0] && s[0] == '|')
		return (1);
	while (s[++i])
	{
		if (s[i] == '"' || s[i] == '\'')
			i += skip_quotes(s, i + 1, s[i]);
		if (s[i] && s[i] == '|')
			if (check_pipe_help(s, i + 1))
				return (1);
	}
	return (0);
}
