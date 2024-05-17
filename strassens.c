#include <stdio.h>
#include <stdlib.h>

void addMatrices(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassenMultiply(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int P1[newSize][newSize], P2[newSize][newSize], P3[newSize][newSize], P4[newSize][newSize], P5[newSize][newSize], P6[newSize][newSize], P7[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // Divide matrices A and B into 4 submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculate the 7 products recursively
    subtractMatrices(newSize, B12, B22, temp1);
    strassenMultiply(newSize, A11, temp1, P1);

    addMatrices(newSize, A11, A12, temp1);
    strassenMultiply(newSize, temp1, B22, P2);

    addMatrices(newSize, A21, A22, temp1);
    strassenMultiply(newSize, temp1, B11, P3);

    subtractMatrices(newSize, B21, B11, temp1);
    strassenMultiply(newSize, A22, temp1, P4);

    addMatrices(newSize, A11, A22, temp1);
    addMatrices(newSize, B11, B22, temp2);
    strassenMultiply(newSize, temp1, temp2, P5);

    subtractMatrices(newSize, A12, A22, temp1);
    addMatrices(newSize, B21, B22, temp2);
    strassenMultiply(newSize, temp1, temp2, P6);

    subtractMatrices(newSize, A11, A21, temp1);
    addMatrices(newSize, B11, B12, temp2);
    strassenMultiply(newSize, temp1, temp2, P7);

    // Calculate the resulting submatrices
    addMatrices(newSize, P5, P4, temp1);
    subtractMatrices(newSize, temp1, P2, temp2);
    addMatrices(newSize, temp2, P6, C11);

    addMatrices(newSize, P1, P2, C12);
    addMatrices(newSize, P3, P4, C21);

    addMatrices(newSize, P5, P1, temp1);
    subtractMatrices(newSize, temp1, P3, temp2);
    subtractMatrices(newSize, temp2, P7, C22);

    // Combine the resulting submatrices into the final matrix C
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

void printMatrix(int n, int mat[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void inputMatrix(int n, int mat[][n]) {
    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the matrices (must be a power of 2): ");
    scanf("%d", &n);

    int X[n][n], Y[n][n], Z[n][n];
    printf("Enter the first matrix:\n");
    inputMatrix(n, X);
    printf("Enter the second matrix:\n");
    inputMatrix(n, Y);
    strassenMultiply(n, X, Y, Z);
    printf("\nResult of matrix multiplication:\n");
    printMatrix(n, Z);
    
    return 0;
}
