#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial
struct PolyNode {
    int coeff;      // Coefficient
    int exp;        // Exponent
    struct PolyNode* next;
};

// Function to create a new node
struct PolyNode* createNode(int coeff, int exp) {
    struct PolyNode* newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the polynomial (in descending order of exponents)
void insertNode(struct PolyNode** head, int coeff, int exp) {
    struct PolyNode* newNode = createNode(coeff, exp);
    if (*head == NULL || (*head)->exp < exp) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct PolyNode* temp = *head;
        while (temp->next != NULL && temp->next->exp >= exp) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to print a polynomial
void printPolynomial(struct PolyNode* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }

    struct PolyNode* temp = poly;
    while (temp != NULL) {
        if (temp->coeff != 0) {
            if (temp != poly && temp->coeff > 0) {
                printf(" + ");
            }
            if (temp->exp == 0) {
                printf("%d", temp->coeff);
            } else if (temp->exp == 1) {
                printf("%dx", temp->coeff);
            } else {
                printf("%dx^%d", temp->coeff, temp->exp);
            }
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct PolyNode* addPolynomials(struct PolyNode* poly1, struct PolyNode* poly2) {
    struct PolyNode* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            insertNode(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            insertNode(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else {
            insertNode(&result, poly2->coeff, poly2->exp);
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

// Function to multiply two polynomials
struct PolyNode* multiplyPolynomials(struct PolyNode* poly1, struct PolyNode* poly2) {
    struct PolyNode* result = NULL;

    for (struct PolyNode* p1 = poly1; p1 != NULL; p1 = p1->next) {
        struct PolyNode* tempResult = NULL;
        for (struct PolyNode* p2 = poly2; p2 != NULL; p2 = p2->next) {
            int coeff = p1->coeff * p2->coeff;
            int exp = p1->exp + p2->exp;
            insertNode(&tempResult, coeff, exp);
        }
        result = addPolynomials(result, tempResult);
        while (tempResult != NULL) {
            struct PolyNode* temp = tempResult;
            tempResult = tempResult->next;
            free(temp);
        }
    }

    return result;
}

// Function to delete a polynomial
void deletePolynomial(struct PolyNode* poly) {
    while (poly != NULL) {
        struct PolyNode* temp = poly;
        poly = poly->next;
        free(temp);
    }
}

// Menu-driven main function for polynomial operations
int main() {
    struct PolyNode* poly1 = NULL;
    struct PolyNode* poly2 = NULL;
    struct PolyNode* result = NULL;
    int choice, coeff, exp;

    while (1) {
        printf("\nPolynomial Menu:\n");
        printf("1. Insert Polynomial Term\n");
        printf("2. Print Polynomial\n");
        printf("3. Add Polynomials\n");
        printf("4. Multiply Polynomials\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter polynomial (coeff exp): ");
                scanf("%d %d", &coeff, &exp);
                printf("Enter polynomial number (1 or 2): ");
                int polyNumber;
                scanf("%d", &polyNumber);
                if (polyNumber == 1) {
                    insertNode(&poly1, coeff, exp);
                } else if (polyNumber == 2) {
                    insertNode(&poly2, coeff, exp);
                } else {
                    printf("Invalid polynomial number\n");
                }
                break;
            case 2:
                printf("Polynomial 1: ");
                printPolynomial(poly1);
                printf("Polynomial 2: ");
                printPolynomial(poly2);
                break;
            case 3:
                result = addPolynomials(poly1, poly2);
                printf("Result of Addition: ");
                printPolynomial(result);
                deletePolynomial(result);
                break;
            case 4:
                result = multiplyPolynomials(poly1, poly2);
                printf("Result of Multiplication: ");
                printPolynomial(result);
                deletePolynomial(result);
                break;
            case 5:
                deletePolynomial(poly1);
                deletePolynomial(poly2);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}
