#include <stdio.h>

int stringLength(char *string)
{
    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    return length;
}

int isPalindrome(char *string, int startIndex, int endIndex)
{
    while (startIndex < endIndex)
    {
        if (string[startIndex] != string[endIndex])
        {
            return 0;
        }
        startIndex++;
        endIndex--;
    }
    return 1;
}

void removeNewline(char *string)
{
    int length = stringLength(string);
    if (length > 0 && string[length - 1] == '\n')
    {
        string[length - 1] = '\0';
    }
}

void findLongestPalindrome(char *string)
{
    int maxLength = 1;
    int startingPoint = 0;
    int length = stringLength(string);

    for (int startIndex = 0; startIndex < length; startIndex++)
    {
        for (int endIndex = startIndex; endIndex < length; endIndex++)
        {
            if (isPalindrome(string, startIndex, endIndex) && (endIndex - startIndex + 1) > maxLength)
            {
                startingPoint = startIndex;
                maxLength = endIndex - startIndex + 1;
            }
        }
    }

    for (int currentIndex = startingPoint; currentIndex < startingPoint + maxLength; currentIndex++)
    {
        printf("%c", string[currentIndex]);
    }
    printf("\n");
}

int main()
{
    char inputString[100];
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);
    removeNewline(inputString);
    findLongestPalindrome(inputString);
    return 0;
}
