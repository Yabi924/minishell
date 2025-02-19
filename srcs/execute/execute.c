/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:26:27 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/15 08:26:30 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    transit(t_data *data, t_list *list, pid_t *children);
void    only_built_in(t_data *data, t_list *list);
void    execute_fd_init(t_data *data);
void    ft_execute(t_data *data, t_list *list);

void    transit(t_data *data, t_list *list, pid_t *children)
{
    int i;

    i = -1;
    while (list)
    {
        if (list->next)
            pipe(list->next->fd);
        if (list->delimiter)
            here_doc(data, list);
        children[++i] = fork();
        if (children[i] == 0)
        {
            ft_signal(1);
            child_process(data, list);
        }
        else
        {
            if (list->fd[0] != -1)
                close(list->fd[0]);
            if (list->next)
                close(list->next->fd[1]);
            list = list->next;
        }
    }
    transit_end(children, data);
}

void    only_built_in(t_data *data, t_list *list)
{
    int status;

    status = input_config(data, list);
    if (status)
        return ;
    if (data->heredoc)
        return ;
    output_config(data, list);
    built_in(data, list);
}
void    execute_fd_init(t_data *data)
{
    data->in_first = dup(0);
    data->out_first = dup(1);
    data->in_fd = 0;
    data->out_fd = 1;
}

void    ft_execute(t_data *data, t_list *list)
{
    pid_t   *children;

    if (!list || !list->command)
        return ;
    execute_fd_init(data);
    children = malloc((ft_lstsize(list) + 1) * sizeof(pid_t));
    if (!children)
        return ;
    children[ft_lstsize(list)] = -1;
    ft_signal(1);
    if (list->next == NULL && confirm_built_in(list))
        only_built_in(data, list);
    else
        transit(data, list, children);
    dup2(data->in_first, 0);
    dup2(data->out_first, 1);
    close(data->in_first);
    close(data->out_first);
    unlink(".tmp");
    free(children);
}
