#include <stdio.h>
#include <limits.h>

#define MAX_V 10

int min(int x, int y) {
    return (x < y) ? x : y;
}

int tsp(int graph[][MAX_V], int numVertices, int mask, int pos, int dp[][MAX_V], int *path) {
    if (mask == (1 << numVertices) - 1) return graph[pos][0];
    if (dp[mask][pos] != -1) return dp[mask][pos];
    int minCost = INT_MAX, next = -1;
    for (int city = 0; city < numVertices; city++) {
        if ((mask & (1 << city)) == 0) {
            int newCost = graph[pos][city] + tsp(graph, numVertices, mask | (1 << city), city, dp, path);
            if (newCost < minCost) { minCost = newCost; next = city; }
        }
    }
    dp[mask][pos] = minCost;
    path[pos] = next;
    return minCost;
}

int main() {
    int numVertices;
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    int graph[MAX_V][MAX_V];
    printf("Enter the adjacency matrix (%d x %d):\n", numVertices, numVertices);
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++) {
            printf("Enter weight for edge (%d, %d): ", i, j);
            scanf("%d", &graph[i][j]);
        }

    int dp[1 << MAX_V][MAX_V], path[MAX_V];
    for (int i = 0; i < (1 << MAX_V); i++)
        for (int j = 0; j < numVertices; j++)
            dp[i][j] = -1;
    int startCity = 0, mask = 1 << startCity;
    int minCost = tsp(graph, numVertices, mask, startCity, dp, path);

    printf("Minimum cost: %d\n", minCost);
    printPath(path, numVertices);

    return 0;
}
