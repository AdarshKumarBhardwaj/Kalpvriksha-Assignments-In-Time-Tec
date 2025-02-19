// Problem Statement:-Stock span for each day.
// Given an array of stock prices, calculate the stock span for each day. 
// The span is the number of consecutive days before the current day where the price was less than or equal to the current price.
// Example:
// Input: [100, 80, 60, 70, 60, 75, 85]
// Output: [1, 1, 1, 2, 1, 4, 6]


#include <stdio.h>
#include <stdlib.h>

#define SIZE 15

typedef struct
{
    int stack[SIZE];
    int top;
} stock;

void initializeStack(stock *stockPointer)
{
    stockPointer->top = -1;
}

void push(stock *stockPointer, int data)
{
    if (stockPointer->top == SIZE - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        stockPointer->stack[++(stockPointer->top)] = data;
    }
}

void pop(stock *stockPointer)
{
    if (stockPointer->top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        stockPointer->top--;
    }
}

int top(stock *stockPointer)
{
    if (stockPointer->top == -1)
        return -1;
    return stockPointer->stack[stockPointer->top];
}

void stockSpan(stock *stockPointer, int elements[], int size1)
{
    int span[size1];

    for (int index = 0; index < size1; index++)
    {
        while (stockPointer->top != -1 && elements[top(stockPointer)] <= elements[index])
        {
            pop(stockPointer);
        }

        if (stockPointer->top == -1)
        {
            span[index] = index + 1;
        }
        else
        {
            span[index] = index - top(stockPointer);
        }

        push(stockPointer, index);
    }

    for (int i = 0; i < size1; i++)
    {
        printf("%d ", span[i]);
    }
    printf("\n");
}

int main()
{
    int sizeOfArray;
    stock myStock;

    printf("Enter size of array: ");
    scanf("%d", &sizeOfArray);

    int *elements = (int *)malloc(sizeOfArray * sizeof(int));
    if (!elements)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter elements of array: ");
    for (int i = 0; i < sizeOfArray; i++)
    {
        scanf("%d", &elements[i]);
    }

    initializeStack(&myStock);
    stockSpan(&myStock, elements, sizeOfArray);

    free(elements);
    return 0;
}

