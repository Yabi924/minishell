/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:36:35 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/10 18:40:16 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    cmd(t_data *mini, t_data *data, int exit_if_zero)
{
    int     builtin;
    char    **commands;

    mini->input_arr = arr_dup(data->command_arr);
    builtin = builtin_check(mini);
    commands = command_make(mini);
    if (redirect_check(mini, commands[0]) == 1)
        return ;
    free_arr(commands);
    commands = command_make(mini);
    if (builtin == 1)
        command_handle(mini, exit_if_zero);
    else
        //run_bin(mini, commands, exit_if_zero);
    if (exit_if_zero == 0)
        exit(0);
    free_arr(commands);
    free_arr(mini->input_arr);
}

void    run_dup(int *tmp_read, t_data *mini, t_data *data, t_data *first)
{
    if (*tmp_read == -2)
        dup2(data->fd[1], STDERR_FILENO);
    else if (data->next != NULL)
    {
        if (!data->heredoc_zero_if_valid != NULL)
            dup2(*tmp_read, STDIN_FILENO);
        dup2(data->fd[1], STDOUT_FILENO);
    }
    else
    {
        if (!data->heredoc_zero_if_valid)
            dup2(*tmp_read, STDIN_FILENO);
    }
    close(first);
    cmd(mini, data, 0);
}

void    run_heredoc(t_data *mini, t_data *data)
{
    int tmp;

    data->in_fd = dup(STDIN_FILENO);
    data->out_fd = dup(STDOUT_FILENO);
    data->heredoc_zero_if_valid = heredoc_check(mini);
    if (data->heredoc_zero_if_valid == 0)
    {
        tmp = open(".tmp", O_RDONLY);
        dup2(tmp, 0);
        close(tmp);
    }
}

void    run_pipes(t_data *mini, t_data *data, t_data *first)
{

}

void    run(t_data *mini, t_data *data)
{

}