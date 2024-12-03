/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:57 by yyan-bin          #+#    #+#             */
/*   Updated: 2024/12/03 20:02:58 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char *readline(const char *prompt)
{
    printf("%s", prompt); // Display the prompt
    (void)prompt;
    size_t bufsize = 128;
    char *buffer = malloc(bufsize);
    if (!buffer) {
        perror("Unable to allocate buffer");
        return NULL;
    }

    if (fgets(buffer, bufsize, stdin) == NULL) {
        free(buffer);
        return NULL; // Handle EOF
    }

    size_t len = strlen(buffer);
    if (buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0'; // Remove trailing newline
    }

    return buffer; // Caller must free this memory
}

void    input_handler(const char *input, char **env)
{
    (void)env;
    ft_printf("%s\n", input);
}

int ft_quotes(int i, char *str)
{
    if (!str[i] || str[i] != '"')
        return (-1);
    i++;
    while (str[i] && str[i] != '"')
        i++;
    if (!str[i])
        return (-1);
    return (i + 1);
}

int skip_unprint(int i, char *str)
{
    if (!str)
        return (-1);
    while (str[i] && !(str[i] <= '~' && str[i] > ' '))
        i++;
    return (i);
}

char    *copy_input(char *input)
{
    int i;
    int j;
    char    *copy;

    if (!input)
        return (NULL);
    i = skip_unprint(0, input);
    j = 0;
    while (input[i + j])
    {
        if (input[i + j] == '#')
            break ;
        j++;
    }
    copy = ft_substr(input, i, j);
    return (copy);
}
