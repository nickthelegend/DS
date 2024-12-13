#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // Head pointer for the linked list

// Function to display the list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert at the end
void insert_at_end(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", value);
}

// Function to insert at a specific position
void insert_at_position(int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        printf("Inserted %d at position %d.\n", value, position);
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", value, position);
}

// Function to delete a node at a specific position
void delete_at_position(int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    if (position == 1) {
        head = temp->next;
        free(temp);
        printf("Node at position %d deleted.\n", position);
        return;
    }

    struct Node* prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node at position %d deleted.\n", position);
}

// Function to update a node's value at a specific position
void update_at_position(int value, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    temp->data = value;
    printf("Updated node at position %d to %d.\n", position, value);
}

// Menu-driven main function
int main() {
    int choice, value, position;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Display List\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Position\n");
        printf("5. Update at Position\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insert_at_end(value);
                break;
            case 3:
                printf("Enter value and position to insert: ");
                scanf("%d %d", &value, &position);
                insert_at_position(value, position);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete_at_position(position);
                break;
            case 5:
                printf("Enter new value and position to update: ");
                scanf("%d %d", &value, &position);
                update_at_position(value, position);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
