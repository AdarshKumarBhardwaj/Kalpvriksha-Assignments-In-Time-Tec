// Prefix to Infix Conversion 
// Problem Statement: You are given a string S of size N that represents the prefix form of a valid mathematical
// expression. The string S contains only lowercase and uppercase alphabets as operands and the operators are
//  +, -, *, /, %, and ^. Convert it to its infix form.


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 50

typedef struct
{
    char stack[SIZE][SIZE];
    int top;
} prefix;

void initializeStack(prefix *prefixPointer)
{
    prefixPointer->top = -1;
}

void push(prefix *prefixPointer, char data[])
{
    if (prefixPointer->top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    prefixPointer->top++;
    strcpy(prefixPointer->stack[prefixPointer->top], data);
}

bool pop(prefix *prefixPointer, char result[])
{
    bool status = false;

    if (prefixPointer->top != -1)
    {
        strcpy(result, prefixPointer->stack[prefixPointer->top]);
        prefixPointer->top--;
        status = true;
    }

    return status;
}

bool isEmpty(prefix *prefixPointer)
{
    return prefixPointer->top == -1;
}

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

bool prefixToInfix(prefix *prefixPointer, char string[], char result[])
{
    int length = strlen(string);
    initializeStack(prefixPointer);
    bool errorOccurred = false;

    for (int index = length - 1; index >= 0; index--)
    {
        char token[2] = {string[index], '\0'};

        if ((string[index] >= 'A' && string[index] <= 'Z') ||
            (string[index] >= 'a' && string[index] <= 'z') ||
            (string[index] >= '0' && string[index] <= '9'))
        {
            push(prefixPointer, token);
        }
        else if (isOperator(string[index]))
        {
            char op1[SIZE], op2[SIZE];

            if (!pop(prefixPointer, op1) || !pop(prefixPointer, op2))
            {
                printf("Error: Invalid prefix expression\n");
                errorOccurred = true;
                break;
            }

            strcpy(result, "(");
            strcat(result, op1);
            strcat(result, token);
            strcat(result, op2);
            strcat(result, ")");

            push(prefixPointer, result);
        }
        else
        {
            printf("Error: Invalid character '%c' in expression\n", string[index]);
            errorOccurred = true;
            break;
        }
    }

    if (errorOccurred)
    {
        return false;
    }

    char finalResult[SIZE];
    if (!pop(prefixPointer, finalResult) || !isEmpty(prefixPointer))
    {
        printf("Error: Invalid prefix expression\n");
        return false;
    }

    strcpy(result, finalResult);
    return true;
}

int main()
{
    prefix myprefix;
    char string[SIZE];
    char result[SIZE];

    printf("Enter prefix expression: ");
    scanf("%s", string);

    bool success = prefixToInfix(&myprefix, string, result);

    if (success)
    {
        printf("Infix Expression: %s\n", result);
    }
    else
    {
        printf("Invalid prefix expression.\n");
    }

    return 0;
}


