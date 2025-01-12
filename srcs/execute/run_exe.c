

#include "../../include/minishell.h"

void    builtins(t_data *shell, t_list *list)
{
    if (list->command[0] == NULL)
        return ;
    if (!ft_strncmp(list->command[0], "pwd\0", 4))
    {
        printf("%s\n", shell->cwd);
        shell->cmd_exit_no = 0;
    }
    else if (!ft_strncmp(list->command[0], "exit\0", 5))
        ft_exit(shell, list);
    /*
    else if (!ft_strncmp(list->command[0], "env\0", 4))
        //ft_env(shell, list);
    else if (!ft_strncmp(list->command[0], "cd\0", 3))
        //ft_cd(shell, list);
    else if (!ft_strncmp(list->command[0], "echo\0", 5))
        //ft_echo(shell, list);
    else if (!ft_strncmp(list->command[0], "unset\0", 6))
        //ft_unset(shell, list);
    else if (!ft_strncmp(list->command[0], "export\0", 7))
        //ft_export(shell, list);
    else if (!ft_strncmp(list->command[0], "./", 2) || \
                    !ft_strncmp(list->command[0], "/", 1))
            //ft_executable(shell, list);
    */
}

void    kindergarten(t_data *shell, t_list *list, pid_t *child)
{
    int i;

    i = -1;
    while (list)
    {
        if (list->next)
            pipe(list->next->fd);
        //if (list->delimiter)
       //     heredoc(shell, list);
        child[++i] = fork();
        if (child[i] == 0)
        {
            ft_signal(1);
            child_process(shell, list);
        }
        else
        {
            if (list->fd[0] != -1)
                close(list->fd[0]);
            if (list->next)
                close(list->next->fd[1]);
            list = list->next;
        }
    }
    kindergarten_end(child, shell);
}

void    only_builtins(t_data *shell, t_list *list)
{
    int status;

    status = input_setup(shell, list);
    if (status)
        return ;
    if (shell->heredoc)
        return ;
    output_setup(shell, list);
    builtins(shell, list);
}

void    exec_fd_setup(t_data *shell)
{
    shell->in_fd = dup(0);
    shell->out_fd = dup(1);
    shell->in_fd = 0;
    shell->out_fd = 1;
}

void execution(t_data *shell, t_list *list)
{
    pid_t *child;

    if (!list || !list->command)
        return;

    exec_fd_setup(shell);

    child = malloc((ft_lstsize(list) + 1) * sizeof(pid_t));
    if (!child)
    {
        perror("malloc");
        return;
    }

    if (list->next == NULL && check_built_in(list))
        only_builtins(shell, list);
    else
        kindergarten(shell, list, child);

    dup2(shell->in_fd, STDIN_FILENO); // Restore standard input
    dup2(shell->out_fd, STDOUT_FILENO); // Restore standard output
    close(shell->in_fd);
    close(shell->out_fd);
    free(child);
}
