#include <stdio.h>
#include <stdlib.h>

// Define the node structure for polynomial terms
struct node {
    int coeff;
    int exp;
    struct node *next;
};

// Function to create a new node
struct node* createNode(int coeff, int exp) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term in the polynomial linked list
void insertNode(struct node** poly, int coeff, int exp) {
    struct node* newNode = createNode(coeff, exp);
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        struct node* temp = *poly;
        while (temp->next != NULL && temp->next->exp >= exp) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to display the polynomial
void displayPoly(struct node* poly) {
    struct node* temp = poly;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomials
struct node* addPolynomials(struct node* poly1, struct node* poly2) {
    struct node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertNode(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertNode(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                insertNode(&result, sumCoeff, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertNode(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertNode(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

int main() {
    int numTerms1, numTerms2;
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;

    // Input for the first polynomial
    printf("Enter the number of terms for the first polynomial: ");
    scanf("%d", &numTerms1);
    printf("Enter the terms (coeff exp):\n");
    for (int i = 0; i < numTerms1; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        insertNode(&poly1, coeff, exp);
    }

    // Input for the second polynomial
    printf("Enter the number of terms for the second polynomial: ");
    scanf("%d", &numTerms2);
    printf("Enter the terms (coeff exp):\n");
    for (int i = 0; i < numTerms2; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        insertNode(&poly2, coeff, exp);
    }

    // Display the first polynomial
    printf("First Polynomial: ");
    displayPoly(poly1);

    // Display the second polynomial
    printf("Second Polynomial: ");
    displayPoly(poly2);

    // Add the two polynomials
    struct node* result = addPolynomials(poly1, poly2);

    // Display the resultant polynomial
    printf("Sum of Polynomials: ");
    displayPoly(result);

    return 0;
}
