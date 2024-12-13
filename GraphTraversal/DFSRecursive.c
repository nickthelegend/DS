#include <stdio.h>

#define MAX_NODES 100 // Maximum number of nodes

int A[MAX_NODES][MAX_NODES]; // Adjacency matrix
int visited[MAX_NODES];      // Visited array

void DFS(int node, int n) {
    printf("%d ", node);
    visited[node] = 1;
    for (int j = 0; j < n; j++) {
        if (A[node][j] == 1 && !visited[j]) {
            DFS(j, n);
        }
    }
}

int main() {
    int n, start;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Initialize visited array to 0
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Input adjacency matrix
    printf("Enter the adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    printf("DFS traversal:\n");
    DFS(start, n);

    return 0;
}
