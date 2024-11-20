#include "../include/minishell.h"

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    (void)env;
    ft_printf("minishell>:");
    pause();
    return 0;
}