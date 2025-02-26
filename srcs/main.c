/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:32 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/26 21:18:29 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	g_exit_code = 0;

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
			break ;
		}
	}
	if (exit_code)
		free(exit_code);
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
	data->heredoc = 0;
	tcgetattr(STDIN_FILENO, &data->ori_terminal);
	data->mod_terminal = data->ori_terminal;
	data->mod_terminal.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &data->mod_terminal);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	t_data	data;

	if (argc != 1 || argv[1])
		return (1);
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

void    print_arr(char **s)
{
    int i = -1;
    while (s[++i])
        printf("debug: i:%d str:%s\n", i + 1, s[i]);
}

void    pll(t_list *list)
{
    int i = 0;

    while (list)
    {
        printf("debug: linked list:%d\n", i++);
        print_arr(list->command);
        list = list->next;
    }
}