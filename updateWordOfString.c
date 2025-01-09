#include <stdio.h>
#include <string.h>

char sentence[100];
char wordToReplace[] = "love";
char replacementWord[] = "enjoy";
char result[100];

void removeNewline()
{
    int i = 0;
    while (sentence[i] != '\0')
    {
        if (sentence[i] == '\n')
        {
            sentence[i] = '\0';
            break;
        }
        i++;
    }
}

void replaceWord()
{
    int i = 0, j = 0, k, match = 0;

    while (sentence[i] != '\0')
    {
        if (sentence[i] == wordToReplace[0])
        {
            match = 1;
            for (k = 0; wordToReplace[k] != '\0'; k++)
            {
                if (sentence[i + k] != wordToReplace[k])
                {
                    match = 0;
                    break;
                }
            }
            if (match == 1)
            {
                for (k = 0; replacementWord[k] != '\0'; k++, j++)
                {
                    result[j] = replacementWord[k];
                }
                i += strlen(wordToReplace);
            }
        }
        if (match == 0)
        {
            result[j++] = sentence[i++];
        }
        else
        {
            match = 0;
        }
    }
    result[j] = '\0';
}

int main()
{
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    removeNewline();
    replaceWord();
    printf("Updated sentence: %s\n", result);

    return 0;
}
