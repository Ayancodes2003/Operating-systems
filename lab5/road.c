#include <stdio.h>
#include <stdlib.h>

#define MAX_LANES 4
#define TIME_SLICE 3

typedef struct {
    int lane_number;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Vehicle;

void calculateWaitingTime(Vehicle vehicles[], int n) {
    int remaining_time[MAX_LANES];
    int current_time = 0;

    // Initialize remaining_time with the arrival times of vehicles
    for (int i = 0; i < n; i++) {
        remaining_time[i] = vehicles[i].arrival_time;
    }

    while (1) {
        int all_finished = 1;

        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                all_finished = 0;

                if (remaining_time[i] > TIME_SLICE) {
                    current_time += TIME_SLICE;
                    remaining_time[i] -= TIME_SLICE;
                } else {
                    current_time += remaining_time[i];
                    vehicles[i].waiting_time = current_time - vehicles[i].arrival_time;
                    remaining_time[i] = 0;
                }
            }
        }

        if (all_finished)
            break;
    }
}

void calculateTurnaroundTime(Vehicle vehicles[], int n) {
    for (int i = 0; i < n; i++) {
        vehicles[i].turnaround_time = vehicles[i].waiting_time + TIME_SLICE;
    }
}

void displayGanttChart(Vehicle vehicles[], int n) {
    printf("Gantt Chart:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("| Lane %d ", vehicles[i].lane_number);
    }
    printf("|\n");
    printf("--------------------------------------------------\n");
}

void displayResults(Vehicle vehicles[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    printf("\nLane\tWaiting Time\tTurnaround Time\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", vehicles[i].lane_number, vehicles[i].waiting_time, vehicles[i].turnaround_time);
        total_waiting_time += vehicles[i].waiting_time;
        total_turnaround_time += vehicles[i].turnaround_time;
    }

    float average_waiting_time = (float)total_waiting_time / n;
    float average_turnaround_time = (float)total_turnaround_time / n;

    printf("--------------------------------------------\n");
    printf("Average\t%.2f\t\t%.2f\n", average_waiting_time, average_turnaround_time);
}

int main() {
    int n;
    printf("Enter the number of vehicles: ");
    scanf("%d", &n);

    Vehicle vehicles[MAX_LANES];
    for (int i = 0; i < n; i++) {
        vehicles[i].lane_number = i + 1;
        printf("Enter the arrival time for lane %d: ", vehicles[i].lane_number);
        scanf("%d", &vehicles[i].arrival_time);
    }

    calculateWaitingTime(vehicles, n);
    calculateTurnaroundTime(vehicles, n);

    displayGanttChart(vehicles, n);
    displayResults(vehicles, n);

    return 0;
}

