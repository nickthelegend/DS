#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN

// Structure to represent a node in the queue
struct node {
    int data;
    struct node* next;
};

// Initialize front and rear pointers and size of the queue
struct node* front = NULL;
struct node* rear = NULL;
int size = 0;

// Function to enqueue an element to the queue
void enqueue(int item) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); // Create a new node
    newNode->data = item;  // Set the data of the new node
    newNode->next = NULL;  // Set the next pointer to NULL

    if (front == NULL) {
        // If the queue is empty, set both front and rear to the new node
        front = rear = newNode;
    } else {
        // Add the new node to the end of the queue and update the rear
        rear->next = newNode;
        rear = newNode;
    }

    size++;  // Increase the size of the queue
    printf("%d enqueued to queue\n", item);
}

// Function to dequeue an element from the queue
int dequeue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return INT_MIN;  // Return an indicator of an empty queue
    }

    // Store the value of the node to be dequeued
    struct node* temp = front;
    int dequeuedValue = temp->data;
    front = front->next;  // Move front to the next node

    // If the queue becomes empty after dequeuing, update rear to NULL
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);  // Free the memory of the dequeued node
    size--;  // Decrease the size of the queue
    return dequeuedValue;
}

// Function to get the element at the front of the queue without removing it
int peek() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return INT_MIN;  // Return an indicator of an empty queue
    }
    return front->data;  // Return the data at the front of the queue
}

// Function to get the current size of the queue
int getSize() {
    return size;
}

// Function to display the elements of the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are:\n");
    struct node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate the queue operations
int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Get Queue Size\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != INT_MIN)
                    printf("%d is dequeued from the queue\n", value);
                break;
            case 3:
                value = peek();
                if (value != INT_MIN)
                    printf("Front element is: %d\n", value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Current size of the queue: %d\n", getSize());
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

