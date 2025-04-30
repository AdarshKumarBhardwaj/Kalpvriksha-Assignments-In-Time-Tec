#include <stdio.h>
#include <stdbool.h>

double atofImplementaion(char string[])
{
    double result = 0.0;
    double fraction = 0.0;
    double divisor = 10.0;

    int sign = 1;
    int index = 0;
    bool fractionPart = false;
    bool isValid = true;
    while (string[index] == ' ')
    {
        index++;
    }
    if (string[index] == '-')
    {
        index++;
        sign = -1;
    }
    if (string[index] == '+')
    {
        index++;
    }

    for (; string[index] != '\0'; index++)
    {
        if (string[index] == '.')
        {
            if (fractionPart)
            {
                isValid = false;
                break;
            }
            fractionPart = true;
            continue;
        }

        if (string[index] < '0' || string[index] > '9')
        {
            isValid = false;
            break;
        }

        if (fractionPart)
        {
            fraction += (string[index] - '0') / divisor;
            divisor *= 10;
        }
        else
        {
            result = result * 10 + (string[index] - '0');
        }
    }

    if (!isValid)
    {
        return 0.0;
    }
    else
    {
        return sign * (result + fraction);
    }
}

int main()
{
    char string[100];
    printf("Enter the string\n");
    scanf("%s", string);
    printf("atof Implememtation of given string is %f ", atofImplementaion(string));
    return 0;
}

