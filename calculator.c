#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isOperator(char character)
{
    return character == '+' || character == '-' || character == '*' || character == '/';
}

int operatorPrecedence(char operatorChar)
{
    int precedence = 0;
    if (operatorChar == '*' || operatorChar == '/')
    {
        precedence = 2;
    }
    else if (operatorChar == '+' || operatorChar == '-')
    {
        precedence = 1;
    }
    return precedence;
}

float performOperation(float operand1, float operand2, char operatorChar, int *error)
{
    float result = 0;
    switch (operatorChar)
    {
    case '+':
        result = operand1 + operand2;
        break;
    case '-':
        result = operand1 - operand2;
        break;
    case '*':
        result = operand1 * operand2;
        break;
    case '/':
        if (operand2 == 0)
        {
            *error = 1;
        }
        else
        {
            result = operand1 / operand2;
        }
        break;
    default:
        *error = 1;
    }
    return result;
}

void processOperator(float numbers[], int *topNumbers, char operators[], int *topOperators, int *error)
{
    if (*topOperators < 0 || *topNumbers < 1)
    {
        *error = 1;
    }
    else
    {
        float operand2 = numbers[(*topNumbers)--];
        float operand1 = numbers[(*topNumbers)--];
        char operatorChar = operators[(*topOperators)--];
        float result = performOperation(operand1, operand2, operatorChar, error);
        if (!*error)
        {
            numbers[++(*topNumbers)] = result;
        }
    }
}

float evaluateExpression(const char *expression, int *error)
{
    float numbers[100];
    int topNumbers = -1;
    char operators[100];
    int topOperators = -1;

    int i = 0, length = strlen(expression);
    while (i < length && !*error)
    {
        if (isspace(expression[i]))
        {
            i++;
            continue;
        }

        if (isdigit(expression[i]) || expression[i] == '.')
        {
            float number = 0;
            int hasDecimalPoint = 0;
            float divisor = 1;

            while (i < length && (isdigit(expression[i]) || expression[i] == '.'))
            {
                if (expression[i] == '.')
                {
                    hasDecimalPoint = 1;
                }
                else
                {
                    number = number * 10 + (expression[i] - '0');
                    if (hasDecimalPoint)
                    {
                        divisor *= 10;
                    }
                }
                i++;
            }
            number /= divisor;
            numbers[++topNumbers] = number;
        }
        else if (isOperator(expression[i]))
        {
            while (topOperators >= 0 &&
                   operatorPrecedence(operators[topOperators]) >= operatorPrecedence(expression[i]))
            {
                processOperator(numbers, &topNumbers, operators, &topOperators, error);
            }
            operators[++topOperators] = expression[i];
            i++;
        }
        else
        {
            *error = 1;
        }
    }

    while (topOperators >= 0 && !*error)
    {
        processOperator(numbers, &topNumbers, operators, &topOperators, error);
    }

    float result = 0;
    if (topNumbers == 0 && !*error)
    {
        result = numbers[topNumbers];
    }
    else
    {
        *error = 1;
    }
    return result;
}

int main()
{
    char input[100];
    printf("Enter the expression for calculation: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    int error = 0;
    float result = evaluateExpression(input, &error);

    if (error)
    {
        printf("Error: Invalid expression.\n");
    }
    else
    {
        printf("Result: %.2f\n", result);
    }

    return 0;
}
