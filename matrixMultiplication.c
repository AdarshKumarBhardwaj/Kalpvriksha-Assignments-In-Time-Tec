#include <stdio.h>
#include <stdlib.h>

// Function to multiply matrices
void multiplyMatrices(int **A, int **B, int **C, int rowA, int colA, int rowB, int colB)
{

    if (colA != rowB)
    {
        printf("Matrix multiplication not possible. Column of A must be equal to row of B.\n");
        return;
    }

    for (int rowIndexA = 0; rowIndexA < rowA; rowIndexA++)
    {
        for (int colIndexB = 0; colIndexB < colB; colIndexB++)
        {
            *(*(C + rowIndexA) + colIndexB) = 0;
            for (int commonIndex = 0; commonIndex < colA; commonIndex++)
            {
                *(*(C + rowIndexA) + colIndexB) += *(*(A + rowIndexA) + commonIndex) * *(*(B + commonIndex) + colIndexB);
            }
        }
    }
}

// Function to create a matrix dynamically
int **createMatrix(int rows, int cols)
{
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        matrix[rowIndex] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to input matrix elements
void inputMatrix(int **matrix, int rows, int cols)
{
    printf("Enter the elements of the matrix:\n");
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols; colIndex++)
        {
            printf("Enter element (%d,%d): ", rowIndex + 1, colIndex + 1);
            scanf("%d", &*(*(matrix + rowIndex) + colIndex));
        }
    }
}

// Function to display matrix
void displayMatrix(int **matrix, int rows, int cols)
{
    printf("Matrix:\n");
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < cols; colIndex++)
        {
            printf("%d ", *(*(matrix + rowIndex) + colIndex));
        }
        printf("\n");
    }
}

// Function to free dynamically allocated matrix memory
void freeMatrix(int **matrix, int rows)
{
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        free(matrix[rowIndex]);
    }
    free(matrix);
}

int main()
{
    int rowA, colA, rowB, colB;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &rowA, &colA);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &rowB, &colB);

    // Dynamically allocate memory for matrices A, B, and C
    int **A = createMatrix(rowA, colA);
    int **B = createMatrix(rowB, colB);
    int **C = createMatrix(rowA, colB);

    inputMatrix(A, rowA, colA);
    inputMatrix(B, rowB, colB);

    printf("\nMatrix A:\n");
    displayMatrix(A, rowA, colA);

    printf("\nMatrix B:\n");
    displayMatrix(B, rowB, colB);

    // Perform matrix multiplication
    multiplyMatrices(A, B, C, rowA, colA, rowB, colB);

    printf("\nResultant Matrix after multiplication:\n");
    displayMatrix(C, rowA, colB);

    freeMatrix(A, rowA);
    freeMatrix(B, rowB);
    freeMatrix(C, rowA);

    return 0;
}
