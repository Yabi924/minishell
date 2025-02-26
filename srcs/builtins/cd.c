/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:22:56 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/26 22:46:48 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_cd(t_data *data, t_list *list)
{
	char	*path;

	if (!list->command[1] || !ft_strncmp(list->command[1], "~", 2))
	{
		path = collect_env(data, "HOME");
		if (path == NULL)
		{
			err_msg(data, 1, "Minishell: cd: HOME not set\n", NULL);
			return ;
		}
	}
	else
		path = list->command[1];
	if (chdir(path) == -1)
	{
		err_msg(data, 1, "Minishell: cd: %s: No such file or directory\n", path);
		return ;
	}
	if (!getcwd(data->cwd, PATH_VAL))
		err_msg(data, 1, "Minishell: cd: Error updating cwd\n", NULL);
	data->cmd_exit_no = 0;
}