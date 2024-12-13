#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Queue structure for BFS
typedef struct {
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;

// Function to initialize a queue
void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Enqueue an element
void enqueue(Queue *q, int value) {
    if (q->rear == MAX_NODES - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

// Dequeue an element
int dequeue(Queue *q) {
    int item;
    if (isEmpty(q)) {
        return -1;
    }
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Recursive BFS function
void recursiveBFS(int graph[MAX_NODES][MAX_NODES], int visited[MAX_NODES], Queue *q, int numNodes) {
    if (isEmpty(q)) return; // Base case: if the queue is empty, return

    // Dequeue the current node
    int current = dequeue(q);
    printf("%d ", current);

    // Visit all neighbors of the current node
    for (int i = 0; i < numNodes; i++) {
        if (graph[current][i] == 1 && !visited[i]) { // If there is an edge and not visited
            visited[i] = 1; // Mark as visited
            enqueue(q, i);  // Enqueue the neighbor
        }
    }

    // Recursive call to process the next node in the queue
    recursiveBFS(graph, visited, q, numNodes);
}

int main() {
    int numNodes;
    
    // Input number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    int graph[MAX_NODES][MAX_NODES];

    // Input adjacency matrix
    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int visited[MAX_NODES] = {0}; // Visited array
    Queue q;
    initializeQueue(&q);

    int startNode;
    
    // Input start node for BFS
    printf("Enter the start node for BFS: ");
    scanf("%d", &startNode);

    // Mark the start node as visited and enqueue it
    visited[startNode] = 1;
    enqueue(&q, startNode);

    printf("BFS Traversal: ");
    recursiveBFS(graph, visited, &q, numNodes);

    return 0;
}
