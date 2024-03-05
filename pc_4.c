#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        
        printf("Child process (PID: %d, Parent PID: %d) is sleeping.\n", getpid(), getppid());  
        sleep(5);  
        printf("Child process (PID: %d) is running, Parent PID: %d\n", getpid(), getppid());
    } else {
        
        printf("Parent process (PID: %d) created a child process (PID: %d).\n", getpid(), child_pid);

        sleep(2);
        printf("Parent process (PID: %d) is terminating.\n", getpid());
    }

    return 0;
}
