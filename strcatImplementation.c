#include <stdio.h>
#include <string.h>

int stringLength(char *string)
{
    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    return length;
}

void strcatImplementation(char string1[], char string2[], int bufferSize)
{
    int lengthOfString1 = stringLength(string1);
    int lengthOfString2 = stringLength(string2);

    int canConcatenate = 1;

    if (lengthOfString1 + lengthOfString2 >= bufferSize)
    {
        canConcatenate = 0;
        printf("Error: Buffer overflow.\n");
    }

    if (canConcatenate)
    {
        int index1 = lengthOfString1;
        int index2 = 0;
        while (string2[index2] != '\0')
        {
            string1[index1++] = string2[index2++];
        }
        string1[index1] = '\0';
        printf("Concatenated String is: %s\n", string1);
    }
}

int main()
{
    char string1[100];
    char string2[100];

    printf("Enter the Original String\n");
    fgets(string1, sizeof(string1), stdin);
    string1[strcspn(string1, "\n")] = '\0';

    printf("Enter the String for concatenation\n");
    fgets(string2, sizeof(string2), stdin);
    string2[strcspn(string2, "\n")] = '\0';

    strcatImplementation(string1, string2, sizeof(string1));

    return 0;
}

