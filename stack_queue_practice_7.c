// Problem Statement:-Reverse a string using stack data structure. 

// Write a C program to reverse a given string using a stack. 
// You can only use stack operations: push, pop, and isEmpty.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define size 15

typedef struct
{
    char stack[size];
    int top;
} string;

void initializeStack(string *stringPointer)
{
    stringPointer->top = -1;
}

void push(string *stringPointer, char data)
{
    if (stringPointer->top == size - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        stringPointer->top++;
        stringPointer->stack[stringPointer->top] = data;
    }
}

char pop(string *stringPointer)
{
    if (stringPointer->top == -1)
    {
        printf("UnderFlow\n");
        return '\0';
    }
    return stringPointer->stack[stringPointer->top--];
}

bool isEmpty(string *stringPointer)
{
    return stringPointer->top == -1;
}

void reverseString(string *stringPointer, char string[])
{
    int index = 0;
    int outputIndex = 0;
    int length = strlen(string);
    char outputString[length];
    while (string[index] != '\0')
    {
        push(stringPointer, string[index]);
        index++;
    }
    while (!isEmpty(stringPointer))
    {
        int poppedElement = pop(stringPointer);
        outputString[outputIndex++] = poppedElement;
    }
    outputString[outputIndex] = '\0';
    printf(" Reversed String is %s ", outputString);
}

int main()
{
    string myString;
    char string[100];
    printf("Enter String\n");
    scanf("%s", string);
    initializeStack(&myString);
    reverseString(&myString, string);
}

