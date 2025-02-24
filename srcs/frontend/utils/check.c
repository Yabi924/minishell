/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:27:01 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/14 15:15:34 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	check_quotes(char *s)
{
	int	i;
	int status;

	i = -1;
	status = 0;
	while (s[++i])
	{
		if (s[i] == '"' && status == 0)
			status = 1;
		else if (s[i] == '"' && status == 1)
			status = 0;
		else if (s[i] == '\'' && status == 0)
			status = 2;
		else if (s[i] == '\'' && status == 2)
			status = 0;
	}
	if (!status)
		return (0);
	return (1);
}

int	check_redrct_pipe(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '|' || s[i] == '<' || s[i] == '>')
			return (1);
	}
	return (0);
}
