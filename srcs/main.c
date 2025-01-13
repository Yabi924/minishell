/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:32 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/12 20:37:51 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int  get_signal_code = 0;

char    **copy_env(char **env)
{
    int     i;
    char    **new_env;

    i = -1;
    new_env = (char **)malloc((ft_arrlen(env) + 1) * sizeof(char *));    
    if (!new_env)
        return NULL;
    while (env[++i])
        new_env[i] = ft_strdup(env[i]);
    new_env[i] = NULL;
    return (new_env);
}

void    initminishell(t_data *data, char **env)
{
    data->env = copy_env(env);
    // if (!data->env)
        //error malloc
    data->cmd_exit_no = 0;
    data->list = NULL;
    tcgetattr(STDIN_FILENO, &data->ori_terminal);
    data->mod_terminal = data->ori_terminal;
    //data->mod_terminal.c_lflag &= ~ECHOCTL;
    tcsetattr(STDIN_FILENO, TCSANOW, &data->mod_terminal);
}

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    t_data minishell_data;

    initminishell(&minishell_data, env);
    //init(env); //Test case
    while (1)
    {
        signal(SIGINT, signal_int);
        signal(SIGQUIT, SIG_IGN);
        input_handle(&minishell_data);
        tcsetattr(STDIN_FILENO, TCSANOW, &minishell_data.mod_terminal);
    }
    return (0);
}

void    print_arr(char **s)
{
    int i = -1;
    while (s[++i])
        printf("i:%d str:%s\n", i + 1, s[i]);
}

void    pll(t_list *list)
{
    int i = 0;

    while (list)
    {
        printf("\nlinked list:%d\n", i++);
        print_arr(list->command);
        list = list->next;
    }
}
