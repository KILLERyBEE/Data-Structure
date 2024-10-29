#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int coeff; // Coefficient
    int pow;   // Power of x
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the polynomial
void displayPoly(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        // If powers of both polynomials are the same
        if (poly1->pow == poly2->pow) {
            insertNode(&result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        // If power of poly1 is greater than poly2
        else if (poly1->pow > poly2->pow) {
            insertNode(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        // If power of poly2 is greater than poly1
        else {
            insertNode(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
    }

    // If there are remaining terms in poly1 or poly2
    while (poly1 != NULL) {
        insertNode(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertNode(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;

    // First polynomial: 3x^3 + 2x^2 + 1x^0
    insertNode(&poly1, 3, 4);
    insertNode(&poly1, 2, 3);
    insertNode(&poly1,-4,2);
    insertNode(&poly1, 7, 0);

    // Second polynomial: 4x^3 + 2x^1 + 3x^0
    insertNode(&poly2, 5, 3);
    insertNode(&poly2, 4, 2);
    insertNode(&poly2, -5, 0);

    // Display the first polynomial
    printf("Polynomial 1: ");
    displayPoly(poly1);

    // Display the second polynomial
    printf("Polynomial 2: ");
    displayPoly(poly2);

    // Add the polynomials
    sum = addPolynomials(poly1, poly2);

    // Display the sum of the polynomials
    printf("Sum of Polynomials: ");
    displayPoly(sum);

    return 0;
}
