
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){

    pid_t id;
    int status;

    //    binary path / atg / envp / NULL
    char *arg[] = {"touch", NULL};
    char *path = "/usr/bin/touch";
    
    id = fork();
    if (id == 0) // child
        execve(path,arg,NULL);
    else
    {  // child pid / reference int / NULL
        waitpid(id, &status, 0);
    }
        
    printf("The child exit status is %d\n", status);
    printf("Return to parent (minishell)\n");

    // return exit
}
