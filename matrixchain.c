#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

void printOptimalParenthesis(int splitMatrix[][MAX_SIZE], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesis(splitMatrix, i, splitMatrix[i][j]);
        printOptimalParenthesis(splitMatrix, splitMatrix[i][j] + 1, j);
        printf(")");
    }
}

void matrixChainOrder(int dimensions[], int n) {
    int costMatrix[MAX_SIZE][MAX_SIZE];
    int splitMatrix[MAX_SIZE][MAX_SIZE];
    int i, j;

    for (i = 1; i <= n; i++) {
        costMatrix[i][i] = 0;
    }

    for (int length = 2; length <= n; length++) {
        for (i = 1; i <= n - length + 1; i++) {
            j = i + length - 1;
            costMatrix[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int tempCost = costMatrix[i][k] + costMatrix[k + 1][j] + (dimensions[i - 1] * dimensions[k] * dimensions[j]);
                if (tempCost < costMatrix[i][j]) {
                    costMatrix[i][j] = tempCost;
                    splitMatrix[i][j] = k;
                }
            }
        }
    }

    printf("The Cost Matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d\t", costMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Minimum number of comparisons: %d\n", costMatrix[1][n]);
    printf("Optimal Parenthesis: ");
    printOptimalParenthesis(splitMatrix, 1, n);
    printf("\n");
}

int main() {
    int dimensions[] = {10, 20, 30, 40};
    int size = sizeof(dimensions) / sizeof(dimensions[0]);
    matrixChainOrder(dimensions, size);
    return 0;
}
