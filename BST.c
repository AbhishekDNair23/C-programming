#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

/* Create a new node */
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* INSERT operation */
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

/* SEARCH operation */
Node* search(Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

/* Find minimum in a subtree (used in delete) */
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

/* DELETE operation */
Node* delete(Node* root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = delete(root->left, value);

    else if (value > root->data)
        root->right = delete(root->right, value);

    else {
        // Case 1: No children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: One child (right)
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        // Case 2: One child (left)
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);   // Minimum in RIGHT subtree
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("Found\n");
                else
                    printf("Not Found\n");
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = delete(root, value);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
