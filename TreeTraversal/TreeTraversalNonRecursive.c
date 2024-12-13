#include <stdio.h>
#include <stdlib.h>

// Definition of the binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Stack structure for traversal
struct Stack {
    struct Node* data;
    struct Stack* next;
};

// Push a node onto the stack
void push(struct Stack** top, struct Node* node) {
    struct Stack* newStack = (struct Stack*)malloc(sizeof(struct Stack));
    newStack->data = node;
    newStack->next = *top;
    *top = newStack;
}

// Pop a node from the stack
struct Node* pop(struct Stack** top) {
    if (*top == NULL) {
        return NULL;
    }
    struct Stack* temp = *top;
    struct Node* node = temp->data;
    *top = (*top)->next;
    free(temp);
    return node;
}

// Check if the stack is empty
int isEmpty(struct Stack* top) {
    return top == NULL;
}

// Create a new tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Non-recursive Inorder Traversal
void inorderTraversal(struct Node* root) {
    struct Stack* stack = NULL;
    struct Node* current = root;

    printf("Inorder Traversal: ");
    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");
}

// Non-recursive Preorder Traversal
void preorderTraversal(struct Node* root) {
    struct Stack* stack = NULL;

    printf("Preorder Traversal: ");
    if (root != NULL) {
        push(&stack, root);
    }

    while (!isEmpty(stack)) {
        struct Node* node = pop(&stack);
        printf("%d ", node->data);

        if (node->right != NULL) {
            push(&stack, node->right);
        }
        if (node->left != NULL) {
            push(&stack, node->left);
        }
    }
    printf("\n");
}

// Non-recursive Postorder Traversal
void postorderTraversal(struct Node* root) {
    struct Stack *stack1 = NULL, *stack2 = NULL;

    if (root != NULL) {
        push(&stack1, root);
    }

    while (!isEmpty(stack1)) {
        struct Node* node = pop(&stack1);
        push(&stack2, node);

        if (node->left != NULL) {
            push(&stack1, node->left);
        }
        if (node->right != NULL) {
            push(&stack1, node->right);
        }
    }

    printf("Postorder Traversal: ");
    while (!isEmpty(stack2)) {
        struct Node* node = pop(&stack2);
        printf("%d ", node->data);
    }
    printf("\n");
}

int main() {
    // Build a sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Perform traversals
    inorderTraversal(root);
    preorderTraversal(root);
    postorderTraversal(root);

    return 0;
}
