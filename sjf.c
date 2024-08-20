#include <stdio.h>

int main() {
    int b[10], i, j, c[10], tat[10], w[10], n, temp;
    int totaltat = 0, totalwt = 0;
    float avgwt, avgtat;

    printf("Enter no of processes:");
    scanf("%d", &n);
    printf("Enter burst time:");

    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    // Sorting burst times in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (b[j] > b[j + 1]) {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }

    c[0] = b[0];
    for (i = 1; i < n; i++) {
        c[i] = c[i - 1] + b[i];
    }

    for (i = 0; i < n; i++) {
        tat[i] = c[i];
        w[i] = tat[i] - b[i];
        totaltat += tat[i];
        totalwt += w[i];
    }

    avgwt = (float) totalwt / n;
    avgtat = (float) totaltat / n;

    printf("Process\t\tBurst\tComp\tTurnarnd\tWaiting\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t%d\t\t%d\t\t%d\n", i, b[i], c[i], tat[i], w[i]);
    }

    printf("\nAverage turnaround time: %.2f", avgtat);
    printf("\nAverage waiting time: %.2f", avgwt);

    return 0;
}
