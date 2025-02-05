/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:22:56 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/01/18 17:17:53 by yyan-bin         ###   ########.fr       */
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

// Function to update OLDPWD in the environment
static void update_oldpwd(t_data *data)
{
    char cwd[1024];
    t_env *current;

    current = data->env_ll;
    if (getcwd(cwd, sizeof(cwd)) == NULL)
        err_exit("getcwd", errno);
    while (current)
    {
        if (strcmp(current->key, "OLDPWD") == 0)
        {
            free(current->value);
            current->value = ft_strdup(cwd);
            return ;
        }
        current = current->next;
    }
}

// Function to update PWD in the environment
static void update_pwd(t_data *data)
{
    char cwd[1024];
    t_env *current;

    current = data->env_ll;
    if (getcwd(cwd, sizeof(cwd)) == NULL)
        err_exit("getcwd", errno);
    while (current)
    {
        if (strcmp(current->key, "PWD") == 0)
        {
            free(current->value);
            current->value = ft_strdup(cwd);
            return ;
        }
        current = current->next;
    }
}

// Function to change directory to HOME
static int cd_home(t_data *data)
{
    char *home;

    home = env_val("HOME", data->env_ll);
    if (!home)
    {
        ft_printf("cd: HOME not set\n");
        return (EXIT_FAILURE);
    }
    if (chdir(home) == -1)
    {
        perror("cd");
        return (EXIT_FAILURE);
    }
    update_pwd(data);
    return (EXIT_SUCCESS);
}

// Main function for the cd command
void ft_cd(t_data *data)
{
    if (!data->list->command[1])  // If no argument is passed, go to HOME directory
    {
        if (cd_home(data) == EXIT_FAILURE)
            return;
    }
    else if (strcmp(data->list->command[1], "-") == 0)  // Handle '-' for previous directory
    {
        char *oldpwd = env_val("OLDPWD", data->env_ll);
        if (!oldpwd)
        {
            ft_printf("cd: OLDPWD not set\n");
            return;
        }
        if (chdir(oldpwd) == -1)
        {
            perror("cd");
            return;
        }
        ft_printf("%s\n", oldpwd);  // Print the directory we're changing to
        update_oldpwd(data);  // Update OLDPWD after changing directory
    }
    else  // Change to the specified directory
    {
        if (chdir(data->list->command[1]) == -1)
        {
            perror("cd");
            return;
        }
        update_oldpwd(data);  // Update OLDPWD before changing to the new directory
        update_pwd(data);     // Update PWD after changing to the new directory
    }
}

void errorMsg3(char *builtin, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(builtin, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

void err_exit(char *action, int code)
{
	errorMsg3(action, strerror(code));
	exit(EXIT_FAILURE);
}

char	*env_val(char *key, t_env *env)
{
	while (key && env)
	{
		if (!strcmp(key, env->key))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

// void    assign_oldpwd(t_env *env_ll, char *pwd, t_data *mini)
// {
//     char    *key;

//     while (env_ll != NULL)
//     {
//         if (!strcmp(env_ll->key, "OLDPWD"))
//         {
//             free(env_ll->value);
//             env_ll->value = pwd;
//             return ;
//         }
//         env_ll = env_ll->next;
//     }
//     key = ft_strdup("OLDPWD");
//     add_node_end(mini->env_ll, key, pwd, 0);
// }

// void    pwd_update(t_env *env_ll, char *new_pwd, t_data *mini)
// {
//     char    *key;

//     while (env_ll != NULL)
//     {
//         if (!strcmp(env_ll->key, "PWD"))
//         {
//             free(env_ll->value);
//             env_ll->value = new_pwd;
//             return ;
//         }
//         env_ll = env_ll->next;
//     }
//     key = ft_strdup("PWD");
//     add_node_end(mini->env_ll, key, new_pwd, 0);
// }

// void    home(t_data *mini)
// {
//     char    *new_dir;

//     new_dir = get_env(mini->env_ll, "HOME");
//     if (!new_dir[0])
//         ft_printf("bash: cd: HOME not set\n");
//     chdir(new_dir);
// }

// void    change_dir(t_data *mini)
// {
//     char    *new_dir;
//     char    *pwd;

//     pwd = getcwd(NULL, 1024);
//     if (!mini->command_arr[1])
//         home(mini);
//     else if (!ft_strncmp(mini->command_arr[1], "-", 2))
//         chdir(getenv("HOME"));
//     else if (!ft_strncmp(mini->command_arr[1], "-", 2))
//     {
//         new_dir = get_env(mini->env_ll, "OLDPWD");
//         if (chdir(new_dir) == -1 && !new_dir[0])
//                 ft_printf("Minishell: cd: OLDPWD not set\n");
//         else
//                 ft_printf("%s\n", new_dir);
//     }
//     else if (chdir(mini->command_arr[1]) == -1)
//     {
//         g_exit_code = 1;
//         ft_printf("Minishell: cd: %s: No such file or directory\n",
//                     mini->command_arr[1]);
//     }
//     assign_oldpwd(mini->env_ll, pwd, mini);
//     pwd = getcwd(NULL, 1024);
//     pwd_update(mini->env_ll, pwd, mini);
// }