#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 200
#define MAX_WORDS 100

int stringLength(char *string){
    int length=0;
    int index=0;
    while(string[index]!='\0'){
        length++;
        index++;
    }
    return length;
}

void printWords(char sentence[], int startIndexArray[], int lastIndexArray[], int wordCount, int targetLength) {
    for (int index1 = 0; index1 < wordCount; index1++) {
        int length = lastIndexArray[index1] - startIndexArray[index1] + 1;
        if (length == targetLength) {
            for (int index2 = startIndexArray[index1]; index2 <= lastIndexArray[index1]; index2++) {
                printf("%c", sentence[index2]);
            }
            printf("\n");
        }
    }
}

void findLongestAndShortestWords(char sentence[]) {
    int startIndexArray[MAX_WORDS];
    int lastIndexArray[MAX_WORDS];
    int wordCount = 0;

    char *token = strtok(sentence, " \n");
    while (token != NULL) {
        int startIndex = token - sentence;
        int length = stringLength(token);

        startIndexArray[wordCount] = startIndex;
        lastIndexArray[wordCount] = startIndex + length - 1;
        wordCount++;

        token = strtok(NULL, " \n");
    }

    if (wordCount == 0) {
        printf("No word found in the input.\n");
    }
    else{
    int longestLength = 0;
    int smallestLength = MAX_LENGTH;

    for (int index = 0; index < wordCount; index++) {
        int length = lastIndexArray[index] - startIndexArray[index] + 1;
        if (length > longestLength) {
            longestLength = length;
        }
        if (length < smallestLength) {
            smallestLength = length;
        }
    }

    printf("Longest Words:\n");
    printWords(sentence, startIndexArray, lastIndexArray, wordCount, longestLength);

    printf("Shortest Words:\n");
    printWords(sentence,startIndexArray, lastIndexArray, wordCount, smallestLength);
    }
}

int main() {
    char sentence[MAX_LENGTH];

    printf("Enter the sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);

    findLongestAndShortestWords(sentence);

    return 0;
}

