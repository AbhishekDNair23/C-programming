#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int expo;
    struct Node* next;
} Node;

Node* createNode(int coeff, int expo) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* head, int coeff, int expo) {
    Node* newNode = createNode(coeff, expo);

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    return head;
}

void display(Node* head) {
    Node* temp = head;

    if (temp == NULL) {
        printf("0\n");
        return;
    }

    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->expo);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

Node* addPolynomials(Node* p1, Node* p2) {
    Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->expo > p2->expo) {
            result = insertNode(result, p1->coeff, p1->expo);
            p1 = p1->next;
        } 
        else if (p2->expo > p1->expo) {
            result = insertNode(result, p2->coeff, p2->expo);
            p2 = p2->next;
        } 
        else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                result = insertNode(result, sum, p1->expo);

            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insertNode(result, p1->coeff, p1->expo);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insertNode(result, p2->coeff, p2->expo);
        p2 = p2->next;
    }

    return result;
}

int main() {
    Node* p1 = NULL;
    Node* p2 = NULL;
    Node* sum = NULL;

    int n, m, coeff, expo, i;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d%d", &coeff, &expo);
        p1 = insertNode(p1, coeff, expo);
    }

    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d%d", &coeff, &expo);
        p2 = insertNode(p2, coeff, expo);
    }

    printf("\nFirst Polynomial: ");
    display(p1);

    printf("Second Polynomial: ");
    display(p2);

    sum = addPolynomials(p1, p2);

    printf("\nSum of Polynomials: ");
    display(sum);

    return 0;
}
