/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:22:56 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/01/08 20:22:58 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
void    assign_oldpwd(t_env *env_ll, char *pwd, t_data *mini)
{
    char    *key;

    while (env_ll != NULL)
    {
        if (!strcmp(env_ll->key, "OLDPWD"))
        {
            free(env_ll->value);
            env_ll->value = pwd;
            return ;
        }
        env_ll = env_ll->next;
    }
    key = ft_strdup("OLDPWD");
    add_node_end(mini->env_ll, key, pwd, 0);
}

void    pwd_update(t_env *env_ll, char *new_pwd, t_data *mini)
{
    char    *key;

    while (env_ll != NULL)
    {
        if (!strcmp(env_ll->key, "PWD"))
        {
            free(env_ll->value);
            env_ll->value = new_pwd;
            return ;
        }
        env_ll = env_ll->next;
    }
    key = ft_strdup("PWD");
    add_node_end(mini->env_ll, key, new_pwd, 0);
}

void    home(t_data *mini)
{
    char    *new_dir;

    new_dir = get_env(mini->env_ll, "HOME");
    if (!new_dir[0])
        ft_printf("bash: cd: HOME not set\n");
    chdir(new_dir);
}

void    change_dir(t_data *mini)
{
    char    *new_dir;
    char    *pwd;

    pwd = getcwd(NULL, 1024);
    if (!mini->command_arr[1])
        home(mini);
    else if (!ft_strncmp(mini->command_arr[1], "-", 2))
        chdir(getenv("HOME"));
    else if (!ft_strncmp(mini->command_arr[1], "-", 2))
    {
        new_dir = get_env(mini->env_ll, "OLDPWD");
        if (chdir(new_dir) == -1 && !new_dir[0])
                ft_printf("Minishell: cd: OLDPWD not set\n");
        else
                ft_printf("%s\n", new_dir);
    }
    else if (chdir(mini->command_arr[1]) == -1)
    {
        get_signal_code = 1;
        ft_printf("Minishell: cd: %s: No such file or directory\n",
                    mini->command_arr[1]);
    }
    assign_oldpwd(mini->env_ll, pwd, mini);
    pwd = getcwd(NULL, 1024);
    pwd_update(mini->env_ll, pwd, mini);
}
*/