/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:38 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/11 18:35:56 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"

//All MACROS
# define SPACE_MINI ' '
# define TAB_MINI '\t'
# define NEW_LINE_MINI '\n'
# define TRUE 1
# define FALSE 0

//External variable to get the signal
extern int  g_exit_code;

//link_list for env
typedef struct s_env
{
	char			*key;
	char			*value;
	int				print;
	struct s_env	*next;
}	t_env;

typedef struct s_dollar
{
    char    **env;
    char    *input;
    char    *temp;
    char    *new;
    int     i;
    int     j;
    int     quotes;
}   t_dollar;

typedef struct s_data
{
    char    **command_arr;
    char    **env;
    char    cwd[1042];
    char    **input_arr;
    char    *input;
    char    *new_input;
    int     cmd_exit_no;
    int     heredoc;
    int     err_stat;
    int     fd[2];
    int     in_fd;
    int     out_fd;
    int     term_in;
    int     term_out;
    int     *ll_len;
    pid_t   fork;
    int     stdin; //Test case
    int     stdout; //Test case
    int     flag;
    int     heredoc_zero_if_valid;
    t_env   *env_ll;
    char    **environ; //Test case
    struct  termios ori_terminal;
    struct  termios mod_terminal;
    t_list  *list;
    t_dollar dollar;
    int     first_run_init_dollar;
    struct  s_data  *next;
}   t_data;

//Temporary global variable
extern t_data g_minishell;

//main
char    **copy_env(char **env);

//readline.c
void    print_prompt(t_data *data);

//lexer.c
int     lexer(char *input);
char    *strjoin_helper(char *str1, char *str2, int free1, int free2);

//parser.c
void    parser(t_data *data);

//tokenization.c
void    tokenization(t_data *data, t_list **list);

//split.c
char    **split(char *s);

//check.c
int     check_quotes(char *s);
int     check_pipe(char *s);
int     check_redrct_pipe(char *s);

//add_space.c
void    add_space(t_data *data);
int     copy_quotes(char **new_input, char *input, int position, char target);

//dollar_sign.c
void    dollar_sign(t_data *data);

//count.c
int     calculate_len(char *s, char **env);
int     is_env(char *s, char *env);

//utils.c
int     is_target(char c, char *target);
char    *ft_strjoin_free(char *s1, char *s2);
int     skip_quotes(char *s, int positoin, char target);
int     unprint_index(int i, char *str);
void    skip_unprint(t_data *data);
int     ft_arrlen(char **arr);

//str_ll.c:
t_env	*list_create( char *key, char *value);
void	insert(t_env **link, t_env *newlist);
t_env	*add_node_end(t_env *head, char *key, char *value, int print);
void	remove_node(t_env **head, char *key);
void	remove_head_node(t_env **head);

//hell_env.c:
t_env	*env_init(char **in);
void	print_env(t_env *env_ll);
char	*get_env(t_env *env_ll, char *what);

// int     input_handle(t_data *data, char **env);
int     input_handle(t_data *data);

//free.c
void    free_data(t_data *data);
void    free_linked_list(t_list **list);
void    free_arr(char **arr);

//Non builtins:
int list_dir(t_data *mini, char *path);
char    *path_array(t_data *mini, char *from_env);
char    **command_make(t_data *mini);
void    not_builtin(t_data *mini, char **cmd);

//builtins:

//cd.c
void    get_pwd(void);
void    errorMsg3(char *builtin, char *msg);
void    err_exit(char *action, int code);
char	*env_val(char *key, t_env *env);
void    ft_cd(t_data *data);

//env.c
void    env(t_data *data);

//env_2d.c
int     count2(t_env *env);
char    **env_2d(t_env *env);

//unset.c
char    **del_env(char **env, char *target);
void    unset(t_data *data, t_list *list, char **env);

//export.c
void    export(t_data *data, t_list *list);


//exec.c
void    exec(t_data *data);
void    ft_exit(t_data *shell, t_list *list);
void    exit_shell(t_data *shell);

//exit.c
void builtin_exit(t_data *shell, t_list *list);

//executable.c
void    executable(t_data *shell, t_list *lst);
char    *resolve_path(char *cmd, char **env);

//echo.c
int     check(char *str);
char	*ret_line(char **arr);
void	echo(t_data *mini);

//Child process
void child_process(t_data *mshell, t_list *lst);

//directory.c
void	pwd_update(t_env *env_ll, char *new_pwd, t_data *mini);
void    home(t_data *mini);

//redirection.c
void	here_doc2(t_data *mshell, t_list *lst, int fd, char *input);
void	here_doc(t_data *mshell, t_list *lst);
void	redirect_setup2(t_list *lst, int i, int status);
void	redirect_setup(t_list *lst, int i, int status);
int     redirection(t_data *mshell, t_list *lst);
// int     right_redirect(t_data *mini, int x, char *valid);
// char    *get_file(char **in, int x);
// int     left_redirect(t_data *mini, int x, char *valid);
// int     redirect_check(t_data *mini, char *valid);

//heredoc.c
int     heredoc_check(t_data *mini);
void    heredoc_run(t_data *mini, char *str);
int     heredoc2(t_data *mini, int x);
char    **mal_dup(t_data *mini);
int     is_redir(char *str);

//pipe.c
void    cmd(t_data *mini, t_data *data, int exit_if_zero);
void    run_dup(int *tmp_read, t_data *mini, t_data *data, t_data *first);
void    run_heredoc(t_data *mini, t_data *data);
void    run_pipes(t_data *mini, t_data *data, t_data *first);
void    run(t_data *mini, t_data *data);

//pipe_utils.c

//pipe_utils2.c


//run_exe.c
int     exit_num(char **in);
void    command_handle(t_data *mini, int exit_if_zero);
int     builtin_check(t_data *mini);
void    array_dup(t_data *mini);

//test
void    print_arr(char **s);
void    pll(t_list *list);

//get_stat.c and signal.c:
/*
    Why use signal?
    Signals help the operating system to communicate with processes and vice-versa. 
    Signals are also generated when processes don’t function properly or try to access prohibited memory. 
    Different signals are mapped to different numbers which are referred to as signal values. 
    The Linux OS implements about 30 standard signals.

    Source: geeksforgeeks



    In minishell project, we just use 3 standard signals:
    1) Ctrl + C: SIGINT (Signal Interrupt)
    2) Ctrl + *: SIGQUIT (Signal Quit)
    3) Ctrl + D: EOF (End of File) 
*/
int     get_stat(int stat);

//signal.c
void    quit_3(int sigquit);
void    quit_subshell(int sigint);
void    signal_int(int sigint);
void    hd_action(int sigint);
void    ft_signal(int flag);
void    flag_0();
void    flag_1();
void    flag_2();


#endif