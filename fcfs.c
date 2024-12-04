#include <stdio.h>

int main() {
    int n, i;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burstTime[n], waitingTime[n], turnaroundTime[n];

    // Input burst times for all processes
    printf("Enter burst times for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    // Calculate waiting time
    waitingTime[0] = 0; // First process has no waiting time
    for (i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }

    // Calculate turnaround time and total times
    for (i = 0; i < n; i++) {
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    // Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    // Display averages
    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);

    return 0;
}
