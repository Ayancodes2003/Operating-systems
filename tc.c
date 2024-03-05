#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
void *threadfunction(void *arg) {
    printf("Thread is running\n");
    sleep(2);
    printf("Thread is done\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, threadfunction, NULL);

    pthread_join(tid, NULL);

    printf("Thread has completed\n");

    return 0;
}

