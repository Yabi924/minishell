#include "../include/minishell.h"

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    (void)env;
    char *input;

    //sigaction(ctrl+C);
    while (1)
    {
        input = readline("minishell:> ");
        if (!input)
        {
            ft_printf("exit\n");
            break ;
        }
        else if (*input)
            add_history(input);
        input_handler(input, env);
        free(input);
    }
    return (0);
}