#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
void *checkoddeven(void *arg) {
    int num = *((int *)arg);
    printf("Odd/Even Thread ID: %ld\n", pthread_self());
    if (num % 2 == 0) {
        printf("%d is an even number\n", num);
    } else {
        printf("%d is an odd number\n", num);
    }
    pthread_exit(NULL);
}

void *checkprime(void *arg) {
    int num = *((int *)arg);
    printf("Prime Thread ID: %ld\n", pthread_self());
    int p= 1;
    if (num <= 1) {
        p= 0;
    } else {
        for (int i = 2; i <= num/2; i++) {
            if (num % i == 0) {
                p= 0;
                break;
            }
        }
    }
    if (p) {
        printf("%d is a prime number\n", num);
    } else {
        printf("%d is not a prime number\n", num);
    }
    pthread_exit(NULL);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    pthread_t tid1, tid2;
    if (pthread_create(&tid1, NULL, checkoddeven, &n) != 0) {
        perror("pthread_create");
        return 1;
    }
    if (pthread_create(&tid2, NULL, checkprime, &n) != 0) {
        perror("pthread_create");
        return 1;
    }
    if (pthread_join(tid1, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }
    if (pthread_join(tid2, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }
}
