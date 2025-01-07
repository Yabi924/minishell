/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:53:57 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/26 19:14:30 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int lexer(char *input)
{
    if (check_quotes(input))
    {
        ft_printf("quotes\n");
        return (1);
    }
    if (check_pipe(input))
    {
        ft_printf("pipe\n");
        return (1);
    }
    return (0);
}
