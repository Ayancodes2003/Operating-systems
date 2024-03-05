#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid > 0) {
        printf("Parent process: Started\n");
        printf("Parent process ID %d:%d\n", getpid(),child_pid);
        sleep(5);
        printf("Parent process: Terminating\n");
    } else if (child_pid == 0) {
        printf("Child process: Started\n");
        printf("Child process ID: %d\n", getpid());
        printf("Child process's parent ID %d:%d\n", getpid(),child_pid);
        sleep(10);
        printf("Child process: Terminating\n");
    } else {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }
    return 0;
}

