

#include "../../include/minishell.h"

int list_dir(t_data *mini, char *path)
{
    DIR             *d;
    struct  dirent  *dir;

    (void)mini;
    d = opendir(path);
    if (d)
    {
        while (1)
        {
            dir = readdir(d);
            if (dir == NULL)
                break ;
            if (!ft_strncmp(mini->command_arr[0], dir->d_name, ft_strlen(mini->command_arr[0]) + 1))
            {
                closedir(d);
                return (1);
            }
        }
        closedir(d);
    }
    return (2);
}

char    *path_array(t_data *mini, char *from_env)
{
    char    **twodpath;
    char    *cmd;
    int             i;

    i = 0;
    cmd = ft_strdup(mini->command_arr[0]);
    twodpath = ft_split(from_env, ':');
    while (twodpath[i])
    {
        if (list_dir(mini, twodpath[i]) == 1)
        {
            free(cmd);
            cmd = ft_strjoin(twodpath[i], "/");
            cmd = strjoin_helper(cmd, mini->command_arr[0], 1, 0);
            break ;
        }
        i++;
    }
    free(twodpath);
    return (cmd);
}

char    **command_make(t_data *mini)
{
    char    **exec;
    char    *cmd;
    int         i;

    i = 0;
	while (mini->command_arr[i++])
		;
    i = 0;
    exec[i] = ft_strdup(cmd);
    while (mini->command_arr[++i])
    {
        if (!ft_strncmp(mini->command_arr[i], ">", 2)
                || !ft_strncmp(mini->command_arr[i], ">>", 3)
                || !ft_strncmp(mini->command_arr[i], "<", 2)
                || !ft_strncmp(mini->command_arr[i], "<<", 3))
                break ;
        exec[i] = ft_strdup(mini->command_arr[i]);
    }
    free(cmd);
    return (exec);
}

void    not_builtin(t_data *mini, char **cmd)
{
    char    **env;
    int     fork_pid;
    int     status;

    status = 0;
    env = env_2d(mini->env_ll);
    fork_pid = fork();
    if (fork_pid == 0)
    {
        if (execve(cmd[0], cmd, env) == -1)
                exit(127);
    }
    else
        waitpid(fork_pid, &status, 0);
    get_signal_code - status % 255;
    if (WIFSIGNALED(status))
            get_signal_code = (WTERMSIG(status) + 128);
    free(env);
    unlink(".tmp");
    return ;
}