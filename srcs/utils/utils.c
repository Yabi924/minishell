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