#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &n);

    int blockSize[n];
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < n; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    int m;
    printf("Enter the number of processes: ");
    scanf("%d", &m);

    int processSize[m], allocated[m];
    printf("Enter the size of each process:\n");
    for (int i = 0; i < m; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processSize[i]);
        allocated[i] = -1;
    }

    // Best Fit Allocation
    for (int i = 0; i < m; i++) {
        int bestIndex = -1;
        for (int j = 0; j < n; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIndex == -1 || blockSize[j] < blockSize[bestIndex])
                    bestIndex = j;
            }
        }

        if (bestIndex != -1) {
            allocated[i] = bestIndex;
            blockSize[bestIndex] -= processSize[i];
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

    printf("\nRemaining Block Sizes:\n");
    for (int i = 0; i < n; i++) {
        printf("Block %d: %d\n", i + 1, blockSize[i]);
    }

    return 0;
}
