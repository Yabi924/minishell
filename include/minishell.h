/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:38 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/27 03:39:37 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# define SPACE_MINI ' '
# define TAB_MINI '\t'
# define NEW_LINE_MINI '\n'

typedef struct s_command
{
    char **command;
    int fd[2];
    int input;
    int output;
    struct s_command *next;
}   t_command;

typedef struct s_data
{
    char    **command_arr;
    char    *input;
    char    *new_input;
    t_command *command;
}   t_data;

void    print_prompt(t_data *data);
int     lexer(char *input);
void    parser(t_data *data);

int     check_quotes(char *s);
int     check_pipe(char *s);
int     check_redrct_pipe(char *s);

int     is_target(char c, char *target);
char    *ft_strjoin_free(char *s1, char *s2);
int     skip_quotes(char *s, int positoin, char target);


//use: skip unprint charater and scape
//return: index of last unprint charater or space + 1
//return -1 if empty pointer
int    unprint_index(int i, char *str);

//copy input
//skip space and unprint charater before command
//return NULL if empty pointer
void    skip_unprint(t_data *data);

int input_handle(t_data *data);


/*
    Coder: Idriss
    Start date: 5/12/2024
    *****This is my part, do not touch anything!*****
*/

//Structure for storing cmd history
typedef struct CommandHistory {
    char *cmd;
    struct CommandHistory *next;
} CommandHistory;

//Define a structure for history management
typedef struct history {
    CommandHistory *head;
} history;



#endif