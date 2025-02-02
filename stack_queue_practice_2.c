#include <stdio.h>
#include <stdlib.h>
#define size 15

typedef struct
{
    int stack[size];
    int top;
} smaller;

void initializeStack(smaller *smallerPointer)
{
    smallerPointer->top = -1;
}

void push(smaller *smallerPointer, int data)
{
    if (smallerPointer->top == size - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        smallerPointer->top++;
        smallerPointer->stack[smallerPointer->top] = data;
    }
}

void pop(smaller *smallerPointer)
{
    if (smallerPointer->top == -1)
    {
        printf("UnderFlow\n");
    }
    else
    {
        smallerPointer->top--;
    }
}

void previousSmallerElements(smaller *smallerPointer, int elements[], int size1)
{
    int previousElements[size1];
    int previousIndex = 0;
    for (int index = 0; index < size1; index++)
    {
        if (smallerPointer->top == -1)
        {
            previousElements[previousIndex++] = -1;
            push(smallerPointer, elements[index]);
        }
        else if (smallerPointer->stack[smallerPointer->top] < elements[index])
        {
            previousElements[previousIndex++] = smallerPointer->stack[smallerPointer->top];
            push(smallerPointer, elements[index]);
        }
        else
        {
            while ((smallerPointer->top != -1) && (smallerPointer->stack[smallerPointer->top] >= elements[index]))
            {
                pop(smallerPointer);
            }
            if (smallerPointer->top == -1)
            {

                previousElements[previousIndex++] = -1;
                push(smallerPointer, elements[index]);
            }
            else
            {
                previousElements[previousIndex++] = smallerPointer->stack[smallerPointer->top];
                push(smallerPointer, elements[index]);
            }
        }
    }
    for (int index = 0; index < previousIndex; index++)
    {
        printf("%d ", previousElements[index]);
    }
}
int main()
{
    int sizeOfArray;
    smaller mySmalller;
    printf("Enter size of array\n");
    scanf("%d", &sizeOfArray);
    int *elements = (int *)malloc(sizeOfArray * sizeof(int));
    printf("Enter elements of array\n");
    for (int index = 0; index < sizeOfArray; index++)
    {
        scanf("%d", &elements[index]);
    }
    initializeStack(&mySmalller);
    previousSmallerElements(&mySmalller, elements, sizeOfArray);
}