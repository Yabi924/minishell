/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:44 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/27 15:39:41 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
		data->cmd_exit_no = 127;
		exit(data->cmd_exit_no);
	}
	if (ppt_input && ppt_input[0])
		add_history(ppt_input);
	data->input = ft_strdup(ppt_input);
	if (g_exit_code)
	{
		data->cmd_exit_no = g_exit_code;
		g_exit_code = 0;
	}
	free(ppt_input);
	free(cwd);
	free(ppt);
}

int	lexer(char *input)
{
	if (check_quotes(input))
	{
		ft_putstr_fd("debug: quotes\n", 2);
		return (1);
	}
	if (check_pipe(input))
	{
		ft_putstr_fd("debug: pipe\n", 2);
		return (1);
	}
	return (0);
}

int	input_handle(t_data *data)
{
	print_prompt(data);
	update_env(data);
	skip_unprint(data);
	if (lexer(data->input))
	{
		free(data->input);
		data->input = NULL;
		data->cmd_exit_no = 127;
		ft_putstr_fd("Syntax error\n", 2);
	}
	else
	{
		parser(data);
		if (redirection(data, data->list))
			ft_execute(data, data->list);
		free_data(data);
	}
	return (0);
}

char	*strjoin_helper(char *str1, char *str2, int free1, int free2)
{
	char	*ret;

	if (!str1 || !str2)
		return (NULL);
	ret = ft_strjoin(str1, str2);
	if (free1)
		free(str1);
	if (free2)
		free(str2);
	return (ret);
}
