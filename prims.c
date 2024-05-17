#include <stdio.h>
#include <string.h>

#define INF 999
#define MAX 10

int Graph[MAX][MAX];

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    if (V > MAX) {
        printf("The number of vertices should not exceed %d\n", MAX);
        return 1;
    }

    int selected[MAX];
    memset(selected, 0, sizeof(selected));

    int no_edge = 0;
    selected[0] = 1;  // Mark the first vertex as selected
    int x = 0, y = 0;

    printf("Enter the adjacency matrix for the graph (use %d for no edge):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("Enter weight for edge (%d, %d): ", i + 1, j + 1);
            scanf("%d", &Graph[i][j]);
        }
    }

    printf("Edge : Weight\n");
    int totalCost = 0;
    while (no_edge < V - 1) {
        int min = INF;
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && Graph[i][j] && Graph[i][j] < min) {
                        min = Graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x + 1, y + 1, Graph[x][y]);
        totalCost += Graph[x][y];
        selected[y] = 1;
        no_edge++;
    }

    printf("Total Cost of Minimum Spanning Tree: %d\n", totalCost);

    return 0;
}
