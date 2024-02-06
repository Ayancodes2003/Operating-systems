#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3, pid4;

    printf("Parent Process: Start\n");

    pid1 = fork();

    if (pid1 < 0) {
        perror("fork error");
        exit(1);
    } else if (pid1 == 0) {
        // First child process
        printf("First Child Process: Start\n");
        printf("First Child Process: Terminated\n");
        exit(0);
    }

    pid2 = fork();

    if (pid2 < 0) {
        perror("fork error");
        exit(1);
    } else if (pid2 == 0) {
        // Second child process
        printf("Second Child Process: Start\n");
        printf("Second Child Process: Terminated\n");
        exit(0);
    }

    pid3 = fork();

    if (pid3 < 0) {
        perror("fork error");
        exit(1);
    } else if (pid3 == 0) {
        // Third child process
        printf("Third Child Process: Start\n");
        printf("Third Child Process: Terminated\n");
        exit(0);
    }

    pid4 = fork();

    if (pid4 < 0) {
        perror("fork error");
        exit(1);
    } else if (pid4 == 0) {
        // Fourth child process
        printf("Fourth Child Process: Start\n");
        printf("Fourth Child Process: Terminated\n");
        exit(0);
    }

    // Wait for the third child process to terminate
    waitpid(pid3, NULL, 0);

    // Wait for the second child process to terminate
    waitpid(pid2, NULL, 0);

    // Wait for the first child process to terminate
    waitpid(pid1, NULL, 0);

    printf("Parent Process: Terminated\n");

    return 0;
}

