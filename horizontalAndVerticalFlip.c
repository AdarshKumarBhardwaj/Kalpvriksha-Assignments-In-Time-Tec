#include <stdio.h>
#include <stdlib.h>

void horizontalFlip(int matrix[10][10],int row, int col);
void verticalFlip(int matrix[10][10], int row, int col);


int main() {
    int matrix[10][10];
    int res[10][10];
    int row, col, choice;

    do {
        printf("Enter the number of rows: ");
        scanf("%d", &row);
        printf("Enter the number of columns: ");
        scanf("%d", &col);

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
                   horizontalFlip(matrix,row, col);
                    break;
                case 2: {
                    verticalFlip(matrix, row, col);
                    break;
                }
                case 3:
                    exit(0);
                default:
                    printf("Wrong Choice\n");
            }
        } while (choice != 6);

        printf("\nDo you want to continue? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);

    } while (choice == 1);

    return 0;
}

void horizontalFlip(int matrix[10][10], int row, int column) {
    for (int index = 0; index < row; index++) {
       int start=0;
       int end=column-1;
       while(start<=end){
           int temp=matrix[index][start];
           matrix[index][start]=matrix[index][end];
           matrix[index][end]=temp;
           start++;
           end--;
       }
    }

    printf("Matrix after horizontal flip:\n");
    for (int rowIndex = 0; rowIndex < column; rowIndex++) { 
        for (int colIndex = 0; colIndex < row; colIndex++) { 
            printf("%d ", matrix[rowIndex][colIndex]);
        }
        printf("\n");
    }
}

void verticalFlip(int matrix[10][10], int row, int col){
     for (int index = 0; index < row; index++) {
       int start=0;
       int end=col-1;
       while(start<=end){
           int temp=matrix[index][start];
           matrix[index][start]=matrix[index][end];
           matrix[index][end]=temp;
           start++;
           end--;
       }
    }
    for(int index=0;index<col;index++){
        int start=0;
        int end=row-1;
        while(start<=end){
            int temp=matrix[start][index];
            matrix[start][index]=matrix[end][index];
            matrix[end][index]=temp;
            start++;
            end--;
            
        }
    }
     printf("Matrix after vertical flip:\n");
    for (int rowIndex = 0; rowIndex < col; rowIndex++) { 
        for (int colIndex = 0; colIndex < row; colIndex++) { 
            printf("%d ", matrix[rowIndex][colIndex]);
        }
        printf("\n");
    }
}

