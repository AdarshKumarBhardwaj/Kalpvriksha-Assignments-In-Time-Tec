#include <stdio.h>

// function  to calculate modular exponentiation
int modularPow(int base, int exponent, int modulus)
{
    int result = 1;
    base = base % modulus;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (int)(((long long)result * base) % modulus);
        }

        base = (int)(((long long)base * base) % modulus);
        exponent = exponent >> 1;
    }
    return result;
}

int main()
{
    int B, N, M;
    int isValid = 1;

    printf("Enter Base Value (B, positive integer): ");
    scanf("%d", &B);
    if (B <= 0)
    {
        printf("Invalid input for B. It must be a positive integer.\n");
        isValid = 0;
    }

    printf("Enter Exponent Value (N, non-negative integer): ");
    scanf("%d", &N);
    if (N < 0)
    {
        printf("Invalid input for N. It must be a non-negative integer.\n");
        isValid = 0;
    }

    printf("Enter Modulus Value (M, positive integer greater than 1): ");
    scanf("%d", &M);
    if (M <= 1)
    {
        printf("Invalid input for M. It must be a positive integer greater than 1.\n");
        isValid = 0;
    }

    // If inputs are valid, calculate the result
    if (isValid)
    {
        int result = modularPow(B, N, M);
        printf("Result: %d\n", result);
    }
    else
    {
        printf("Exiting due to invalid input.\n");
    }

    return 0;
}
