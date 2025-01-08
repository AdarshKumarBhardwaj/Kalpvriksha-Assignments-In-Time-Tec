#include <stdio.h>
#include <stdlib.h>

void rotateMatrix(int **matrix, int size)
{

    for (int rowIndex = 0; rowIndex < size; rowIndex++)
    {
        for (int colIndex = rowIndex + 1; colIndex < size; colIndex++)
        {
            int temp = matrix[rowIndex][colIndex];
            matrix[rowIndex][colIndex] = matrix[colIndex][rowIndex];
            matrix[colIndex][rowIndex] = temp;
        }
    }

    for (int rowIndex = 0; rowIndex < size; rowIndex++)
    {
        int start = 0, end = size - 1;
        while (start < end)
        {
            int temp = matrix[rowIndex][start];
            matrix[rowIndex][start] = matrix[rowIndex][end];
            matrix[rowIndex][end] = temp;
            start++;
            end--;
        }
    }
}

int **createMatrix(int size)
{
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int rowIndex = 0; rowIndex < size; rowIndex++)
    {
        matrix[rowIndex] = (int *)malloc(size * sizeof(int));
    }
    return matrix;
}

void inputMatrix(int **matrix, int size)
{
    printf("Enter the elements of the matrix:\n");
    for (int rowIndex = 0; rowIndex < size; rowIndex++)
    {
        for (int colIndex = 0; colIndex < size; colIndex++)
        {
            printf("Enter element (%d,%d): ", rowIndex + 1, colIndex + 1);
            scanf("%d", &matrix[rowIndex][colIndex]);
        }
    }
}

void displayMatrix(int **matrix, int size)
{
    printf("Matrix:\n");
    for (int rowIndex = 0; rowIndex < size; rowIndex++)
    {
        for (int colIndex = 0; colIndex < size; colIndex++)
        {
            printf("%d ", matrix[rowIndex][colIndex]);
        }
        printf("\n");
    }
}

void freeMatrix(int **matrix, int size)
{
    for (int rowIndex = 0; rowIndex < size; rowIndex++)
    {
        free(matrix[rowIndex]);
    }
    free(matrix);
}

int main()
{
    int size;
    printf("Enter the size of matrix: ");
    scanf("%d", &size);

    int **matrix = createMatrix(size);

    inputMatrix(matrix, size);

    printf("\nOriginal Matrix:\n");
    displayMatrix(matrix, size);

    rotateMatrix(matrix, size);

    printf("\nResultant Matrix after 90-degree rotation:\n");
    displayMatrix(matrix, size);

    freeMatrix(matrix, size);

    return 0;
}
