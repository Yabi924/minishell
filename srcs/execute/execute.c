/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:26:27 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/15 08:26:30 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	kindergarden(t_data *mshell, t_list *lst, pid_t *childs)
{
	int	i;

	i = -1;
	while (lst)
	{
		if (lst->next)
			pipe(lst->next->fd);
		if (lst->delimiter)
			here_doc(mshell, lst);
		childs[++i] = fork();
		if (childs[i] == 0)
		{
			ft_signal(1);
			child_process(mshell, lst);
		}
		else
		{
			if (lst->fd[0] != -1)
				close(lst->fd[0]);
			if (lst->next)
				close(lst->next->fd[1]);
			lst = lst->next;
		}
	}
	kindergarden_end(childs, mshell);
}

void only_built_in(t_data *shell, t_list *list)
{
    int status;

    status = input_setup(shell, list);
    if (status)
        return ;
    if (shell->heredoc)
        return ;
    output_setup(shell, list);
    built_in(shell, list);
}    

void execute_fd_init(t_data *shell)
{
    shell->in_first = dup(0);
    shell->out_first = dup(1);
    shell->in_fd = 0;
    shell->out_fd = 1;
}

void    ft_execute(t_data *shell, t_list *list)
{
    pid_t   *children;

    if (!list || !list->command)
        return ;
    execute_fd_init(shell);
    children = malloc((ft_lstsize(list) + 1) * sizeof(pid_t));
    if (!children)
        return ;
    children[ft_lstsize(list)] = -1;
    ft_signal(1);
    if (list->next == NULL && confirm_built_in(list))
        only_built_in(shell, list);
    else
        kindergarden(shell, list, children);
    dup2(shell->in_first, 0);
    dup2(shell->out_first, 1);
    close(shell->in_first);
    close(shell->out_first);
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

void    ft_execute(t_data *shell, t_list *list)
{
    pid_t   p_id;
    char    *cmd_path = find_command(list->command[0], shell->env);

    if (!cmd_path) {
        ft_putstr_fd("Minishell: ", 2);
        perror(list->command[0]);
        shell->cmd_exit_no = 127;
        return;
    }

    p_id = fork();
    if (p_id == 0) { // Child process
        execve(cmd_path, list->command, shell->env);
        perror("execve"); // If execve fails
        exit(1);
    } else if (p_id > 0) { // Parent process
        waitpid(p_id, &shell->cmd_exit_no, 0);
        shell->cmd_exit_no = WEXITSTATUS(shell->cmd_exit_no);
    } else {
        perror("fork");
    }
    free(cmd_path);
}
*/