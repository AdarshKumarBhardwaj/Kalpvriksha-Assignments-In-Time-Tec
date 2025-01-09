#include <stdio.h>

int stringLength(char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

int isPalindrome(char *str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

void removeNewline(char *str)
{
    int len = stringLength(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

void findLongestPalindrome(char *str)
{
    int maxLength = 1;
    int start = 0;
    int len = stringLength(str);

    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (isPalindrome(str, i, j) && (j - i + 1) > maxLength)
            {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }

    for (int i = start; i < start + maxLength; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    removeNewline(str);
    findLongestPalindrome(str);
    return 0;
}
