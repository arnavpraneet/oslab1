#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Process {
    int id;
    int arrival_time;
    int burst_time;
};

int compare(const void* a, const void* b) {
    struct Process* p1 = (struct Process*)a;
    struct Process* p2 = (struct Process*)b;
    return p1->arrival_time - p2->arrival_time;
}

int main(){
    struct Process processes[MAX_SIZE];
    int size = 0;
    printf("Enter the number of processes (Max 100): ");
    scanf("%d", &size);
    for(int i = 0; i<size; i++){
        printf("Enter arrival time for process %d: ", i+1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i+1;
    }

    qsort(processes, size, sizeof(struct Process), compare);

    int waiting_time[MAX_SIZE];
    int turnaround_time[MAX_SIZE];
    int completion_time[MAX_SIZE];
    int total_wt = 0;
    int total_tat = 0;

    waiting_time[0] = 0;
    completion_time[0] = processes[0].burst_time;

    for (int i = 1; i < size ; i++ ) {
        waiting_time[i] = completion_time[i-1] - processes[i].arrival_time;
        waiting_time[i] = waiting_time[i] < 0 ? 0 : waiting_time[i];
        completion_time[i] = waiting_time[i] + processes[i].burst_time + processes[i].arrival_time;
    }

    for (int i = 0; i < size ; i++) {
        turnaround_time[i] = completion_time[i] - processes[i].arrival_time;
        total_wt = total_wt + waiting_time[i];
        total_tat = total_tat + turnaround_time[i];
        printf("\n ---------Process %d --------- ", processes[i].id);
        printf("\nWaiting time: %d", waiting_time[i]);
        printf("\nTurnaround time: %d", turnaround_time[i]);
        printf("\nCompletion time: %d", completion_time[i]);
    }

    printf("\nAverage waiting time: %.2f", (float)total_wt / size);
    printf("\nAverage turnaround time: %.2f", (float)total_tat / size);

    return 0;
}