#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("fork failed");
        return 1;
    } else if (child_pid == 0) {
        // Child process
        printf("Child process (PID=%d) is running with parent (PPID=%d)\n", getpid(), getppid());
        sleep(5); // Simulate some work
        printf("Child process (PID=%d) is now an orphan with parent (PPID=%d)\n", getpid(), getppid());
        printf("Orphan process (PID=%d) is adopted by the init process (PPID=1)\n", getpid());
        sleep(5); // Simulate some work as an orphan
    } else {
        // Parent process
        printf("Parent process (PID=%d) is terminating\n", getpid());
    }

    return 0;
}
