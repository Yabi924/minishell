/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:22:00 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/15 08:22:05 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/*
char	*get_path(t_data *data, t_list *list)
{
	char	**env_paths;
	char	*temp;
	char	*path;
	int		i;

	i = -1;
	env_paths = ft_split(ft_getenv(data, "PATH"), ':');
	while (env_paths && env_paths[++i])
	{
		temp = ft_strjoin(env_paths[i], "/");
		path = ft_strjoin(temp, list->command[0]);
		free(temp);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_arr(env_paths);
			return (path);
		}
		free(path);
	}
	free_arr(env_paths);
	return (NULL);
}
*/

// char *get_path(t_data *data, t_list *list)
// {
//     char    **env_paths;
//     char    *temp;
//     char    *path;
//     int     i;

//     env_paths = ft_split(ft_getenv(data, "PATH"), ':');
//     if (!env_paths)
//         return (NULL);
    
//     i = -1;
//     while (env_paths[++i])
//     {
//         temp = ft_strjoin(env_paths[i], "/");
//         path = ft_strjoin(temp, list->command[0]);
//         free(temp);
//         if (access(path, F_OK | X_OK) == 0)
//         {
//             free_arr(env_paths);
//             return (path);
//         }
//         free(path);
//     }
//     free_arr(env_paths);
//     return (NULL);
// }

/*
char	*ft_getenv(t_data *data, char *env_var)
{
	char	*value;
	int		i;

	i = -1;
	value = NULL;
	if (!ft_strncmp(env_val, "?\0", 2))
		return (ft_itoa(data->cmd_exit_no));
	while (data->env[++i])
	{
		if (!ft_strncmp(data->env[i], env_val, ft_strlen(env_val)) && \
			data->env[i][ft_strlen(env_val)] == '=')
			{
				value = ft_strchr(data->env[i], '=') + 1;
				break ;
			}
	}
	if (!value)
		return ("");
	return (value);
}
*/
// char *ft_getenv(t_data *data, char *env_var)
// {
//     char    *value;
//     int     i;

//     i = -1;
//     value = NULL;
//     if (!ft_strncmp(env_var, "?\0", 2)) // Fixed variable name
//         return (ft_itoa(data->cmd_exit_no));
    
//     while (data->env[++i])
//     {
//         if (!ft_strncmp(data->env[i], env_var, ft_strlen(env_var)) && \
//             data->env[i][ft_strlen(env_var)] == '=')
//         {
//             value = ft_strchr(data->env[i], '=') + 1;
//             break;
//         }
//     }
//     return (value ? value : "");
// }


/*
#include "../../include/minishell.h"

char	*ft_getenv(t_data *mshell, char *evar)
{
	char	*value;
	int		a;

	a = -1;
	value = NULL;
	if (!ft_strncmp(evar, "?\0", 2))
		return (ft_itoa(mshell->cmd_exit_no));
	while (mshell->env[++a])
	{
		if (!ft_strncmp(mshell->env[a], evar, ft_strlen(evar)) && \
			mshell->env[a][ft_strlen(evar)] == '=')
		{
			value = ft_strchr(mshell->env[a], '=') + 1;
			break ;
		}
	}
	if (!value)
		return ("");
	return (value);
}

int	input_setup(t_data *mshell, t_list *lst)
{
	if (lst->in_path && lst->delimiter == NULL)
		mshell->in_fd = open(lst->in_path, O_RDONLY);
	else if (lst->in_path == NULL && lst->delimiter)
		mshell->in_fd = open(".tmp", O_RDONLY);
	else if (lst->fd[0] != -1 && lst->fd[0] != 0)
		mshell->in_fd = lst->fd[0];
	else
		mshell->in_fd = dup(mshell->in_first);
	if (mshell->heredoc && mshell->cmd_exit_no == 42)
		return (1);
	if (mshell->in_fd == -1 && !mshell->heredoc)
	{
		perror("Minishell: Infile");
		return (1);
	}
	if (dup2(mshell->in_fd, 0) == -1 && !mshell->heredoc)
	{
		perror("Error: infile fd");
		return (1);
	}
	close(mshell->in_fd);
	return (0);
}

void	output_setup(t_data *mshell, t_list *lst)
{
	if (lst->out_path && lst->append == 0)
		mshell->out_fd = open(lst->out_path, \
							O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (lst->out_path && lst->append == 1)
		mshell->out_fd = open(lst->out_path, \
							O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (lst->next)
	{
		mshell->out_fd = lst->next->fd[1];
		close(lst->next->fd[0]);
	}
	else
		mshell->out_fd = dup(mshell->out_first);
	if (dup2(mshell->out_fd, 1) == -1)
	{
		perror("Error: outfile fd");
		return ;
	}
	close(mshell->out_fd);
}

void	kindergarden_end(pid_t *childs, t_data *mshell)
{
	int	status;
	int	i;

	i = -1;
	while (childs[++i] != -1)
	{
		waitpid(childs[i], &status, 0);
		if (WIFSIGNALED(status))
			mshell->cmd_exit_no = 128 + WTERMSIG(status);
		else if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
			mshell->cmd_exit_no = status;
		}
	}
}

void	cmd(t_data *mshell, t_list *lst)
{
	char	*path;

	if (confirm_built_in(lst))
		return ;
	if (lst->command && lst->command[0])
	{
		path = get_path(mshell, lst);
		if (!ft_strncmp(lst->command[0], ".", 1) \
			|| !ft_strncmp(lst->command[0], "..", 2))
			path = NULL;
		if (!path)
		{
			err_msg(mshell, 127, "Minishell: '%s': command not found\n", \
					lst->command[0]);
			free(path);
			return ;
		}
		execve(path, lst->command, mshell->env);
		free(path);
		mshell->cmd_exit_no = 1;
	}
}

void	child_process(t_data *mshell, t_list *lst)
{
	if (input_setup(mshell, lst) == 0)
	{
		if (mshell->heredoc)
			exit(mshell->cmd_exit_no);
		output_setup(mshell, lst);
		ft_signal(1);
		if (confirm_built_in(lst))
			built_in(mshell, lst);
		cmd(mshell, lst);
	}
	else
		mshell->cmd_exit_no = 1;
	exit(mshell->cmd_exit_no);
}
*/