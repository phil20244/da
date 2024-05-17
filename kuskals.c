#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int parent[MAX_VERTICES];
int rank[MAX_VERTICES];

void makeSet(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find(int v) {
    if (parent[v] != v)
        parent[v] = find(parent[v]);
    return parent[v];
}

void Union(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

void kruskalMST(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    int edgeCount = 0;
    int minWeight = 0;

    for (int i = 0; i < V; i++)
        makeSet(i);

    while (edgeCount < V - 1) {
        int min = 99; 
        int a = -1, b = -1;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(i) != find(j) && graph[i][j] && graph[i][j] < min) {
                    min = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (a != -1 && b != -1) {
            Union(a, b);
            printf("%d - %d : %d", a, b, min);
            minWeight += min;
            edgeCount++;
        }
    }

    printf("Total Cost of Minimum Spanning Tree: %d\n", minWeight);
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("Enter weight for edge (%d, %d): ", i+1, j+1);
            scanf("%d", &graph[i][j]);
        }
    }
    kruskalMST(graph, V);

    return 0;
}
