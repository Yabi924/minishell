#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>


//test readline function
//compile: cc test.c -I/usr/include/readline -lreadline


// int main() {
//     char *input;

//     while (1) {
//         // Display prompt and read input
//         input = readline("shell> ");

//         if (!input) { // Exit on EOF (Ctrl+D)
//             printf("\nExiting shell.\n");
//             break;
//         }
//         if (*input) { // Add non-empty input to history
//             add_history(input);
//         }
//         printf("You entered: %s\n", input);
//         free(input); // Free dynamically allocated memory
//     }

//     return 0;
// }

int main()
{
    char *s1 = "12345#12345";

    int i = skip_unprint(0, s1);
    int j = 0;
    while (s1[i + j])
    {
        if (s1[i + j] == '#')
            break ;
        j++;
    }
    printf("%s\n", ft_substr(s1, i, i + j));
    return 0;
}