/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:23:49 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/01/08 20:23:51 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    get_pwd(void)
{
    char    *pwd;

    pwd = getcwd(NULL, 1024);
    ft_printf("%s\n", pwd);
    free(pwd);
}

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
    //add_node_end(mini->env_ll, key, pwd, 0);
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
    //add_node_end(mini->env_ll, key, new_pwd, 0);
}
*/