#include <stdio.h>
#include <stdlib.h>

// Function to multiply matrices
void multiplyMatrices(int **matrix1, int **matrix2, int **resultMatrix, int rowMatrix1, int colMatrix1, int rowMatrix2, int colMatrix2)
{
    if (colMatrix1 != rowMatrix2)
    {
        printf("Matrix multiplication not possible. Column of matrix1 must be equal to row of matrix2.\n");
        return;
    }

    for (int rowIndexMatrix1 = 0; rowIndexMatrix1 < rowMatrix1; rowIndexMatrix1++)
    {
        for (int colIndexMatrix2 = 0; colIndexMatrix2 < colMatrix2; colIndexMatrix2++)
        {
            *(*(resultMatrix + rowIndexMatrix1) + colIndexMatrix2) = 0;
            for (int commonIndex = 0; commonIndex < colMatrix1; commonIndex++)
            {
                *(*(resultMatrix + rowIndexMatrix1) + colIndexMatrix2) += *(*(matrix1 + rowIndexMatrix1) + commonIndex) * *(*(matrix2 + commonIndex) + colIndexMatrix2);
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
    int rowMatrix1, colMatrix1, rowMatrix2, colMatrix2;

    printf("Enter rows and columns for matrix1: ");
    scanf("%d %d", &rowMatrix1, &colMatrix1);

    printf("Enter rows and columns for matrix2: ");
    scanf("%d %d", &rowMatrix2, &colMatrix2);

    // Dynamically allocate memory for matrices matrix1, matrix2, and resultMatrix
    int **matrix1 = createMatrix(rowMatrix1, colMatrix1);
    int **matrix2 = createMatrix(rowMatrix2, colMatrix2);
    int **resultMatrix = createMatrix(rowMatrix1, colMatrix2);

    inputMatrix(matrix1, rowMatrix1, colMatrix1);
    inputMatrix(matrix2, rowMatrix2, colMatrix2);

    printf("\nMatrix1:\n");
    displayMatrix(matrix1, rowMatrix1, colMatrix1);

    printf("\nMatrix2:\n");
    displayMatrix(matrix2, rowMatrix2, colMatrix2);

    // Perform matrix multiplication
    multiplyMatrices(matrix1, matrix2, resultMatrix, rowMatrix1, colMatrix1, rowMatrix2, colMatrix2);

    printf("\nResultant Matrix after multiplication:\n");
    displayMatrix(resultMatrix, rowMatrix1, colMatrix2);

    freeMatrix(matrix1, rowMatrix1);
    freeMatrix(matrix2, rowMatrix2);
    freeMatrix(resultMatrix, rowMatrix1);

    return 0;
}
