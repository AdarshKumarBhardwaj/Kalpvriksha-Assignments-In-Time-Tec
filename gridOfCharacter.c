#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int found = 0;
void searchWord(char **arr, char word[], int parameter[])
{
    int row = parameter[0];
    int column = parameter[1];
    int rowIndex = parameter[2];
    int colIndex = parameter[3];
    int index = parameter[4];
    int length = parameter[5];

    if (index == length)
    {
        found = 1;
        return;
    }
    for (int index1 = -1; index1 <= 1; index1++)
    {
        for (int index2 = -1; index2 <= 1; index2++)
        {
            if (index1 == 0 && index2 == 0)
            {
                continue;
            }
            int nrow = rowIndex + index1;
            int ncol = colIndex + index2;
            if (nrow >= 0 && ncol >= 0 && nrow < row && ncol < column && arr[nrow][ncol] == word[index])
            {
                int newParams[] = {row, column, nrow, ncol, index + 1, length};
                searchWord(arr, word, newParams);
            }
        }
    }
}

void isWordPresentInGrid(char **arr, char wordToFound[], int dimension[])
{
    int row = dimension[0];
    int column = dimension[1];
    int length = dimension[2];
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < column; colIndex++)
        {
            if (arr[rowIndex][colIndex] == wordToFound[0])
            {
                int parameter[] = {row, column, rowIndex, colIndex, 1, length};
                searchWord(arr, wordToFound, parameter);
                if (found)
                    return;
            }
        }
    }
}

int main()
{
    int row, column;
    char wordToFind[20];
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &column);
    printf("Enter the word to find: ");
    scanf("%s", wordToFind);
    int length = strlen(wordToFind);
    char **matrix = (char **)malloc(row * sizeof(char *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (char *)malloc(column * sizeof(char));
    }
    getchar();
    printf("Enter the matrix elements:\n");
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < column; colIndex++)
        {
            printf("Element at (%d,%d): ", rowIndex, colIndex);
            matrix[rowIndex][colIndex] = getchar();
            getchar();
        }
    }
    printf("Matrix Elements are:\n");
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < column; colIndex++)
        {
            printf("%c ", matrix[rowIndex][colIndex]);
        }
        printf("\n");
    }
    int arguments[] = {row, column, length};
    isWordPresentInGrid(matrix, wordToFind, arguments);
    if (found)
    {
        printf("%s is present in the grid of characters\n", wordToFind);
    }
    else
    {
        printf("%s is absent in the grid of characters\n", wordToFind);
    }
    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
