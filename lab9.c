#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term of the polynomial
struct Term {
    int coeff;
    int x_pow;
    int y_pow;
    int z_pow;
    struct Term *next;
};

// Function to create a new term
struct Term* createTerm(int coeff, int x_pow, int y_pow, int z_pow) {
    struct Term *newTerm = (struct Term*)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newTerm->coeff = coeff;
    newTerm->x_pow = x_pow;
    newTerm->y_pow = y_pow;
    newTerm->z_pow = z_pow;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term at the end of the singly circular linked list
void insertTerm(struct Term **head, int coeff, int x_pow, int y_pow, int z_pow) {
    struct Term *newTerm = createTerm(coeff, x_pow, y_pow, z_pow);
    if (*head == NULL) {
        *head = newTerm;
        newTerm->next = newTerm; // Point to itself
    } else {
        struct Term *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newTerm;
        newTerm->next = *head;
    }
}

// Function to evaluate the polynomial for given values of x, y, and z
int evaluatePolynomial(struct Term *head, int x, int y, int z) {
    int result = 0;
    struct Term *temp = head;
    do {
        result += temp->coeff * (temp->x_pow * x + temp->y_pow * y + temp->z_pow * z);
        temp = temp->next;
    } while (temp != head);
    return result;
}

// Function to display the polynomial
void displayPolynomial(struct Term *head) {
    struct Term *temp = head;
    do {
        printf("(%dx^%dy^%dz^%d)", temp->coeff, temp->x_pow, temp->y_pow, temp->z_pow);
        temp = temp->next;
        if (temp != head) {
            printf(" + ");
        }
    } while (temp != head);
    printf("\n");
}

int main() {
    // Representing the polynomial P(x,y,z) = 6x^2y^2z - 4yz^5 + 3x^3yz + 2xy^5z - 2xyz^3
    struct Term *poly = NULL;
    insertTerm(&poly, 6, 2, 2, 1);
    insertTerm(&poly, -4, 0, 1, 5);
    insertTerm(&poly, 3, 3, 1, 1);
    insertTerm(&poly, 2, 1, 5, 1);
    insertTerm(&poly, -2, 1, 1, 3);

    printf("Polynomial P(x,y,z) = ");
    displayPolynomial(poly);

    // Evaluating the polynomial for x=2, y=3, z=4
    int result = evaluatePolynomial(poly, 2, 3, 4);
    printf("Result of polynomial evaluation: %d\n", result);

    return 0;
}
