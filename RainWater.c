#include <stdio.h>
#define MAX_ROW 30
#define MAX_COL 30

typedef struct {
    int matrix[MAX_ROW][MAX_COL];
    int rightMatrix[MAX_ROW][MAX_COL];
    int leftMatrix[MAX_ROW][MAX_COL];
    int bottomMatrix[MAX_ROW][MAX_COL];
    int upMatrix[MAX_ROW][MAX_COL];
    int dims[2]; 
} RainWaterData;

int findMinimum(int first,int second){
    if(first<second){
        return first;
    }
    return second;
}

void findRightMax(int matrix[][MAX_COL], int dims[], int rightMatrix[][MAX_COL]) {
    int row=dims[0];
    int col=dims[1];
    for (int rowIndex = 0; rowIndex < row; rowIndex++) {
        int maximum = -1;
        for (int colIndex = col - 1; colIndex >= 0; colIndex--) {
            if (matrix[rowIndex][colIndex] > maximum) {
                maximum = matrix[rowIndex][colIndex];
            }
            rightMatrix[rowIndex][colIndex] = maximum;
        }
    }
}

void findLeftMax(int matrix[][MAX_COL], int dims[], int leftMatrix[][MAX_COL]) {
    int row=dims[0];
    int col=dims[1];
    for (int rowIndex = 0; rowIndex < row; rowIndex++) {
        int maximum = -1;
        for (int colIndex =0; colIndex<col; colIndex++) {
            if (matrix[rowIndex][colIndex] > maximum) {
                maximum = matrix[rowIndex][colIndex];
            }
            leftMatrix[rowIndex][colIndex] = maximum;
        }
    }
}

void findBottomMax(int matrix[][MAX_COL], int dims[] ,int bottomMatrix[][MAX_COL]) {
    int row=dims[0];
    int col=dims[1];
    for (int colIndex = 0; colIndex<col; colIndex++) {
        int maximum = -1;
        for (int rowIndex =row-1; rowIndex>=0; rowIndex--) {
            if (matrix[rowIndex][colIndex] > maximum) {
                maximum = matrix[rowIndex][colIndex];
            }
            bottomMatrix[rowIndex][colIndex] = maximum;
        }
    }
}

void findUpMax(int matrix[][MAX_COL], int dims[] ,int upMatrix[][MAX_COL]) {
    int row=dims[0];
    int col=dims[1];
    for (int colIndex = 0; colIndex<col; colIndex++) {
        int maximum = -1;
        for (int rowIndex =0; rowIndex<row; rowIndex++) {
            if (matrix[rowIndex][colIndex] > maximum) {
                maximum = matrix[rowIndex][colIndex];
            }
            upMatrix[rowIndex][colIndex] = maximum;
        }
    }
}

void rainWaterTrappedAmount(RainWaterData *data){
    int row=data->dims[0];
    int col=data->dims[1];
    int amount=0;
    for(int rowIndex=0;rowIndex<row;rowIndex++){
        for(int colIndex=0;colIndex<col;colIndex++){
            int firstMinimum=findMinimum(data->rightMatrix[rowIndex][colIndex],data->leftMatrix[rowIndex][colIndex]);
            int secondMinimum=findMinimum(firstMinimum,data->upMatrix[rowIndex][colIndex]);
            int thirdMinimum=findMinimum(secondMinimum,data->bottomMatrix[rowIndex][colIndex]);
            amount+=thirdMinimum-data->matrix[rowIndex][colIndex];
        }
    }
    printf("Total amount of rainwater trapped is %d ",amount);
}

int main() {
    RainWaterData data;
    
    printf("Enter number of rows: ");
    scanf("%d", &data.dims[0]);
    printf("Enter number of columns: ");
    scanf("%d", &data.dims[1]);

     if (data.dims[0] > MAX_ROW || data.dims[1] > MAX_COL) {
        printf("Error: Rows or columns exceed maximum limits.\n");
        return 1;
    }
    
    printf("Enter matrix elements:\n");
    for (int rowIndex = 0; rowIndex < data.dims[0]; rowIndex++) {
        for (int  colIndex = 0;  colIndex < data.dims[1];  colIndex++) {
            printf("Enter elements at (%d,%d):- ",rowIndex,colIndex);
            scanf("%d", &data.matrix[rowIndex][ colIndex]);
        }
    }

    printf("\nMatrix:\n");
    for (int rowIndex = 0; rowIndex < data.dims[0]; rowIndex++) {
        for (int  colIndex = 0;  colIndex < data.dims[1];colIndex++) {
            printf("%d ", data.matrix[rowIndex][ colIndex]);
        }
        printf("\n");
    }
    
   findRightMax(data.matrix, data.dims, data.rightMatrix);
   findLeftMax(data.matrix, data.dims, data.leftMatrix);
   findBottomMax(data.matrix, data.dims, data.bottomMatrix);
   findUpMax(data.matrix, data.dims, data.upMatrix);
   
   rainWaterTrappedAmount(&data);
    return 0;
}

