/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:38 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/25 21:41:00 by yyan-bin         ###   ########.fr       */
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
    t_command *command;
}   t_data;

void    print_prompt(t_data *data);
int     lexer(char *input);

int check_quotes(char *s);
int check_pipe(char *s);

//use: skip unprint charater and scape
//return: index of last unprint charater or space + 1
//return -1 if empty pointer
int    unprint_index(int i, char *str);

//use: fine next quotes index
//return: index after double quotes
//return -1 if single quotes
// int     ft_quotes(int i, char *str);

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