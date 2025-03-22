#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int node, bool *visited, int **adjMatrix, int n, int *size, int *edgeCount) {
    visited[node] = true;
    (*size)++; // Count number of nodes in the component
    
    for (int neighbor = 0; neighbor < n; neighbor++) {
        if (adjMatrix[node][neighbor]) {
            (*edgeCount)++; // Count edges
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adjMatrix, n, size, edgeCount);
            }
        }
    }
}

int countCompleteComponents(int n, int** edges, int edgesSize, int* edgesColSize) {
    // Create adjacency matrix
    int **adjMatrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = (int *)calloc(n, sizeof(int));
    }

    // Fill adjacency matrix
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    bool *visited = (bool *)calloc(n, sizeof(bool));
    int completeComponents = 0;

    // Perform DFS on each unvisited node
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int size = 0, edgeCount = 0;
            dfs(i, visited, adjMatrix, n, &size, &edgeCount);

            // A complete component must have exactly `size * (size - 1) / 2` edges
            if (edgeCount / 2 == size * (size - 1) / 2) {
                completeComponents++;
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    free(visited);

    return completeComponents;
}
