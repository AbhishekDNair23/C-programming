#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[100];
    struct Node *prev;
    struct Node *next;
} Node;

Node *current = NULL;   // Initially no page visited

// Function to visit a new page
void visitNewPage() {
    char newURL[100];

    printf("Enter URL to visit: ");
    scanf("%s", newURL);

    Node *newnode = (Node*)malloc(sizeof(Node));

    strcpy(newnode->url, newURL);
    newnode->next = NULL;
    newnode->prev = current;

    if (current != NULL)
        current->next = newnode;

    current = newnode;

    printf("Visited: %s\n", current->url);
}

// Function to go back
void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("Cannot go back\n");
    } else {
        current = current->prev;
        printf("Moved back to: %s\n", current->url);
    }
}

// Function to go forward
void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("Cannot go forward\n");
    } else {
        current = current->next;
        printf("Moved forward to: %s\n", current->url);
    }
}

// Display current page
void displayCurrentPage() {
    if (current == NULL) {
        printf("No page visited yet\n");
    } else {
        printf("Current page: %s\n", current->url);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Browser Navigation Menu ---\n");
        printf("1. Visit new page\n");
        printf("2. Go back\n");
        printf("3. Go forward\n");
        printf("4. Display current page\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: visitNewPage(); break;
            case 2: goBack(); break;
            case 3: goForward(); break;
            case 4: displayCurrentPage(); break;
            case 5:
                printf("Exiting the navigation\n");
                printf("Program stopped\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
