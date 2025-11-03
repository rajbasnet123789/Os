#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &n);
    int blockSize[n];
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter the size of block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    int m;
    printf("Enter the number of processes: ");
    scanf("%d", &m);
    int processSize[m], allocated[m];
    for (int i = 0; i < m; i++) {
        printf("Enter the size of process %d: ", i + 1);
        scanf("%d", &processSize[i]);
        allocated[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocated[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < m; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocated[i] != -1)
            printf("%d\n", allocated[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
