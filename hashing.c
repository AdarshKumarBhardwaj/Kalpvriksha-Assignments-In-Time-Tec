#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define HashTableSize 10

struct Node {
    char name[20];
    struct Node *next;
};

struct Node *hashtable[HashTableSize];

void sortString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int hash(char *str) {
    char sortedStr[20];
    strcpy(sortedStr, str);
    sortString(sortedStr);
    
    int sum = 0;
    for (int i = 0; i < strlen(sortedStr); i++) {
        sum += sortedStr[i];
    }
    return sum % HashTableSize;
}

void insertInHashtable(char word[][20], int number) {
    for (int i = 0; i < number; i++) {
        int index = hash(word[i]);
        
        struct Node *newNode = malloc(sizeof(struct Node));
        strcpy(newNode->name, word[i]);
        newNode->next = NULL;

        if (hashtable[index] == NULL) {
            hashtable[index] = newNode;
        } else {
            struct Node *temp = hashtable[index];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void printAnagramGroups() {
    int j=0;
    for (int i = 0; i < HashTableSize; i++) {
        if (hashtable[i] != NULL) {
            printf("Anagram Group %d: ",++j);
            struct Node *temp = hashtable[i];
            while (temp != NULL) {
                printf("%s", temp->name);
                if (temp->next != NULL) printf(" -> ");
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

int main() {
    int number;
    printf("Enter number of words to insert: ");
    scanf("%d", &number);

    char word[20][20];
    printf("Enter Words:\n");
    for (int index = 0; index < number; index++) {
        scanf("%s", word[index]);
    }

    insertInHashtable(word, number);
    
    printAnagramGroups();

   

    return 0;
}

