#include "../../include/minishell.h"

void	here_doc2(t_data *mshell, t_list *lst, int fd, char *input)
{
	ft_signal(2);
	fd = open(".tmp", O_WRONLY | O_CREAT, 0644);
	input = readline(" > ");
	while (1)
	{
		if (!input)
		{
			ft_putstr_fd("Minishell: warning: here-document delimited by", 2);
			err_msg(mshell, 0, " end-of-file (wanted '%s')\n", lst->delimiter);
			break ;
		}
		if (!ft_strncmp(input, lst->delimiter, ft_strlen(lst->delimiter + 1)))
		{
			free(input);
			break ;
		}
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
		free(input);
		input = readline(" > ");
	}
	close(fd);
	exit (mshell->cmd_exit_no);
}

void	here_doc(t_data *mshell, t_list *lst)
{
	pid_t	p_id;
	int		status;
	int		fd;
	char	*input;

	p_id = fork();
	input = NULL;
	fd = 0;
	if (p_id == 0)
	{
		ft_signal(1);
		here_doc2(mshell, lst, fd, input);
	}
	else if (p_id)
	{
		waitpid(p_id, &status, 0);
		status = WEXITSTATUS(status);
		if (WIFSIGNALED(status) && status == 42)
		{
			mshell->heredoc = 1;
			mshell->cmd_exit_no = 130;
		}
	}
}

void	redirect_setup2(t_list *lst, int i, int status)
{
	status = check_if_redirect(lst, i);
	if (status == 1)
		lst->in_path = ft_strdup(lst->command[i + 1]);
	else if (status == 2 || status == 4)
		lst->out_path = ft_strdup(lst->command[i + 1]);
	else if (status == 3)
		lst->delimiter = ft_strdup(lst->command[i + 1]);
	if (lst->in_path || lst->out_path || lst->delimiter)
		command_update(&lst, i);
}

void	redirect_setup(t_list *lst, int i, int status)
{
    status = check_if_redirect(list, i);
    if (status)
    {
        if (status == 1)
        {
            if (list->in_path)
                free(list->in_path);
        }
        else if (status == 2 || status == 4)
        {
            if (list->out_path)
            {
                open(list->out_path, O_WRONLY | O_CREAT, 0644);
                free(list->out_path);
            }
            if (status == 4)
                list->append = 1;
        }
        else if (status == 3)
        {
            if (list->delimiter)
                free(list->delimiter);
        }
    }
}

void    redirect_config2(t_list *list, int i, int status)
{
    status = check_if_redirect(list, i);
    if (status == 1)
        list->in_path = ft_strdup(list->command[i + 1]);
    else if (status == 2 || status == 4)
        list->out_path = ft_strdup(list->command[i + 1]);
    else if (status == 3)
        list->delimiter = ft_strdup(list->command[i + 1]);
    if (list->in_path || list->out_path || list->delimiter)
        command_updater(&list, i);
}

int     redirection(t_data *data, t_list *list)
{
    t_list  *temp;
    int     i;
    int     value;
    int     status;

    temp = list;
    status = 0;
    while (temp)
    {
        i = -1;
        while (temp->command && temp->command[++i])
        {
            value = check_redirect_syntax(data, temp, i);
            if (!value)
                return (0);
            else if (value == 1)
            {
                redirect_config(temp, i, status);
                redirect_config2(temp, i, status);
                ++i;
            }
        }
        temp = temp->next;
    }
    return (1);
}
