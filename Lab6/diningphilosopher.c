#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 

#define NUM_PHILOSOPHERS 5

typedef enum {
    THINKING,
    HUNGRY,
    EATING
} PhilosopherState;

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond_vars[NUM_PHILOSOPHERS];
    PhilosopherState states[NUM_PHILOSOPHERS];
} DiningTable;

DiningTable dining_table;

void init_dining_table() {
    pthread_mutex_init(&dining_table.mutex, NULL);

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_cond_init(&dining_table.cond_vars[i], NULL);
        dining_table.states[i] = THINKING;
    }
}

void pickup_forks(int philosopher_id) {
    pthread_mutex_lock(&dining_table.mutex);

    dining_table.states[philosopher_id] = HUNGRY;
    printf("Philosopher %d is hungry.\n", philosopher_id);

    while ((dining_table.states[(philosopher_id + 1) % NUM_PHILOSOPHERS] == EATING) ||
           (dining_table.states[(philosopher_id + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS] == EATING)) {
        pthread_cond_wait(&dining_table.cond_vars[philosopher_id], &dining_table.mutex);
    }

    dining_table.states[philosopher_id] = EATING;
    printf("Philosopher %d is eating.\n", philosopher_id);

    pthread_mutex_unlock(&dining_table.mutex);
}

void return_forks(int philosopher_id) {
    pthread_mutex_lock(&dining_table.mutex);

    dining_table.states[philosopher_id] = THINKING;
    printf("Philosopher %d is thinking.\n", philosopher_id);

    pthread_cond_signal(&dining_table.cond_vars[(philosopher_id + 1) % NUM_PHILOSOPHERS]);
    pthread_cond_signal(&dining_table.cond_vars[(philosopher_id + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS]);

    pthread_mutex_unlock(&dining_table.mutex);
}

void* philosopher(void* arg) {
    int philosopher_id = *((int*)arg);

    while (1) {
        // Think
        printf("Philosopher %d is thinking.\n", philosopher_id);
        sleep(rand() % 3);

        // Pick up forks
        pickup_forks(philosopher_id);

        // Eat
        printf("Philosopher %d is eating.\n", philosopher_id);
        sleep(rand() % 3);

        // Return forks
        return_forks(philosopher_id);
    }

    return NULL;
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_ids[NUM_PHILOSOPHERS];

    init_dining_table();

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}

