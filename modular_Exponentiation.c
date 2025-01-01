#include <stdio.h>

int modular_pow(int base, int exponent, int modulus)
{
    int result = 1;
    base = base % modulus;

    while (exponent > 0)
    {
        // If the exponent is odd, multiply result with base and reduce modulo
        if (exponent % 2 == 1)
        {
            result = (int)(((long long)result * base) % modulus);
        }
        // Reduce base by squaring and applying modulo
        base = (int)(((long long)base * base) % modulus);
        exponent = exponent >> 1;
    }
    return result;
}

int main()
{
    int B, N, M;
    int isValid = 1;

    // Input for Base B
    printf("Enter Base Value (B, positive integer): ");
    if (scanf("%d", &B) != 1 || B <= 0)
    {
        printf("Invalid input for B. It must be a positive integer.\n");
        isValid = 0;
    }

    // Input for Exponent N
    printf("Enter Exponent Value (N, non-negative integer): ");
    if (isValid && (scanf("%d", &N) != 1 || N < 0))
    {
        printf("Invalid input for N. It must be a non-negative integer.\n");
        isValid = 0;
    }

    // Input for Modulus M
    printf("Enter Modulus Value (M, positive integer greater than 1): ");
    if (isValid && (scanf("%d", &M) != 1 || M <= 1))
    {
        printf("Invalid input for M. It must be a positive integer greater than 1.\n");
        isValid = 0;
    }

    // If inputs are valid, calculate the result
    if (isValid)
    {
        int result = modular_pow(B, N, M);
        printf("Result: %d\n", result);
    }
    else
    {
        printf("Exiting due to invalid input.\n");
    }

    return 0;
}
