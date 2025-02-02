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
    if (prefixPointer->top == -1)
    {
        return false;
    }
    strcpy(result, prefixPointer->stack[prefixPointer->top--]);
    return true;
}

bool isEmpty(prefix *prefixPointer)
{
    return prefixPointer->top == -1;
}

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void prefixToInfix(prefix *prefixPointer, char string[])
{
    int length = strlen(string);
    initializeStack(prefixPointer);

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
            char op1[SIZE], op2[SIZE], result[SIZE];

            if (!pop(prefixPointer, op1) || !pop(prefixPointer, op2))
            {
                printf("Error: Invalid prefix expression\n");
                return;
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
            return;
        }
    }

    char finalResult[SIZE];
    if (!pop(prefixPointer, finalResult) || !isEmpty(prefixPointer))
    {
        printf("Error: Invalid prefix expression\n");
        return;
    }

    printf("Infix Expression: %s\n", finalResult);
}

int main()
{
    prefix myprefix;
    char string[SIZE];

    printf("Enter prefix expression: ");
    scanf("%s", string);

    prefixToInfix(&myprefix, string);
    return 0;
}
