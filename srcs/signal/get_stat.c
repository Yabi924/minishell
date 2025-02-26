/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:16:08 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/01/18 17:17:53 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
    get_stat (status)
    
    Why use this function?
    - This function is used to get the exit_code for a child_process.
*/

int	get_stat(int stat)
{
	int	exit_code;

	if (WIFSIGNALED(stat))
	{
		exit_code = WTERMSIG(stat);
		if (exit_code == SIGINT)
			return (exit_code + 128);
	}
	if (WIFEXITED(stat))
		return (WEXITSTATUS(stat));
	return (1);
}

/*
    Summary (From ChatGPT)

    Summary:

    - The function get_stat() checks if the child process 
    	terminated normally or due to a signal.
    - If terminated by a signal, it handles special cases 
    	(e.g., SIGINT with signal number 2) and 
    adjusts the exit code by adding 128 to the signal number.
    
    - If the process terminated normally, it simply returns the exit status.    
*/
