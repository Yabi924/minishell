
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
			//err_msg(mshell, 0, " end-of-file (wanted '%s')\n", lst->delimiter);
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
	status = check_if_redirect(lst, i);
	if (status)
	{
		if (status == 1)
		{
			if (lst->in_path)
				free(lst->in_path);
		}
		else if (status == 2 || status == 4)
		{
			if (lst->out_path)
			{
				open(lst->out_path, O_WRONLY | O_CREAT, 0644);
				free(lst->out_path);
			}
			if (status == 4)
				lst->append = 1;
		}
		else if (status == 3)
		{
			if (lst->delimiter)
				free(lst->delimiter);
		}
	}
}

int	redirection(t_data *mshell, t_list *lst)
{
	t_list	*tmp;
	int		i;
	int		value;
	int		status;

	tmp = lst;
	status = 0;
	while (tmp)
	{
		i = -1;
		while (tmp->command && tmp->command[++i])
		{
			value = check_redirect_syntax(mshell, tmp, i);
			if (!value)
				return (0);
			else if (value == 1)
			{
				redirect_setup(tmp, i, status);
				redirect_setup2(tmp, i, status);
				++i;
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

void	command_update(t_list **lst, int i)
{
	t_list	*tmp;

	free((*lst)->command[i]);
	free((*lst)->command[i + 1]);
	while ((*lst)->command[i + 2])
	{
		(*lst)->command[i] = (*lst)->command[i + 2];
		++i;
	}
	(*lst)->command[i] = NULL;
	if ((*lst)->command == NULL)
	{
		tmp = (*lst)->next;
		free_arr((*lst)->command);
		free(*lst);
		*lst = tmp;
	}
}

/*
int     right_redirect(t_data *mini, int x, char *valid)
{
    int     fd;

    fd = open(mini->command_arr[x + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0)
    {
        g_exit_code = 258;
        ft_putstr_fd("Minishell: syntax error near unexpected taken 'newline\n", 2);
        return (1);
    }
    if (!ft_strncmp(mini->command_arr[0], ">", 2))
        return (1);
    array_dup(mini);
    if (access(valid, X_OK) == 0 || builtin_check(mini) == 1)
        dup2(fd, 1);
    close(fd);
    return (0);
}

char    *get_file(char **in, int x)
{
    while (in[x++])
    {
        if (!ft_strncmp(in[x], "<", 2)
                || !ft_strncmp(in[x], ">", 2)
                || !ft_strncmp(in[x], ">>", 3)
                || !ft_strncmp(in[x], "<<", 3))
                return (in[x - 1]);
    }
    return (in[x - 2]);
}

int     left_redirect(t_data *mini, int x, char *valid)
{
    int     fd;
    char    *file;

    file = get_file(mini->command_arr, x);
    if (x == 0)
    {
        g_exit_code = 258;
        ft_putstr_fd("Minishell: syntax error near unexpected taken 'newline\n", 2);
        return (1);
    }
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        g_exit_code = 1;
        ft_printf("Minishell: no such file or directory: %s\n", file);
        return (1);
    }
    if (access(valid, X_OK) == 0 || builtin_check(mini) == 1)
        dup2(fd, 0);
    close(fd);
    return (0);
}

int     redirect_check(t_data *mini, char *valid)
{
    int     x;
    int     err;

    x = 0;
    err = 0;
    while (mini->command_arr[x])
    {
        if (!ft_strncmp(mini->command_arr[x], ">", 2))
                err = right_redirect(mini, x, valid);
        else if (!ft_strncmp(mini->command_arr[x], ">>", 3))
                err = right_redirect(mini, x, valid);
        else 
        #include "minishell.h"
        
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
                    mshell->here_doc = 1;
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
            status = check_if_redirect(lst, i);
            if (status)
            {
                if (status == 1)
                {
                    if (lst->in_path)
                        free(lst->in_path);
                }
                else if (status == 2 || status == 4)
                {
                    if (lst->out_path)
                    {
                        open(lst->out_path, O_WRONLY | O_CREAT, 0644);
                        free(lst->out_path);
                    }
                    if (status == 4)
                        lst->append = 1;
                }
                else if (status == 3)
                {
                    if (lst->delimiter)
                        free(lst->delimiter);
                }
            }
        }
        
        int	redirection(t_data *mshell, t_list *lst)
        {
            t_list	*tmp;
            int		i;
            int		value;
            int		status;
        
            tmp = lst;
            status = 0;
            while (tmp)
            {
                i = -1;
                while (tmp->command && tmp->command[++i])
                {
                    value = check_redirect_syntax(mshell, tmp, i);
                    if (!value)
                        return (0);
                    else if (value == 1)
                    {
                        redirect_setup(tmp, i, status);
                        redirect_setup2(tmp, i, status);
                        ++i;
                    }
                }
                tmp = tmp->next;
            }
            return (1);
        }
        if (!ft_strncmp(mini->command_arr[x], "<", 2))
                err = left_redirect(mini, x, valid);
        if (err == 1)
                return (1);
        x++;
    }
    return (0);
}
*/
