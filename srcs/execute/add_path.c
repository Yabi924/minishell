/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:14:23 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/18 14:50:23 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char    *ft_getenv(char *s, char **env)
{
    int i;
    int p;

    i = -1;
    p = 0;
    while (s[p] && (s[p] != '"' || s[p] != '\'' || s[p] != '$' || s[p] != ' '))
        p++;
    while (env[++i])
        if (is_env(s, env[i]))
            return (ft_strdup(env[i] + p + 1));
    return (NULL);
}

static void free_path(char *s, char **arr)
{
    if (s)
        free(s);
    free_arr(arr);
}

char    *add_path(t_data *data,  char *command)
{
    int i;
    char *path;
    char **split_path;
    char *temp;

    i = -1;
    path = ft_getenv("PATH", data->env);
    if (!path)
        return (NULL);
    split_path = ft_split(path, ':');
    while (split_path[++i])
    {
        temp = ft_strjoin(split_path[i], "/");
        temp = ft_strjoin_free(temp, command);
        if (access(temp, F_OK | X_OK) == 0)
            break ;
        if (temp)
            free(temp);
    }
    free_path(path, split_path);
    if (!temp)
        return (NULL);
    return (temp); 
}