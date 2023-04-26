#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *args[2];
    int status;
    pid_t pid;

    while (1) {
        printf("$ ");
        nread = getline(&line, &len, stdin);
        if (nread == -1) {
            if (feof(stdin)) {
                exit(EXIT_SUCCESS);
            } else {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }
        if (line[nread-1] == '\n') {
            line[nread-1] = '\0';
        }
        args[0] = line;
        args[1] = NULL;
        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            /* Child process */
            if (execve(args[0], args, NULL) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else {
            /* Parent process */
            if (wait(&status) == -1) {
                perror("wait");
                exit(EXIT_FAILURE);
            }
        }
    }
    return 0;
}
