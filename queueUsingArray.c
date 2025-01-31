#include <stdio.h>
#include <stdbool.h>
#define size 10

typedef struct
{
    int queue[size];
    int front;
    int rear;
} queue;

void initialializeQueue(queue *queuePointer)
{
    queuePointer->front = -1;
    queuePointer->rear = -1;
}

void enqueue(queue *queuePointer)
{
    int data;
    printf("Enter value\n");
    scanf("%d", &data);

    if (queuePointer->rear == size - 1)
    {
        printf("Overflow\n");
    }
    else if (queuePointer->front == -1 && queuePointer->rear == -1)
    {
        queuePointer->front = 0;
        queuePointer->rear = 0;
        queuePointer->queue[queuePointer->rear] = data;
    }
    else
    {
        queuePointer->rear++;
        queuePointer->queue[queuePointer->rear] = data;
    }
    printf("\n");
}

void dequeue(queue *queuePointer)
{
    if (queuePointer->front == -1 && queuePointer->rear == -1)
    {
        printf("Underflow\n");
    }
    else if (queuePointer->front == queuePointer->rear)
    {
        queuePointer->front = -1;
        queuePointer->rear = -1;
    }
    else
    {
        printf("Dequeued element of queue is %d ", queuePointer->queue[queuePointer->front]);
        queuePointer->front++;
    }
    printf("\n");
}

void peek(queue *queuePointer)
{
    if (queuePointer->front == -1 && queuePointer->rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Front element of queue is %d \n", queuePointer->queue[queuePointer->front]);
    }
    printf("\n");
}

bool isEmpty(queue *queuePointer)
{
    if (queuePointer->front == -1 && queuePointer->rear == -1)
    {
        return true;
    }
    return false;
}

void findSize(queue *queuePointer)
{
    if (queuePointer->front == -1 && queuePointer->rear == -1)
    {
        printf("size of queue is 0 \n");
    }
    else
    {
        printf("Size of queue is %d ", (queuePointer->rear - queuePointer->front + 1));
    }
    printf("\n");
}

int main()
{
    queue myQueue;
    bool empty;
    initialializeQueue(&myQueue);
    int choice;
    printf("1. push element in queue\n");
    printf("2. pop an element from queue\n");
    printf("3. find front element of queue\n");
    printf("4. check queue is empty or not\n");
    printf("5. find size of queue\n");
    printf("for exit enter 0\n");
    do
    {

        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&myQueue);
            break;
        case 2:
            dequeue(&myQueue);
            break;
        case 3:
            peek(&myQueue);
            break;
        case 4:
            empty = isEmpty(&myQueue);
            if (empty)
            {
                printf("Queue is Empty \n");
            }
            else
            {
                printf("Queue is not Empty \n");
            }
            break;
        case 5:
            findSize(&myQueue);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Enter a valid choice\n");
            break;
        }
    } while (choice != 0);

    return 0;
}

