#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;  // New nodes start with height 1
    return newNode;
}

// Get height of a node
int height(Node* node) {
    if (node == NULL)
        return 0;
    else
        return node->height;
}

// Calculate balance factor
int balanceFactor(Node* node) {
    if (node == NULL)
        return 0;
    else
        return height(node->left) - height(node->right);
}

// Right rotation
Node* rotateRight(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;

    // Update heights
    if (height(y->left) > height(y->right))
        y->height = height(y->left) + 1;
    else
        y->height = height(y->right) + 1;

    if (height(x->left) > height(x->right))
        x->height = height(x->left) + 1;
    else
        x->height = height(x->right) + 1;

    return x;
}

// Left rotation
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;

    // Update heights
    if (height(x->left) > height(x->right))
        x->height = height(x->left) + 1;
    else
        x->height = height(x->right) + 1;

    if (height(y->left) > height(y->right))
        y->height = height(y->left) + 1;
    else
        y->height = height(y->right) + 1;

    return y;
}

// Insert function with balancing
Node* insert(Node* node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    // Update the height of the node
    if (height(node->left) > height(node->right))
        node->height = height(node->left) + 1;
    else
        node->height = height(node->right) + 1;

    int bf = balanceFactor(node);

    // Left Left Case
    if (bf > 1 && data < node->left->data)
        return rotateRight(node);

     // Left Right Case
    if (bf > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Right Case
    if (bf < -1 && data > node->right->data)
        return rotateLeft(node);

   

    // Right Left Case
    if (bf < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Preorder traversal to print tree nodes
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int option, data;

    do {
        printf("\n1. Insert\n2. Display (Preorder)\n3. Exit\nChoose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (option != 3);

    return 0;
}
