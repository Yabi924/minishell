#include "../../include/minishell.h"

int	check_if_redirect(t_list *lst, int i)
{
	if (!ft_strncmp(lst->command[i], "<\0", 2))
		return (1);
	else if (!ft_strncmp(lst->command[i], ">\0", 2))
		return (2);
	else if (!ft_strncmp(lst->command[i], "<<\0", 3))
		return (3);
	else if (!ft_strncmp(lst->command[i], ">>\0", 3))
		return (4);
	else
		return (0);
}

int	check_redirect_syntax(t_data *mshell, t_list *lst, int i)
{
	if (!lst->command || !(*lst->command))
		return (0);
	if (check_if_redirect(lst, i))
	{
		if (!lst->command[i + 1] || check_if_redirect(lst, i + 1))
		{
			err_msg(mshell, 2, "Syntax error near redirection.\n", NULL);
			return (0);
		}
		return (1);
	}
	return (2);
}
