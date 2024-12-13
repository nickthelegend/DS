#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100 // Maximum number of nodes

int A[MAX_NODES][MAX_NODES]; // Adjacency matrix
int visited[MAX_NODES];      // Visited array

void DFS(int start, int n) {
    int stack[MAX_NODES]; // Stack to store nodes
    int top = -1;         // Stack pointer

    // Push the starting node onto the stack
    stack[++top] = start;
    visited[start] = 1;

    printf("DFS Traversal: ");

    while (top != -1) {
        int node = stack[top--]; // Pop a node from the stack
        printf("%d ", node);

        // Traverse all adjacent nodes
        for (int j = n - 1; j >= 0; j--) { // Reverse order for correct traversal
            if (A[node][j] == 1 && !visited[j]) {
                stack[++top] = j; // Push unvisited node onto the stack
                visited[j] = 1;   // Mark as visited
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Initialize visited array
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

    printf("Enter the starting node: ");
    scanf("%d", &start);

    DFS(start, n);

    return 0;
}
