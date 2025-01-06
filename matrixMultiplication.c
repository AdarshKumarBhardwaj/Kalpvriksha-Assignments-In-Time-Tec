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

    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colB; j++)
        {
            *(*(C + i) + j) = 0;
            for (int k = 0; k < colA; k++)
            {
                *(*(C + i) + j) += *(*(A + i) + k) * *(*(B + k) + j);
            }
        }
    }
}

// Function to create a matrix dynamically
int **createMatrix(int rows, int cols)
{
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to input matrix elements
void inputMatrix(int **matrix, int rows, int cols)
{
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter element (%d,%d): ", i + 1, j + 1);
            scanf("%d", &*(*(matrix + i) + j));
        }
    }
}

// Function to display matrix
void displayMatrix(int **matrix, int rows, int cols)
{
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

// Function to free dynamically allocated matrix memory
void freeMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
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
