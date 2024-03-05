#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int commonVariable = 9;

void childProcess() {
    printf("Child process:\n");
    printf("Common variable value before modification: %d\n", commonVariable);
    commonVariable += 5;
    printf("Common variable value after modification: %d\n", commonVariable);
    printf("Child process ID: %d\n", getpid());
}

void parentProcess() {
    printf("Parent process:\n");
    printf("Common variable value before modification: %d\n", commonVariable);
    commonVariable -= 4;
    printf("Common variable value after modification: %d\n", commonVariable);
    printf("Parent process ID: %d\n", getpid());
}

int main() {
    printf("Before fork:\n");
    printf("Common variable value: %d\n", commonVariable);
    printf("Parent process ID: %d\n", getpid());
    pid_t pid = fork();
    
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        childProcess();
    } else {
        parentProcess();
    }
    
    return 0;
}
