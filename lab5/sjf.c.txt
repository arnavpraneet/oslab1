#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 100

// Structure to represent a process
struct Process {
    int id;
    int arrival_time;
    int burst_time;
};

// Function to find the next process to execute
int findNextProcess(struct Process processes[], int size, int current_time) {
    int min_burst_time = INT_MAX;
    int chosen_index = -1;

    for (int i = 0; i < size; i++) {
        if (processes[i].arrival_time <= current_time && 
            processes[i].burst_time < min_burst_time && 
            processes[i].burst_time > 0) {
            min_burst_time = processes[i].burst_time;
            chosen_index = i;
        }
    }

    return chosen_index;
}

// Function to sort the processes by arrival time
void sortProcessesByArrivalTime(struct Process processes[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main(){
    struct Process processes[MAX_SIZE];
    int size = 0;
    printf("Enter the number of processes (Max 100): ");
    scanf("%d", &size);
    for(int i = 0; i<size; i++){
        printf("\nEnter arrival time for process %d: ", i+1);
        scanf("%d", &processes[i].arrival_time);
        printf("\nEnter burst time for process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i+1;
    }

    // Sort the processes by arrival time
    sortProcessesByArrivalTime(processes, size);

    int waiting_time[MAX_SIZE] = {0};
    int turnaround_time[MAX_SIZE] = {0};
    int completion_time[MAX_SIZE] = {0};
    int total_wt = 0;
    int total_tat = 0;

    // Initialize current_time to the arrival_time of the first process
    int current_time = processes[0].arrival_time;

    while (1) {
        int index = findNextProcess(processes, size, current_time);
        if (index == -1) {
            break;
        }

        // If the current time is less than the arrival time of the chosen process,
        // increment the current time to the arrival time of the next process.
        if (current_time < processes[index].arrival_time) {
            current_time = processes[index].arrival_time;
        }

        waiting_time[index] = current_time - processes[index].arrival_time;
        current_time += processes[index].burst_time;
        completion_time[index] = current_time;
        turnaround_time[index] = completion_time[index] - processes[index].arrival_time;
        processes[index].burst_time = 0;
    }

    for (int i = 0; i < size ; i++) {
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
        printf("\n ---------Process %d --------- ", processes[i].id);
        printf("\nWaiting time: %d", waiting_time[i]);
        printf("\nTurnaround time: %d", turnaround_time[i]);
        printf("\nCompletion time: %d", completion_time[i]);
    }

    printf("\nAverage waiting time: %.2f", (float)total_wt / size);
    printf("\nAverage turnaround time: %.2f", (float)total_tat / size);

    return 0;
}