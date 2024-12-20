/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:38 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/03 20:02:39 by yyan-bin         ###   ########.fr       */
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

//type 1 command
//type 2 pipe
//type 3 redirection
typedef struct s_token
{
    char *string;
    int type;
    struct s_token *next;
}   t_token;

//use: skip unprint charater and scape
//return: index of last unprint charater or space + 1
//return -1 if empty pointer
int    skip_unprint(int i, char *str);

//use: fine next quotes index
//return: index after double quotes
//return -1 if single quotes
int     ft_quotes(int i, char *str);

//copy input
//skip space and unprint charater before command
//skip after '#'
//return NULL if empty pointer
char    *copy_input(char *input);

void    input_handler(const char *input, char **env);


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