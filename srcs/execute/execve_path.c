/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 07:33:49 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/19 07:33:52 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    execve_command(t_data *data, t_list *list)
{
    pid_t	p_id;
    char    *temp;
    char    **envp;

	if (access(list->command[0], F_OK | X_OK) == 0)
	{
        //Idriss's part
        temp = ft_strdup(list->command[0]);
	}
	else 
	{
		temp = add_path(data, list->command[0]);
		if (!temp)
			return ; //err message & free data;
		if (list->command[0])
			free(list->command[0]);
		list->command[0] = ft_strdup(temp);
		if (temp)
			free(temp);
		// pll(list);
	}
	//idriss part
	// execve
    // Fork the process to execute the command
    p_id = fork();
    if (p_id < 0)
    {
        perror("minishell: fork failed");
        return;
    }
    if (p_id == 0) // Child process
    {
        envp = data->env; // Use environment variables
        if (execve(list->command[0], list->command, envp) == -1)
        {
            perror("minishell");
            exit(127); // Standard exit code for command not found
        }
    }
    else // Parent process
    {
        int status;
        waitpid(p_id, &status, 0); // Wait for child process
    }
}

/*
    int main(int ac, char **av, char **env)

	/bin/ls (relative path) /usr/bin/ls (absolute path)  ls (command)

	1) Test if can access --> access(list->command[0]

	2) If fail, then get path from ENV
	  a) table->env[i] == "PATH"  (function) = string
      b) ft_split(string, ":")  --> malloc
	  c) string_path = ft_join(path[i], command) --> malloc
	       i) access (string_path)

	3) If tried everything and still fail, command is
		msg --> error: command not found
	
	strerror(errno)
*/
