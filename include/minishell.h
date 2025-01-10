/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:38 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/01/10 20:28:32 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <dirent.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <signal.h>
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

typedef struct s_data
{
    char    **command_arr;
    char    *input;
    char    *new_input;
    int     cmd_exit_no;
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

//utils.c
int     is_target(char c, char *target);
char    *ft_strjoin_free(char *s1, char *s2);
int     skip_quotes(char *s, int positoin, char target);
int     unprint_index(int i, char *str);
void    skip_unprint(t_data *data);
// int     input_handle(t_data *data, char **env);
int     input_handle(t_data *data);

//test
void    print_arr(char **s);
void    pll(t_list *list);

//Initialization
void    init(t_data *data, char **env);
char    *env_val(const char *key, char **env);
void    update_env(const char *key, const char *value);

//test
void    print_arr(char **s);
void    pll(t_list *list);

//Initialization
void    init(t_data *data, char **env);
char    *env_val(const char *key, char **env);
void    update_env(const char *key, const char *value);

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