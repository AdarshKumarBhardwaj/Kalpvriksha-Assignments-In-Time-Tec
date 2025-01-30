#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue()
{
    int data;
    printf("Enter value\n");
    scanf("%d", &data);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        struct Node *temp = front;
        printf("Dequeued element of queue is %d ", temp->data);
        front = front->next;
        free(temp);
    }
    printf("\n");
}

void peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element of queue is %d ", front->data);
    }
    printf("\n");
}

bool isEmpty()
{
    if (front == NULL && rear == NULL)
    {
        return true;
    }
    return false;
}

void findSize()
{
    if (front == NULL && rear == NULL)
    {
        printf("Size of queue is 0 \n");
    }
    else
    {
        struct Node *temp = front;
        int count = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        printf("Size of queue is %d ", count);
    }
    printf("\n");
}

int main()
{
    int choice;
    bool empty;
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
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            empty = isEmpty();
            if (empty)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;
        case 5:
            findSize();
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