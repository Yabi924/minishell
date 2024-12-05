/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:33:20 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/12/05 15:34:31 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//This file handle history command: It traces every keystroke you made in shell.

//Remember: Make sure everything is executable. Then, you can norminette.

/*
    Function involves:

    1) void init_history(history *hist);
    2) void add_history(history *hist, char *s);
    3) void rl_clear_history(history *hist);
    4) void process_cmd(const char *cmd, history *hist);
*/

/*

//Structure for storing cmd history
typedef struct CommandHistory {
    char *cmd;
    struct CommandHistory *next;
} CommandHistory;

//Define a structure for history management
typedef struct history {
    CommandHistory *head;
} history;

*/

//1)
void init_history(history *hist)
{
    hist->head = NULL;
}

//2)
void add_history(history *hist, char *s)
{
    //Create a new history node
    //Malloc happens
    CommandHistory *new_node = (CommandHistory *)malloc(sizeof(CommandHistory));
    if (new_node == NULL)
    {
        perror("Failed to allocate memory from history node");
        return;
    }
    
    //Copy the cmd into the new node
    new_node->cmd = ft_strdup(s);
    if (new_node == NULL)
    {
        perror("Failed to copy the cmd string");
        free(new_node); //deallocate the memory
        return;
    }

    //Add the new node at the beginning of the history list
    new_node->next = hist->head;
    hist->head - new_node;
}

//3) This function clears the history list by deleting all of the entries.
void rl_clear_history(history *hist)
{
    CommandHistory *current = hist->head;
    CommandHistory *next_history;

    //Traverse and free each node
    while (current != NULL)
    {
        next_history = current->next;
        free(current->cmd);
        free(current);
        current = next_history;
    }

    //Reset the head pointer to NULL
    hist->head = NULL;
}

//4)
void process_cmd(const char *cmd, history *hist)
{
    
}