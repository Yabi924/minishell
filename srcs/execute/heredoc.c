#include "../../include/minishell.h"

int	heredoc_check(t_data *mini)
{
	int	x;

	x = 0;
	while (mini->input_arr[x])
	{
		if (!ft_strncmp(mini->input_arr[x], "<<", 3) && !mini->input_arr[x + 1])
		{
			printf("Minishell: syntax error near unexpected token `newline'\n");
			return (1);
		}
		else if (!ft_strncmp(mini->input_arr[x], "<<", 3))
			heredoc2(mini, x + 1);
		x++;
	}
	return (0);
}

void	heredoc_run(t_data *mini, char *str)
{
	int	tmp;

	(void)mini;
	tmp = open(".tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (ft_strlen(str) == 0)
		str = ft_calloc(1, sizeof(char));
	else
		str[ft_strlen(str)] = '\0';
	write(tmp, str, ft_strlen(str));
	close(tmp);
	free(str);
}

int	heredoc2(t_data *mini, int x)
{
	char	*key_word;
	char	*long_str;
	char	*long_str1;
	char	*here_arg;

	long_str = "";
	key_word = mini->input_arr[x];
	while (1)
	{
		here_arg = readline("> ");
		if (!here_arg || \
			!ft_strncmp(here_arg, key_word, ft_strlen(key_word) + 1))
		{
			heredoc_run(mini, long_str);
			free(here_arg);
			return (0);
		}
		long_str1 = strjoin_helper(long_str, here_arg, 0, 1);
		if (ft_strlen(long_str) > 0)
			free(long_str);
		long_str = strjoin_helper(long_str1, "\n", 1, 0);
	}
	return (0);
}

char	**mal_dup(t_data *mini)
{
	int		x;
	char	**arr;

	x = -1;
	while (mini->input_arr[++x])
		;
	arr = ft_calloc(x + 1, sizeof(char *));
	return (arr);
}

int	is_redir(char *str)
{
	if (!ft_strncmp(str, ">", 2))
		return (0);
	else if (!ft_strncmp(str, ">>", 3))
		return (0);
	return (1);
}