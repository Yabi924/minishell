#include "../../include/minishell.h"

void    command_updater(t_list **list, int i);

void    command_updater(t_list **list, int i)
{
    t_list  *temp;

    free((*list)->command[i]);
    free((*list)->command[i + 1]);
    while ((*list)->command[i + 2])
    {
        (*list)->command[i] = (*list)->command[i + 2];
        ++i;
    }
    (*list)->command[i] = NULL;
    if ((*list)->command == NULL)
    {
        temp = (*list)->next;
        free_arr((*list)->command);
        free(*list);
        *list = temp;
    }
}
