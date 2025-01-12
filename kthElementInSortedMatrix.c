#include <stdio.h>
#include <stdlib.h>
int countLessEqual(int **matrix, int row, int column, int mid)
{
    int count = 0;
    int rows = row - 1;
    int cols = 0;

    while (rows >= 0 && cols < column)
    {
        if (matrix[rows][cols] <= mid)
        {
            count += rows + 1;
            cols++;
        }
        else
        {
            rows--;
        }
    }
    return count;
}
int kthSmallestElements(int **matrix, int row, int column, int k)
{
    int low = matrix[0][0];
    int high = matrix[row - 1][column - 1];

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (countLessEqual(matrix, row, column, mid) < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}
int main()
{
    int row, column, k;
    printf("Enter the no of row\n");
    scanf("%d", &row);
    printf("Enter the no of column\n");
    scanf("%d", &column);

    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int index = 0; index < row; index++)
    {
        matrix[index] = (int *)malloc(column * sizeof(int));
    }

    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < column; colIndex++)
        {
            printf("Enter the element at (%d,%d):- ", rowIndex, colIndex);
            scanf("%d", &matrix[rowIndex][colIndex]);
        }
    }
    printf("Matrix Elements are\n");
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < column; colIndex++)
        {
            printf("%d ", matrix[rowIndex][colIndex]);
        }
        printf("\n");
    }

    printf("Enter the value of k\n");
    scanf("%d", &k);
    int result = kthSmallestElements(matrix, row, column, k);
    printf("%d smallest element of matrix is %d ", k, result);

    for (int index = 0; index < row; index++)
    {
        free(matrix[index]);
    }
    free(matrix);
    return 0;
}