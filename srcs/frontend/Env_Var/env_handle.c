/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:55:42 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/26 21:02:33 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	shlvl(char **env, int f)
{
	int	i;

	i = -1;
	if (!f)
		return (1);
	while (env[++i])
		if (is_env("SHLVL", env[i]))
			return (1);
	return (0);
}

char	*copy_env_help(char *env, int f)
{
	char	*temp;
	char	*new_env;

	if (is_env("SHLVL", env) && f)
	{
		temp = ft_itoa(ft_atoi(env + 6) + 1);
		new_env = ft_strjoin("SHLVL=", temp);
		free(temp);
	}
	else
		new_env = ft_strdup(env);
	return (new_env);
}

char	**copy_env(char **env, int f)
{
	int		i;
	char	**new_env;
	int		shlvl_flag;

	shlvl_flag = shlvl(env, f);
	i = -1;
	if (shlvl_flag)
		new_env = (char **)malloc((ft_arrlen(env) + 2) * sizeof(char *));
	else
		new_env = (char **)malloc((ft_arrlen(env) + 3) * sizeof(char *));
	if (!new_env)
		return (NULL);
	while (env[++i])
		new_env[i] = copy_env_help(env[i], f);
	if (!shlvl_flag && f)
		new_env[i++] = ft_strdup("SHLVL=1");
	if (f)
		new_env[i++] = ft_strdup("?=0");
	new_env[i] = NULL;
	return (new_env);
}
