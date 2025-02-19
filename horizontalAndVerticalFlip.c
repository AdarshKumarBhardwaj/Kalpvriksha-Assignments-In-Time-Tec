#include <stdio.h>

void horizontalFlip(int matrix[10][10], int row, int col);
void verticalFlip(int matrix[10][10], int row, int col);

int main() {
    int matrix[10][10];
    int row, col, choice;

    printf("Enter the number of rows (<= 10): ");
    scanf("%d", &row);
    if (row > 10) {
        printf("Error: Number of rows cannot exceed 10.\n");
    }

    printf("Enter the number of columns (<= 10): ");
    scanf("%d", &col);
    if (col > 10) {
        printf("Error: Number of columns cannot exceed 10.\n");
    }

    if (row > 10 || col > 10) {
        return 1;
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element at (%d,%d): ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    do {
        printf("\nMenu:\n");
        printf("1. Horizontal Flip\n");
        printf("2. Vertical Flip\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                horizontalFlip(matrix, row, col);
                break;
            case 2:
                verticalFlip(matrix, row, col);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Wrong Choice\n");
        }
    } while (choice != 3);

    return 0;
}

void horizontalFlip(int matrix[10][10], int row, int column) {
    for (int index = 0; index < row; index++) {
        int start = 0;
        int end = column - 1;
        while (start <= end) {
            int temp = matrix[index][start];
            matrix[index][start] = matrix[index][end];
            matrix[index][end] = temp;
            start++;
            end--;
        }
    }

    printf("Matrix after horizontal flip:\n");
    for (int rowIndex = 0; rowIndex < row; rowIndex++) { 
        for (int colIndex = 0; colIndex < column; colIndex++) { 
            printf("%d ", matrix[rowIndex][colIndex]);
        }
        printf("\n");
    }
}

void verticalFlip(int matrix[10][10], int row, int col) {
    for (int index = 0; index < row; index++) {
        int start = 0;
        int end = col - 1;
        while (start <= end) {
            int temp = matrix[index][start];
            matrix[index][start] = matrix[index][end];
            matrix[index][end] = temp;
            start++;
            end--;
        }
    }
    for (int index = 0; index < col; index++) {
        int start = 0;
        int end = row - 1;
        while (start <= end) {
            int temp = matrix[start][index];
            matrix[start][index] = matrix[end][index];
            matrix[end][index] = temp;
            start++;
            end--;
        }
    }

    printf("Matrix after vertical flip:\n");
    for (int rowIndex = 0; rowIndex < row; rowIndex++) { 
        for (int colIndex = 0; colIndex < col; colIndex++) { 
            printf("%d ", matrix[rowIndex][colIndex]);
        }
        printf("\n");
    }
}

