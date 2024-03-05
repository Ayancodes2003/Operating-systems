/*#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
void childProcess(int processId) {
    printf("Child process %d: Started\n", processId);
    sleep(processId);
    printf("Child process %d: Terminated\n", processId);
    exit(0);
}

int main() {
    pid_t childPid[4];
    int i;
    for (i = 0; i < 4; i++) {
        childPid[i] = fork();
        if (childPid[i] == 0) {

            childProcess(i + 1);
        } else if (childPid[i] < 0) {
            fprintf(stderr, "Fork failed\n");
            return 1;
        }
    }
    waitpid(childPid[4], NULL, 0);
    for (i = 0; i < 4; i++) {
        wait(NULL);
    }
    printf("Parent process: Terminated\n");

    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childProcess(int id, int delay) {
    printf("Child process %d is running.\n",id);

    sleep(delay);

    printf("Child process %dis terminating.\n",id);
    exit(0);
}

int main() {
    int i;
    pid_t child_pid;

    
    for (i = 1; i <= 4; ++i) {
        child_pid = fork();

        if (child_pid == -1) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (child_pid == 0) {
            switch (i) {
                case 1:
                    
                    childProcess(i, 3);
                    break;
                case 2:
                    
                    childProcess(i, 2);
                    break;
                case 3:
                    
                    childProcess(i, 1);
                    break;
                case 4:
                    
                    childProcess(i, 4);
                    break;
            }
        }
    }    
    for (i = 0; i < 4; ++i) {
        wait(NULL);
    }

    printf("Parent process is terminating.\n");

    return 0;
}
