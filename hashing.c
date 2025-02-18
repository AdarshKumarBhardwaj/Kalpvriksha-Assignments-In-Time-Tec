#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_TABLE_SIZE 10
#define NUMBER_OF_WORDS 10
#define WORD_SIZE 20

typedef struct Node {
    char word[WORD_SIZE];
    struct Node *next;
} HashNode;

bool isAnagram(const char *str1, const char *str2) {
    int count1[26] = {0};
    int count2[26] = {0};
    int index;

    for (index = 0; str1[index] != '\0'; index++) {
        count1[str1[index] - 'a']++;
    }

    for (index = 0; str2[index] != '\0'; index++) {
        count2[str2[index] - 'a']++;
    }

    for (index = 0; index < 26; index++) {
        if (count1[index] != count2[index]) {
            return false;
        }
    }

    return true;
}

void insertIntoTable(char words[][WORD_SIZE], int size) {
    HashNode *hashTable[HASH_TABLE_SIZE] = {NULL};

    for (int i = 0; i < size; i++) {
        for (int index = 0; index < HASH_TABLE_SIZE; index++) {
            if (hashTable[index] == NULL) {
                HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
                strcpy(newNode->word, words[i]);
                newNode->next = NULL;
                hashTable[index] = newNode;
                break;
            } 
            else if (isAnagram(words[i], hashTable[index]->word)) {
                HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
                strcpy(newNode->word, words[i]);
                newNode->next = hashTable[index]->next;
                hashTable[index]->next = newNode;
                break;
            }
        }

       
    }

   int j=0;
    for (int index = 0; index < HASH_TABLE_SIZE; index++) {
        if (hashTable[index] != NULL) {
            printf("Anagram Group %d: ",++j);
            HashNode *temp = hashTable[index];
            while (temp != NULL) {
                printf("%s", temp->word);
                if (temp->next != NULL) printf(" -> ");
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    char words[NUMBER_OF_WORDS][WORD_SIZE];

    printf("Enter number of words: ");
    scanf("%d", &n);


    printf("Enter words:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    insertIntoTable(words, n);

    return 0;
}
