#include <stdio.h>

#define N 4

// Function to count inversions in the puzzle
int getInvCount(int *arr)
{
    int inv_count = 0;
    for (int i = 0; i < N * N - 1; i++)
    {
        for (int j = i + 1; j < N * N; j++)
        {
            if (arr[j] && arr[i] && arr[i] > arr[j])
                inv_count++;
        }
    }
    return inv_count;
}

// Function to find the row position of the blank space (0) from the bottom
int findXPosition(int puzzle[N][N])
{
    for (int i = N - 1; i >= 0; i--)
        for (int j = N - 1; j >= 0; j--)
            if (puzzle[i][j] == 0)
                return N - i;
    return -1;
}

// Function to check if the puzzle is solvable
int isSolvable(int puzzle[N][N])
{
    int invCount = getInvCount((int *)puzzle);

    if (N & 1)
        return !(invCount & 1);
    else
    {
        int pos = findXPosition(puzzle);
        if (pos & 1)
            return !(invCount & 1);
        else
            return invCount & 1;
    }
}

// Function to print the puzzle state
void printPuzzle(int puzzle[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%2d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

// Function to create the goal state for an NxN puzzle
void createGoalState(int goal[N][N])
{
    int value = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == N - 1 && j == N - 1)
                goal[i][j] = 0;  // Last element is the blank space
            else
                goal[i][j] = value++;
        }
    }
}

int main()
{
    int puzzle[N][N];
    int goal[N][N];

    // Input the puzzle values from the user
    printf("Enter the puzzle values (4x4 matrix, use 0 for the blank space):\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &puzzle[i][j]);
        }
    }

    // Print the initial puzzle state
    printf("Initial puzzle state:\n");
    printPuzzle(puzzle);

    // Check if the puzzle is solvable
    if (isSolvable(puzzle))
        printf("The puzzle is solvable.\n");
    else
        printf("The puzzle is not solvable.\n");

    // Create and print the final goal state
    createGoalState(goal);
    printf("Goal puzzle state (for reference):\n");
    printPuzzle(goal);

    return 0;
}
