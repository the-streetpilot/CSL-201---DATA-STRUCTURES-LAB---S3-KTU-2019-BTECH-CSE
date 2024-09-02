#include <stdio.h>

// Define the maximum degree of the polynomial
#define MAX_DEGREE 100

// Function to add two polynomials
void addPolynomials(int poly1[], int poly2[], int result[], int degree) {
    for (int count = 0; count <= degree; count++) {
        result[count] = poly1[count] + poly2[count];
    }
}

// Function to display the polynomial
void displayPolynomial(int poly[], int degree) {
    for (int count = degree; count >= 0; count--) {
        if (poly[count] != 0) {
            printf("%dx^%d", poly[count], count);
            if (count != 0) printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    int degree;  // Maximum degree of the polynomials
    int poly1[MAX_DEGREE + 1] = {0}; // First polynomial
    int poly2[MAX_DEGREE + 1] = {0}; // Second polynomial
    int result[MAX_DEGREE + 1] = {0}; // Resultant polynomial

    // Initialize the degree of the polynomial
    printf("Enter the maximum degree of the polynomials: ");
    scanf("%d", &degree);

    // Input coefficients for the first polynomial
    printf("Enter the coefficients for the first polynomial:\n");
    for (int count = degree; count >= 0; count--) {
        printf("Coefficient of x^%d: ", count);
        scanf("%d", &poly1[count]);
    }

    // Input coefficients for the second polynomial
    printf("Enter the coefficients for the second polynomial:\n");
    for (int count = degree; count >= 0; count--) {
        printf("Coefficient of x^%d: ", count);
        scanf("%d", &poly2[count]);
    }

    // Add the two polynomials
    addPolynomials(poly1, poly2, result, degree);

    // Display the result
    printf("Resultant polynomial after addition: ");
    displayPolynomial(result, degree);

    return 0;
}
