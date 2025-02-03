// Valid Parentheses 
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
// determine if the input string is valid. 

// An input string is valid if: 
// Open brackets must be closed by the same type of brackets. 
// Open brackets must be closed in the correct order. 
// Every close bracket has a corresponding open bracket of the same type. 

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STACK_MAX_SIZE 10
#define STRING_SIZE 20

typedef struct
{
    char stack[STACK_MAX_SIZE];
    int top;
} stack;

void initializeStack(stack *stackPointer)
{
    stackPointer->top = -1;
}

void push(stack *stackPointer, char data)
{
    if (stackPointer->top == STACK_MAX_SIZE - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        stackPointer->stack[++stackPointer->top] = data;
    }
}

char pop(stack *stackPointer)
{
    if (stackPointer->top == -1)
    {
        return '\0';
    }
    return stackPointer->stack[stackPointer->top--];
}

bool isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool checkParenthesis(stack *stackPointer, char string[])
{
    int length = strlen(string);

    for (int index = 0; index < length; index++)
    {
        char ch = string[index];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(stackPointer, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (stackPointer->top == -1)
            {
                return false;
            }
            char topChar = pop(stackPointer);
            if (!isMatchingPair(topChar, ch))
            {
                return false;
            }
        }
    }

    return stackPointer->top == -1;
}

int main()
{
    stack myStack;
    initializeStack(&myStack);

    char string[STRING_SIZE];
    printf("Enter parenthesis string for check: ");
    fgets(string, STRING_SIZE, stdin);
    string[strcspn(string, "\n")] = '\0';

    bool isValid = checkParenthesis(&myStack, string);
    if (isValid)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }

    return 0;
}

