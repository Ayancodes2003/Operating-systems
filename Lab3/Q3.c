#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void childProcess(int processNumber, int sleepTime) {
    printf("Child Process %d: Start\n", processNumber);
    sleep(sleepTime);
    printf("Child Process %d: Terminated\n", processNumber);
    exit(0);
}

int main() {
    int i;

    printf("Parent Process: Start\n");

    for (i = 1; i <= 4; i++) {
        pid_t child_pid = fork();

        if (child_pid < 0) {
            perror("fork error");
            exit(1);
        } else if (child_pid == 0) {
            // Child process
            if (i == 1) {
                childProcess(1, 5);
            } else if (i == 2) {
                sleep(3);
                childProcess(2, 2);
            } else if (i == 3) {
                sleep(1);
                childProcess(3, 4);
            } else if (i == 4) {
                sleep(2);
                childProcess(4, 3);
            }
        }
    }

    // Wait for the 4th child process to terminate
    waitpid(-1, NULL, 0);

    printf("Parent Process: Terminated\n");

    return 0;
}

