#include <stdio.h>

typedef struct {
    int arrivalTime;     // Arrival time of the person
    int burstTime;       // Time required to buy the ticket
    int waitingTime;     // Waiting time for the person
    int turnaroundTime;  // Turnaround time for the person
} Person;

void calculateTimes(Person queue[], int n) {
    int waitingTime[n], turnaroundTime[n];
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    waitingTime[0] = 0;
    for (int i = 1; i < n; i++) {
        waitingTime[i] = queue[i - 1].burstTime + waitingTime[i - 1];
        totalWaitingTime += waitingTime[i];
    }

    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = queue[i].burstTime + waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    printf("Gantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| Person%d ", i + 1);
    }
    printf("|\n");

    printf("Waiting Time:\n");
    for (int i = 0; i < n; i++) {
        printf("|    %d    ", waitingTime[i]);
    }
    printf("|\n");

    printf("Turnaround Time:\n");
    for (int i = 0; i < n; i++) {
        printf("|    %d    ", turnaroundTime[i]);
    }
    printf("|\n");

    float avgWaitingTime = (float)totalWaitingTime / n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2f", avgWaitingTime);
    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime);
}

int main() {
    int n;

    printf("Enter the number of people in the queue: ");
    scanf("%d", &n);

    Person queue[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for Person %d: ", i + 1);
        scanf("%d%d", &queue[i].arrivalTime, &queue[i].burstTime);
    }

    calculateTimes(queue, n);

    return 0;
}

