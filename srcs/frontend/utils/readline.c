/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:00:27 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/19 00:35:49 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	print_prompt(t_data *data)
{
	char	*ppt_input;
	char	*cwd;
	char	*ppt;

	cwd = getcwd(NULL, 1024);
	ppt = ft_strjoin("Minishell: ", cwd);
	ppt = ft_strjoin_free(ppt, " > ");
	ppt_input = readline(ppt);
	if (!ppt_input)
	{
		ft_putstr_fd("exit\n", 1);
		tcsetattr(STDIN_FILENO, TCSANOW, &data->ori_terminal);
		exit(0);//will update to free before exit
	}
	if (ppt_input && ppt_input[0])
		add_history(ppt_input);
	data->input = ft_strdup(ppt_input);
	free(ppt_input);
	free(cwd);
	free(ppt);
}
