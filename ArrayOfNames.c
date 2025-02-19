#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_ROWS 10
#define MAX_COLUMNS 101

int startsWithVowel(char name[MAX_NAME_LENGTH + 1])
{
    char firstChar = tolower(name[0]);
    return (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u');
}

int validateDeimension(int rowCount,int colCount){
    if (rowCount < 1 || rowCount > MAX_ROWS || colCount < 1 || colCount > MAX_COLUMNS)
    {
       printf("Invalid input for rows or columns.\n");
       return 0;
    }
    return 1;
}

void inputNames(char names[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH + 1],int rowCount,int colCount){
     printf("Enter the names:\n");
    for (int rowIndex = 0; rowIndex < rowCount; rowIndex++)
    {
        for (int colIndex = 0; colIndex < colCount; colIndex++)
        {
            printf("Name at (%d,%d): ", rowIndex, colIndex);
            scanf("%s", names[rowIndex][colIndex]);
        }
     }
}

void processNames(char  names[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH + 1],int values[3] ,char longestName[MAX_NAME_LENGTH + 1]){
    int rowCount=values[0];
    int colCount=values[1];
    values[2]=0;
    int maxLength=0;
     for (int rowIndex = 0; rowIndex < rowCount; rowIndex++)
    {
        for (int colIndex = 0; colIndex < colCount; colIndex++)
        {
            if (startsWithVowel(names[rowIndex][colIndex]))
            {
                values[3]++;
            }

            int nameLength = strlen(names[rowIndex][colIndex]);
            if (nameLength > maxLength)
            {
                maxLength = nameLength;
                strcpy(longestName, names[rowIndex][colIndex]);
            }
        }
    }
}
void printNamesArray(char names[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH + 1],int rowCount,int colCount){
     printf("\nThe 2D array of names is:\n");
    for (int rowIndex = 0; rowIndex < rowCount; rowIndex++)
    {
        for (int colIndex = 0; colIndex < colCount; colIndex++)
        {
            printf("%s ", names[rowIndex][colIndex]);
        }
        printf("\n");
    }
}


int main()
{   
    int values[3];
    int rowCount, colCount;
    int vowelCount = 0;
    char longestName[MAX_NAME_LENGTH + 1];
    
    printf("Enter number of rows: ");
    scanf("%d", &rowCount);
    printf("Enter number of columns: ");
    scanf("%d", &colCount);
    
    values[0]=rowCount;
    values[1]=colCount;
    values[2]=0;
    
    if(!validateDeimension(rowCount,colCount)){
        return 1;
    }
    char names[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH + 1];
    inputNames(names,rowCount,colCount);
    processNames(names,values,longestName);
    printNamesArray(names,rowCount,colCount); 
    
    printf("\nNumber of names starting with a vowel: %d\n", vowelCount);
    printf("The longest name: %s\n", longestName);

    return 0;
}

