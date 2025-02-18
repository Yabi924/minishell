/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:22:56 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/20 18:23:17 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    ft_cd(t_data *data, t_list *list)
{
    char    path[PATH_VAL];
    char    *new_path;
    char    *old_path;

    if (!list->command[1] || !ft_strncmp(list->command[1], "~", 2))
        new_path = ft_strdup(ft_getenv("HOME", data->env));
    else if (!ft_strncmp(list->command[1], "-", 2))
        new_path = ft_strdup(ft_getenv("OLDPWD", data->env));
    else
        new_path = ft_strdup(list->command[1]);
    if_path_is_wrong(new_path);
    old_path = ft_strdup(ft_getenv("PWD", data->env));
    check_dir(new_path, old_path);
    if (getcwd(path, sizeof(path)))
    {
        env_updater(data, "PWD", path);
        if (old_path)
            env_updater(data, "OLDPWD", old_path);
    }
    free_cd(new_path, old_path);
    data->cmd_exit_no = 0;
}

void    env_updater(t_data *data, char *key, char *value)
{
    int     i;
    char    *new_entry;
    char    *temp;

    i = 0;
    if (!key || !value)
        return;
    new_entry = ft_strjoin(key, "=");
    temp = ft_strjoin(new_entry, value);
    free(new_entry);
    while (data->env[i])
    {
        if (!ft_strncmp(data->env[i], key, ft_strlen(key)) &&
            data->env[i][ft_strlen(key)] == '=')
        {
            free(data->env[i]);
            data->env[i] = temp;
            return;
        }
        i++;
    }
}

void    if_path_is_wrong(char *new_path)
{
    if (!new_path)
    {
        perror("minishell: cd");
        return;
    }
}

void    check_dir(char *new_path, char *old_path)
{
    if (chdir(new_path) != 0)
    {
        perror("minishell: cd");
        free_cd(new_path, old_path);
        return;
    }
}

void    free_cd(char *new_path, char *old_path)
{
    free(new_path);
    free(old_path);
}