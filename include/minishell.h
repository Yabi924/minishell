/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:38 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/12 20:34:23 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <dirent.h>
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
extern int  get_signal_code;

//link_list for env
typedef struct s_env
{
	char			*key;
	char			*value;
	int				print;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
    char    **command_arr;
    char    **env;
    char    *input;
    char    cwd[1042];
    char    *new_input;
    int     cmd_exit_no;
    int     heredoc;
    int     in_fd;
    int     out_fd;
    int     flag;
    t_env   *env_ll;
    struct  termios ori_terminal;
    struct  termios mod_terminal;
    t_list  *list;
}   t_data;

//readline.c
void    print_prompt(t_data *data);

//lexer.c
int     lexer(char *input);

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
char    *explan_dollar_sign(char *s, char **env);

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

// int     input_handle(t_data *data, char **env);
int     input_handle(t_data *data);

//signal.c
void    signal_int(int signal_no);

//free.c
void    free_data(t_data *data);
void    free_linked_list(t_list **list);
void    free_arr(char **arr);

//Initialization
void    init(t_data *data, char **env);
// create_env.c
char    **copy_env(char **env);
void    setup_env(t_data *data, char **env);

// Function Prototypes
void free_env(char **env);
void setup_env(t_data *data, char **env);
void update_env(const char *key, const char *value);
char *env_val(const char *key, char **env);

//builtins
void    ft_exit(t_data *shell, t_list *list);

//Child process
void child_process(t_data *mshell, t_list *lst);

//ft_echo.c
int     check(char *str);
char	*ret_line(char **arr);
void	echo(t_data *mini);

//directory.c
void    get_pwd(void);
void    assign_oldpwd(t_env *env_ll, char *pwd, t_data *mini);
void	pwd_update(t_env *env_ll, char *new_pwd, t_data *mini);
void    home(t_data *mini);
void    change_dir(t_data *mini);

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

void    signal_int(int signal_no);
void    signal_quit(int signal_no);
void    signal_int_child(int signal_no);
void    signal_quit_child(int signal_no);
void    heredoc(int signo);


#endif