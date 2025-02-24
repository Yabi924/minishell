/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:38 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/02/17 18:53:30 by yyan-bin         ###   ########.fr       */
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
# define BUFFER 10000
# define PATH_VAL 4096

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

typedef struct s_split
{
    int i;
    int j;
    int end;
    char *temp;
    int first;
}   t_split;

typedef struct s_data
{
    char    **command_arr;
    char    **env;
    char    cwd[1024];
    char    **input_arr;
    char    *input;
    char    *new_input;
    char    **token;
    int     cmd_exit_no;
    int     heredoc;
    int     err_stat;
    int     fd[2];
    int     in_first;
    int     out_first;
    int     in_fd;
    int     out_fd;
    int     term_in;
    int     term_out;
    int     *ll_len;
    pid_t   fork;
    int     stdin; //Test case
    int     stdout; //Test case
    int     flag;
    int     quote;
    int     heredoc_zero_if_valid;
    t_env   *env_ll;
    char    **environ; //Test case
    struct  termios ori_terminal;
    struct  termios mod_terminal;
    t_list  *list;
    t_dollar dollar;
    t_split split;
    int     first_run_init_dollar;
}   t_data;

//Temporary global variable
extern t_data g_minishell;

//main
char	**copy_env(char **env, int f);

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
char    **split(t_split *split, char *input);

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

//free.c
// void    free_data(t_data *data);
void    free_data(t_data *data);
void    free_linked_list(t_list **list);
void    free_arr(char **arr);
void	free_lst(t_data *mshell, t_list **lst);

//Non builtins:
int list_dir(t_data *mini, char *path);
char    *path_array(t_data *mini, char *from_env);
char    **command_make(t_data *mini);
void    not_builtin(t_data *mini, char **cmd);

//env_2d.c
int     count2(t_env *env);
char    **env_2d(t_env *env);

/*
    main function:
    main.c
*/
// char	**copy_env(char **env);
void	update_env(t_data *data);
void	init_data(t_data *data, char **env);
void    init_list(t_list *list);

/*
    Input handle:
    input_handle.c
*/
int    input_handle(t_data *data);
//int    input_handle(t_data *data);

/*
    Built in functions: Without list
*/
//exit.c
void    ft_exit(t_data *data, t_list *list);
//void    ft_exit(t_data *data);
//env.c
void    ft_env(t_data *data);

//echo.c

int     check(char *data);
char    *retrieve_line(char **data);
void	ft_echo(t_data *data);
void    ft_echo_process1(t_data *data, int *i, int *newline);
void    ft_echo_process2(t_data *data, char *line, int fd, int newline);

//export.c

void    ft_export(t_data *data, t_list *list);

//unset.c

char    **del_env(char **env, char *target);
void    ft_unset(t_data *data, t_list *list, char **env);

//cd.c

void    ft_cd(t_data *data, t_list *list);

//pwd.c

void    ft_pwd(void);

//executable.c

void    transit(t_data *data, t_list *list, pid_t *children);
void    only_built_in(t_data *data, t_list *list);
void    execute_fd_init(t_data *data);
void    ft_execute(t_data *data, t_list *list);
void	transit_end(pid_t *children, t_data *data);

//child_process.c

char	*collect_env(t_data *data, char *env_var);
int     input_config(t_data *data, t_list *list);
void	output_config(t_data *data, t_list *list);
void	command(t_data *data, t_list *list);
void	child_process(t_data *data, t_list *list);

//get_path.c

char    *collect_path(t_data *data, t_list *list);
char    *collect_env(t_data *data, char *env_var);

//add_path.c
char    *ft_getenv(char *s, char **env);
char    *add_path(t_data *data,  char *command);

//add_path.c
char    *ft_getenv(char *s, char **env);
char    *add_path(t_data *data,  char *command);

//Path to execve
void    execve_command(t_data *data, t_list *list);
void    child_parent(t_data *data, t_list *list);

//built_in.c
// void    built_in(t_data *data);
void    built_in(t_data *data, t_list *list);
int     confirm_built_in(t_list *list);

//child_process.c
char	*get_path(t_data *data, t_list *list);
int     input_config(t_data *data, t_list *list);
void    output_config(t_data *data, t_list *list);
void    transit_end(pid_t *children, t_data *data);
void	command(t_data *data, t_list *list);
void	child_process(t_data *data, t_list *list);

//directory.c
void	pwd_update(t_env *env_ll, char *new_pwd, t_data *mini);
void    home(t_data *mini);

//redirection.c
void    redirect_config(t_list *list, int i, int status);
void    redirect_config2(t_list *list, int i, int status);
int     redirection(t_data *data, t_list *list);

//heredoc.c
void    heredoc(t_data *data, t_list *list);
void    heredoc2(t_data *data, t_list *list, int fd, char *input);

//redirect_checker.c
int     check_if_redirect(t_list *list, int i);
int     check_redirect_syntax(t_data *data, t_list *list, int i);

//command_updater.c
void    command_updater(t_list **list, int i);

/*
    Error Message: Tell user what goes wrong
    error_msg_1.c
*/
void	err_msg(t_data *mshell, int exit_status, char *msg, char *arg);

//pipe.c

//run_exe.c
int     exit_num(char **in);
void    command_handle(t_data *mini, int exit_if_zero);
int     builtin_check(t_data *mini);
void    array_dup(t_data *mini);

//test
void    print_arr(char **s);
void    pll(t_list *list);

//signal.c
void    ft_signal(int flag);
void    flag_0();
void    flag_1();
void    flag_2();

//signal2.c
void    quit_3(int sigquit);
void    quit_subshell(int sigint);
void    signal_int(int sigint);
void    hd_action(int sigint);

#endif