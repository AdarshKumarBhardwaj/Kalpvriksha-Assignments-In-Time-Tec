#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_TRANSACTION 10000

typedef struct hashNode {
    int transactionId;
    int userId;
    float amount;
    int timeStamps;
    struct hashNode* next;
} hashNode;

hashNode* hashTable[MAX_TRANSACTION] = { NULL };

int hash(int userId) {
    return userId % MAX_TRANSACTION;
}

void insertTransaction() {
    int transactionId;
    int userId;
    float amount;
    int timeStamps;

    printf("Enter transaction id ");
    scanf("%d", &transactionId);
    printf("Enter userId ");
    scanf("%d", &userId);
    printf("Enter Amount ");
    scanf("%f", &amount);
    printf("Enter timestamps ");
    scanf("%d", &timeStamps);

    int index = hash(userId);
    hashNode* newNode = (hashNode*)malloc(sizeof(hashNode));

    newNode->transactionId = transactionId;
    newNode->userId = userId;
    newNode->amount = amount;
    newNode->timeStamps = timeStamps;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    }
    else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
    printf("\n");
}

void detectDuplicateTransaction() {
    for (int i = 0; i < MAX_TRANSACTION; i++) {
        hashNode* current = hashTable[i];
        while (current != NULL) {
            hashNode* temp = current->next;
            while (temp != NULL) {
                if (current->userId == temp->userId &&
                    current->amount == temp->amount &&
                    abs(current->timeStamps - temp->timeStamps) < 60) {
                    printf("Duplicate Transaction IDs: %d and %d\n", current->transactionId, temp->transactionId);
                }
                temp = temp->next;
            }
            current = current->next;
        }
    }
    printf("\n");
}

void removeDuplicateTransaction() {
    for (int i = 0; i < MAX_TRANSACTION; i++) {
        hashNode* current = hashTable[i];
        hashNode* prev = NULL;

        while (current != NULL) {
            hashNode* nextNode = current->next;
            hashNode* temp = nextNode;

            while (temp != NULL) {
                if (current->userId == temp->userId &&
                    current->amount == temp->amount &&
                    abs(current->timeStamps - temp->timeStamps) < 60) {


                    if (prev == NULL) {
                        hashTable[i] = nextNode;
                    }
                    else {
                        prev->next = nextNode;
                    }
                    current = temp;
                    break;
                }
                temp = temp->next;
            }
            prev = current;
            current = nextNode;
        }
    }
    printf("\n");
}

void displayTransactions() {
    printf("Transactions:\n");
    for (int i = 0; i < MAX_TRANSACTION; i++) {
        hashNode* current = hashTable[i];
        while (current != NULL) {
            printf("Transaction ID: %d, User ID: %d, Amount: %.2f, Timestamp: %d\n",
                current->transactionId,
                current->userId,
                current->amount,
                current->timeStamps);
            current = current->next;
        }
    }
    printf("\n");
}

int main() {
    int noOfTransaction;
    printf("Enter number of transaction\n");
    scanf("%d", &noOfTransaction);
    if (noOfTransaction > MAX_TRANSACTION) {
        printf("Enter valid number of transaction\n");
        return 1;
    }
    printf("1. Insert Transaction\n");
    printf("2. Detect Transaction\n");
    printf("3. Remove Transaction\n");
    printf("4. Display Transaction\n");
    int choice;
    do {
        printf("Enter choice\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:insertTransaction();
            break;
        case 2:detectDuplicateTransaction();
            break;
        case 3:removeDuplicateTransaction();
            break;
        case 4:displayTransactions();
            break;
        case 0:printf("Existing\n");
            break;
        default:printf("Wrong choice\n");
            break;
        }
    } while (choice != 0);

    return 0;
}

