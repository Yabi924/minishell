/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:26:27 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/22 08:42:32 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/minishell.h"

void	transit(t_data *data, t_list *list, pid_t *children)
{
	int	i;
void	transit(t_data *data, t_list *list, pid_t *children)
{
	int	i;

	i = -1;
	while (list)
	{
		if (list->next)
			pipe(list->next->fd);
		if (list->delimiter)
			heredoc(data, list);
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

void	transit_end(pid_t *children, t_data *data)
{
	int	status;
	int	i;

	i = -1;
	while (children[++i] != -1)
	{
		waitpid(children[i], &status, 0);
		if (WIFSIGNALED(status))
			data->cmd_exit_no = 128 + WTERMSIG(status);
		else if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
			data->cmd_exit_no = status;
		}
	}
}

void only_built_in(t_data *data, t_list *list)
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

void execute_fd_init(t_data *data)
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

/*
static char *find_command(char *cmd, char **env)
{
    char *path_env = NULL;
    char **paths = NULL;
    char *full_path = NULL;
    int i;

    // Get the PATH variable from the environment
    for (i = 0; env[i]; i++) {
        if (strncmp(env[i], "PATH=", 5) == 0) {
            path_env = env[i] + 5;
            break;
        }
    }

    if (!path_env) // No PATH in environment
        return NULL;

    // Split PATH into directories
    paths = ft_split(path_env, ':');
    if (!paths)
        return NULL;

    // Search for the command in each directory
    for (i = 0; paths[i]; i++) {
        full_path = ft_strjoin(paths[i], "/");
        if (!full_path)
            break;
        full_path = ft_strjoin_free(full_path, cmd); // Append command to directory
        if (!full_path)
            break;
        if (access(full_path, F_OK | X_OK) == 0) { // Command found
            free(paths); // Free paths array
            return full_path;
        }
        free(full_path);
    }

    free(paths); // Free paths array
    return NULL; // Command not found
}

void    ft_execute(t_data *data, t_list *list)
{
    pid_t   p_id;
    char    *cmd_path = find_command(list->command[0], data->env);

    if (!cmd_path) {
        ft_putstr_fd("Minidata: ", 2);
        perror(list->command[0]);
        data->cmd_exit_no = 127;
        return;
    }

    p_id = fork();
    if (p_id == 0) { // Child process
        execve(cmd_path, list->command, data->env);
        perror("execve"); // If execve fails
        exit(1);
    } else if (p_id > 0) { // Parent process
        waitpid(p_id, &data->cmd_exit_no, 0);
        data->cmd_exit_no = WEXITSTATUS(data->cmd_exit_no);
    } else {
        perror("fork");
    }
    free(cmd_path);
}
*/