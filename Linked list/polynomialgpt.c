#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node of the singly linked list
struct Node {
    int coeff;  // Coefficient of the term
    int exp;    // Exponent of the term
    struct Node* next;  // Pointer to the next node
};

// Function to create a new node for the polynomial
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to append a new node to the polynomial linked list
void appendNode(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the polynomial
void displayPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        // Display coefficient and exponent
        if (temp->exp != 0) {
            printf("%dx^%d", temp->coeff, temp->exp);
        } else {
            printf("%d", temp->coeff);
        }
        
        // Print plus or minus between terms
        if (temp->next != NULL && temp->next->coeff > 0) {
            printf(" + ");
        } else if (temp->next != NULL && temp->next->coeff < 0) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* poly = NULL;
    
    // Creating the polynomial 5x^4 + 3x^2 + 1
    appendNode(&poly, 5, 4);  // 5x^4
    appendNode(&poly, 3, 2);  // 3x^2
    appendNode(&poly, 1, 0);  // 1

    printf("The polynomial is: ");
    displayPolynomial(poly);
    
    return 0;
}
