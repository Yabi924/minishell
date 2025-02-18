
#include "../../include/minishell.h"

// #include "../../include/minishell.h"

// void    execve_command(t_data *data, t_list *list)
// {
//     pid_t	p_id;
// 	int		i;
// 	char	**split_cmd; // It splits the PATH into directories, and then concatenates each directory with the command (cmd)
// 	char	*path;

// 	// int main(int ac, char **av, char **env)

// 	// /bin/ls (relative path) /usr/bin/ls (absolute path)  ls (command)

// 	// 1) Test if can access --> access(list->command[0]

// 	// 2) If fail, then get path from ENV
// 	//   a) table->env[i] == "PATH"  (function) = string
//     //   b) ft_split(string, ":")  --> malloc
// 	//   c) string_path = ft_join(path[i], command) --> malloc
// 	//        i) access (string_path)

// 	// 3) If tried everything and still fail, command is
// 	//	msg --> error: command not found

// 	// strerror(errno)

// 	i = -1;
// 	split_cmd = ft_split(list->command[0], ' ');
// 	if (access(list->command[0], F_OK | X_OK) == 0)
// 	{
// 		//idriss part 
// 		//execve
// 		ft_signal(1);
// 		execve(list->command[0], list->command, data->env);
// 		ft_printf("If block");
// 	}
// 	else 
// 	{
// 		ft_printf("Else block");
// 		/*
// 		while ()
// 		{
// 			//add path
// 			//check command is able to run
// 			//if can't to run just show error message
// 		}
// 		*/
// 	}
// 	//idriss part
// 	// execve
	

// 	// if (access(list->command[0], F_OK | X_OK) == 0)
// 	// {
// 	// 	p_id = fork();
// 	// 	if (p_id == 0)
// 	// 	{
// 	// 		malloc
// 	// 		exit()
// 	// 		ft_signal(1);
// 	// 		       // "usr/bin/" + ls         open("./path/folder/map.ber")
// 	// 		execve(list->command[0], list->command, data->env);
// 	// 		ft_printf("Hello1");

// 	// 	}
// 	// 	else if (p_id)
// 	// 	{
// 	// 		waitpid(p_id, &data->cmd_exit_no, 0);
// 	// 		data->cmd_exit_no = WEXITSTATUS(data->cmd_exit_no);
// 	// 		ft_printf("Hello2");
// 	// 	}
// 	// }
// 	// else
// 	// {
// 	// 	ft_putstr_fd("Minishell: ", 2);
// 	// 	perror(list->command[0]);
// 	// 	data->cmd_exit_no = 127;
// 	// 	return ;
// 	// }
// }