/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:53:57 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/25 19:33:45 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int lexer(char *input)
{
    if (!check_quotes(input))
        return (1);
    // if (!check_pipe(input))
    //     return (1);
    // if (!check_double_pipe(input));
    //     return (1);
}
