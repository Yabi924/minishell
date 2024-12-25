/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:00:27 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/25 19:54:23 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void    print_prompt(t_data *data)
{
    char    *input;
    input = readline("Minishell > ");
    if (!input)
    {
        ft_putstr_fd("exit", 1);
        exit(0);//will update to free before exit
    }
    if (input && input[0])
        add_history(input);
    data->input = ft_strdup(input);
    free(input);
}
