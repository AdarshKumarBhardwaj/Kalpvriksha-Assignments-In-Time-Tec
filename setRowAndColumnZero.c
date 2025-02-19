#include <stdio.h>

void assignZero(int matrix[][150],int rowIndexMatrix[],int columnIndexMatrix[],int arguments[]){
    int size=arguments[0];
    int row=arguments[1];
    int column=arguments[2];
    for(int index=0;index<size;index++){
       for(int index1=0;index1<column;index1++){
             matrix[rowIndexMatrix[index]][index1]=0;
       }
       for(int index2=0;index2<row;index2++){
        matrix[index2][columnIndexMatrix[index]]=0;
       }
    }
}

void makingRowAndColumnZero(int matrix[][150],int row,int column){
    int rowIndexMatrix[100];
    int columnIndexMatrix[150];
    int index=0;
    for(int rowIndex=0;rowIndex<row;rowIndex++){
        for(int colIndex=0;colIndex<column;colIndex++){
           if(matrix[rowIndex][colIndex]==0){
              rowIndexMatrix[index]=rowIndex;
              columnIndexMatrix[index]=colIndex;
              index++;
           }
           else{
               continue;
           }
        }
    }
    int arguments[]={index,row,column};
   assignZero(matrix,rowIndexMatrix,columnIndexMatrix,arguments);
}

int main() {
    int row,column;
    int matrix[100][150];
    printf("Enter the number of row ");
    scanf("%d",&row);
    printf("Enter the number of column ");
    scanf("%d",&column);
    
    for(int rowIndex=0;rowIndex<row;rowIndex++){
        for(int colIndex=0;colIndex<column;colIndex++){
            printf("Enter element at (%d,%d):- ",rowIndex,colIndex);
            scanf("%d",&matrix[rowIndex][colIndex]);
        }
    }
    printf("\nMatrix is \n");
     for(int rowIndex=0;rowIndex<row;rowIndex++){
        for(int colIndex=0;colIndex<column;colIndex++){
            printf("%d ",matrix[rowIndex][colIndex]);
        }
        printf("\n");
    }
    
    makingRowAndColumnZero(matrix,row,column);
    printf("\nUpdated Matrix is \n");
     for(int rowIndex=0;rowIndex<row;rowIndex++){
        for(int colIndex=0;colIndex<column;colIndex++){
            printf("%d ",matrix[rowIndex][colIndex]);
        }
        printf("\n");
    }
    return 0;
}
