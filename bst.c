#include <stdio.h>
#include <stdlib.h>

// Define a structure for each node in the binary search tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to insert a node in the binary search tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to find the minimum value in the binary search tree
int findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Function to find the maximum value in the binary search tree
int findMax(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

// Recursive function to search for a node with the given data
Node* searchNode(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// Helper function to find the minimum node in a subtree, used for deletion
Node* findMinNode(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary search tree
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with no children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Node with only one child
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            free(temp);
        }
        // Node with two children
        else {
            Node* temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Main function for testing the binary search tree functions
int main() {
    Node* root = NULL;
    int n, data, choice;

    // Input number of nodes and their values to insert in the binary search tree
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter node %d value: ", i + 1);
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    // Menu-driven options for finding min/max, searching, deleting, and exiting
    while (1) {
        printf("\n1. Find Minimum\n");
        printf("2. Find Maximum\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Minimum value: %d\n", findMin(root));
                break;
            case 2:
                printf("Maximum value: %d\n", findMax(root));
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &data);
                if (searchNode(root, data) != NULL) {
                    printf("Value found\n");
                } else {
                    printf("Value not found\n");
                }
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
