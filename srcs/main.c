/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:32 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/22 08:12:28 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	g_exit_code = 0;

char	**copy_env(char **env, int f)
{
	int		i;
	char	**new_env;
	char	*temp;

	i = -1;
	new_env = (char **)malloc((ft_arrlen(env) + 2) * sizeof(char *));
	if (!new_env)
		return (NULL);
	while (env[++i])
	{
		if (is_env("SHLVL", env[i]) && f)
		{
			temp = ft_itoa(ft_atoi(env[i] + 6) + 1);
			new_env[i] = ft_strjoin("SHLVL=", temp);
			free(temp);
		}
		else
			new_env[i] = ft_strdup(env[i]);
	}
	if (f)
		new_env[i++] = ft_strdup("?=0");
	new_env[i] = NULL;
	return (new_env);
}

void	update_env(t_data *data)
{
	int		i;
	char	*exit_code;
	char	*no;

	i = -1;
	no = ft_itoa(data->cmd_exit_no);
	if (!no)
		return ;
	exit_code = ft_strjoin("?=", no);
	while (data->env[++i])
	{
		if (is_env("?", data->env[i]))
		{
			free(data->env[i]);
			data->env[i] = ft_strdup(exit_code);
			free(exit_code);
		}
	}
	if (no)
		free(no);
}

void	init_data(t_data *data, char **env)
{
	data->env = copy_env(env, 1);
	data->first_run_init_dollar = 0;
	data->cmd_exit_no = 0;
	data->list = NULL;
	data->command_arr = NULL;
	tcgetattr(STDIN_FILENO, &data->ori_terminal);
	data->mod_terminal = data->ori_terminal;
	data->mod_terminal.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &data->mod_terminal);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void)argc;
	(void)argv;
	init_data(&data, env);
	while (1)
	{
		update_env(&data);
		ft_signal(0);
		input_handle(&data);
		tcsetattr(STDIN_FILENO, TCSANOW, &data.mod_terminal);
	}
	return (0);
}
/*
void	print_arr(char **s)
{
	int i;

	i = -1;
	while (s[++i])
		ft_printf("debug: i:%d str:%s\n", i + 1, s[i]);
}

void	pll(t_list *list)
{
	int i = 0;

	while (list)
	{
		ft_printf("debug: linked list:%d\n", i++);
		print_arr(list->command);
		list = list->next;
	}
}
*/
