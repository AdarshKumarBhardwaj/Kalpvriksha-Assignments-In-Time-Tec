// Sort a stack in ascending order.
// Implement a function to sort a stack such that the smallest element is at the top.
// You can use only one additional stack as a temporary space.
// You can only use stack operations: push, pop, and isEmpty

#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 5

typedef struct
{
    int stack[MAX_SIZE];
    int temporaryStack[MAX_SIZE];
    int top1;
    int top2;
} stack;

void initializeStack(stack *stackPointer)
{
    stackPointer->top1 = -1;
    stackPointer->top2 = -1;
}

void push1(stack *stackPointer, int data)
{
    if (stackPointer->top1 == MAX_SIZE - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        stackPointer->top1++;
        stackPointer->stack[stackPointer->top1] = data;
    }
}

void push2(stack *stackPointer, int data)
{
    if (stackPointer->top2 == MAX_SIZE - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        stackPointer->top2++;
        stackPointer->temporaryStack[stackPointer->top2] = data;
    }
}

void pop1(stack *stackPointer)
{
    if (stackPointer->top1 == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        stackPointer->top1--;
    }
}
void pop2(stack *stackPointer)
{
    if (stackPointer->top2 == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        stackPointer->top2--;
    }
}

bool isStackEmpty(stack *stackPointer)
{
    return stackPointer->top1 == -1;
}

bool isTempStackEmpty(stack *stackPointer)
{
    return stackPointer->top2 == -1;
}

void sortStack(stack *stackPointer)
{
    while (!isStackEmpty(stackPointer))
    {
        int topElement = stackPointer->stack[stackPointer->top1];
        pop1(stackPointer);
        while (!isTempStackEmpty(stackPointer) && stackPointer->temporaryStack[stackPointer->top2] < topElement)
        {
            push1(stackPointer, stackPointer->temporaryStack[stackPointer->top2]);
            pop2(stackPointer);
        }
        push2(stackPointer, topElement);
    }

    while (!isTempStackEmpty(stackPointer))
    {
        printf("%d ", stackPointer->temporaryStack[stackPointer->top2]);
        pop2(stackPointer);
    }
}

int main()
{
    stack myStack;
    initializeStack(&myStack);
    int data;
    printf("Enter the stack element\n");
    for (int index = 0; index < MAX_SIZE; index++)
    {
        printf("Enter value\n");
        scanf("%d", &data);
        push1(&myStack, data);
    }
    sortStack(&myStack);
}

