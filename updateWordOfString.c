#include <stdio.h>
#include <string.h>

char inputSentence[100];
char targetWord[] = "love";
char substituteWord[] = "enjoy";
char updatedSentence[100];

void removeNewline()
{
    int currentIndex = 0;
    while (inputSentence[currentIndex] != '\0')
    {
        if (inputSentence[currentIndex] == '\n')
        {
            inputSentence[currentIndex] = '\0';
            break;
        }
        currentIndex++;
    }
}

void replaceWord()
{
    int sentenceIndex = 0, resultIndex = 0, tempIndex, isMatch = 0;

    while (inputSentence[sentenceIndex] != '\0')
    {
        if (inputSentence[sentenceIndex] == targetWord[0])
        {
            isMatch = 1;
            for (tempIndex = 0; targetWord[tempIndex] != '\0'; tempIndex++)
            {
                if (inputSentence[sentenceIndex + tempIndex] != targetWord[tempIndex])
                {
                    isMatch = 0;
                    break;
                }
            }
            if (isMatch == 1)
            {
                for (tempIndex = 0; substituteWord[tempIndex] != '\0'; tempIndex++, resultIndex++)
                {
                    updatedSentence[resultIndex] = substituteWord[tempIndex];
                }
                sentenceIndex += strlen(targetWord);
            }
        }
        if (isMatch == 0)
        {
            updatedSentence[resultIndex++] = inputSentence[sentenceIndex++];
        }
        else
        {
            isMatch = 0;
        }
    }
    updatedSentence[resultIndex] = '\0';
}

int main()
{
    printf("Enter a sentence: ");
    fgets(inputSentence, sizeof(inputSentence), stdin);

    removeNewline();
    replaceWord();
    printf("Updated sentence: %s\n", updatedSentence);

    return 0;
}
