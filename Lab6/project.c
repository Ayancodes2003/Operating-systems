#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> 

// Global variables
sem_t mutex, wrt;
int read_count = 0;

// Reader function
void *reader(void *arg) {
    int reader_id = *((int *)arg);

    while (1) {
        // Entering critical section
        sem_wait(&mutex);
        read_count++;
        if (read_count == 1) {
            sem_wait(&wrt);
        }
        sem_post(&mutex);

        // Reading the file
        printf("Reader %d is reading the file.\n", reader_id);

        // Exiting critical section
        sem_wait(&mutex);
        read_count--;
        if (read_count == 0) {
            sem_post(&wrt);
        }
        sem_post(&mutex);

        // Sleep for some time before reading again
        sleep(rand() % 3);
    }

    return NULL;
}

// Writer function
void *writer(void *arg) {
    int writer_id = *((int *)arg);

    while (1) {
        // Entering critical section
        sem_wait(&wrt);

        // Writing to the file
        printf("Writer %d is updating the file.\n", writer_id);

        // Exiting critical section
        sem_post(&wrt);

        // Sleep for some time before writing again
        sleep(rand() % 3);
    }

    return NULL;
}

int main() {
    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Create threads for readers and writers
    pthread_t readers[4], writers[4];
    int ids[4] = {1, 2, 3, 4};

    for (int i = 0; i < 4; i++) {
        pthread_create(&readers[i], NULL, reader, &ids[i]);
        pthread_create(&writers[i], NULL, writer, &ids[i]);
    }

    // Join threads
    for (int i = 0; i < 4; i++) {
        pthread_join(readers[i], NULL);
        pthread_join(writers[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}

