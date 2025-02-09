// Given a number N, generate all binary numbers from 1 to N using a queue.
// Example Input: 5
// Example Output: 001, 010, 011, 100, 101


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
#define MAX_STRING_LENGTH 20

typedef struct
{
    char queue[MAX_QUEUE_SIZE][MAX_STRING_LENGTH];
    int front;
    int rear;
} queue;

void initializeQueue(queue *queuePointer)
{
    queuePointer->front = -1;
    queuePointer->rear = -1;
}

void enqueue(queue *queuePointer, char data[])
{
    if (queuePointer->rear == MAX_QUEUE_SIZE - 1)
    {
        printf("Overflow\n");
    }
    else if (queuePointer->front == -1 && queuePointer->rear == -1)
    {
        queuePointer->front = 0;
        queuePointer->rear = 0;
        strcpy(queuePointer->queue[queuePointer->rear], data);
    }
    else
    {
        queuePointer->rear++;
        strcpy(queuePointer->queue[queuePointer->rear], data);
    }
}

char *dequeue(queue *queuePointer)
{
    if (queuePointer->front == -1 && queuePointer->rear == -1)
    {
        printf("Underflow\n");
        return NULL;
    }

    char *dequeuedElement = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
    strcpy(dequeuedElement, queuePointer->queue[queuePointer->front]);

    if (queuePointer->front == queuePointer->rear)
    {
        queuePointer->front = -1;
        queuePointer->rear = -1;
    }
    else
    {
        queuePointer->front++;
    }

    return dequeuedElement;
}

int calculateBitSize(int number)
{
    int bitSize = 0;
    int temp = number;
    while (temp > 0)
    {
        temp /= 2;
        bitSize++;
    }
    return bitSize;
}

void generateBinaryNumber(queue *queuePointer, int number)
{
    char result[number][MAX_STRING_LENGTH];

    enqueue(queuePointer, "1");

    for (int index = 0; index < number; index++)
    {
        char *frontElement = dequeue(queuePointer);
        if (frontElement == NULL)
        {
            return;
        }

        strcpy(result[index], frontElement);
        free(frontElement);

        char number1[MAX_STRING_LENGTH], number2[MAX_STRING_LENGTH];

        strcpy(number1, result[index]);
        strcat(number1, "0");

        strcpy(number2, result[index]);
        strcat(number2, "1");

        enqueue(queuePointer, number1);
        enqueue(queuePointer, number2);
    }

    int bitSize = calculateBitSize(number);

    for (int index = 0; index < number; index++)
    {
        int length = strlen(result[index]);
        for (int j = 0; j < bitSize - length; j++)
        {
            printf("0");
        }
        printf("%s", result[index]);

        if (index < number - 1)
        {
            printf(", ");
        }
    }
    printf("\n");
}

int main()
{
    queue myQueue;
    initializeQueue(&myQueue);

    int number;
    printf("Enter the value of N: ");
    scanf("%d", &number);

    generateBinaryNumber(&myQueue, number);

    return 0;
}



