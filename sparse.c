#include <stdio.h>

// Function to create a sparse matrix representation
void createSparseMatrix(int matrix[][3], int rows, int cols, int sparseMatrix[][3]) {
    int count = 1;
    for (int rowCount = 0; rowCount < rows; rowCount++) {
        for (int colCount = 0; colCount < cols; colCount++) {
            if (matrix[rowCount][colCount] != 0) {
                sparseMatrix[count][0] = rowCount;
                sparseMatrix[count][1] = colCount;
                sparseMatrix[count][2] = matrix[rowCount][colCount];
                count++;
            }
        }
    }
    sparseMatrix[0][2] = count - 1; // Number of non-zero elements
}

// Function to display the sparse matrix
void displaySparseMatrix(int sparseMatrix[][3]) {
    printf("Row\tColumn\tValue\n");
    for (int count = 0; count <= sparseMatrix[0][2]; count++) {
        printf("%d\t%d\t%d\n", sparseMatrix[count][0], sparseMatrix[count][1], sparseMatrix[count][2]);
    }
}

int main() {
    int rows, cols;
    int matrix[100][100];
    int sparseMatrix[100][3] = {0};

    // Input dimensions of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Input the matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int rowCount = 0; rowCount < rows; rowCount++) {
        for (int colCount = 0; colCount < cols; colCount++) {
            scanf("%d", &matrix[rowCount][colCount]);
        }
    }

    // Store the dimensions and the count of non-zero elements
    sparseMatrix[0][0] = rows;
    sparseMatrix[0][1] = cols;

    // Create sparse matrix representation
    createSparseMatrix(matrix, rows, cols, sparseMatrix);

    // Display the sparse matrix
    printf("Sparse matrix representation:\n");
    displaySparseMatrix(sparseMatrix);

    return 0;
}
