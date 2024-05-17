#include <stdio.h>
#include <stdlib.h>

#define MAX_JOBS 10

struct Job {
    int id;
    int deadline;
    int profit;
};

int compare(const void *a, const void *b) {
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

void jobScheduling(struct Job arr[], int n) {
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].deadline > maxDeadline)
            maxDeadline = arr[i].deadline;
    }
    struct Job result[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        result[i].id = -1;

    for (int i = 0; i < n; i++) {
        int j = arr[i].deadline - 1;
        while (j >= 0 && result[j].id != -1)
            j--;
        if (j >= 0)
            result[j] = arr[i];
    }

    int totalProfit = 0;
    printf("Scheduled Jobs:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i].id != -1) {
            printf("Job ID: %d, Deadline: %d, Profit: %d\n", result[i].id, result[i].deadline, result[i].profit);
            totalProfit += result[i].profit;
        }
    }
    printf("Total Profit: %d\n", totalProfit);
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    struct Job arr[MAX_JOBS];
    printf("Enter job details (id, deadline, profit):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &arr[i].id, &arr[i].deadline, &arr[i].profit);
    }
    qsort(arr, n, sizeof(struct Job), compare);
    jobScheduling(arr, n);
    return 0;
}
