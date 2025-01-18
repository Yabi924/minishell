

#include "../../include/minishell.h"

static char *find_command(char *cmd, char **env)
{
    char *path_env = NULL;
    char **paths = NULL;
    char *full_path = NULL;
    int i;

    // Get the PATH variable from the environment
    for (i = 0; env[i]; i++) {
        if (strncmp(env[i], "PATH=", 5) == 0) {
            path_env = env[i] + 5;
            break;
        }
    }

    if (!path_env) // No PATH in environment
        return NULL;

    // Split PATH into directories
    paths = ft_split(path_env, ':');
    if (!paths)
        return NULL;

    // Search for the command in each directory
    for (i = 0; paths[i]; i++) {
        full_path = ft_strjoin(paths[i], "/");
        if (!full_path)
            break;
        full_path = ft_strjoin_free(full_path, cmd); // Append command to directory
        if (!full_path)
            break;
        if (access(full_path, F_OK | X_OK) == 0) { // Command found
            free(paths); // Free paths array
            return full_path;
        }
        free(full_path);
    }

    free(paths); // Free paths array
    return NULL; // Command not found
}

// Executes a command
void executable(t_data *shell, t_list *lst)
{
    pid_t p_id;
    char *cmd_path;

    cmd_path = find_command(lst->command[0], shell->env);
    if (!cmd_path) {
        ft_putstr_fd("Minishell: ", 2);
        perror(lst->command[0]);
        shell->cmd_exit_no = 127;
        return;
    }

    p_id = fork();
    if (p_id == 0) { // Child process
        execve(cmd_path, lst->command, shell->env);
        perror("execve"); // If execve fails
        exit(1);
    } else if (p_id > 0) { // Parent process
        waitpid(p_id, &shell->cmd_exit_no, 0);
        shell->cmd_exit_no = WEXITSTATUS(shell->cmd_exit_no);
    } else {
        perror("fork");
    }

    free(cmd_path);
}