#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void createList(struct Node **head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    int data;
    printf("Enter value: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void reverseLinkedList(struct Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    struct Node *newHead = NULL;
    struct Node *current = *head;
    struct Node *nextNode = NULL;

    while (current != NULL)
    {
        nextNode = current->next;
        current->next = newHead;
        newHead = current;
        current = nextNode;
    }
    *head = newHead;
}

int main()
{
    struct Node *head = NULL;
    int number;
    printf("Enter number of nodes for insertion: ");
    scanf("%d", &number);

    for (int index = 0; index < number; index++)
    {
        createList(&head);
    }

    printf("Original linked list:\n");
    printList(head);

    reverseLinkedList(&head);
    printf("Reversed linked list:\n");
    printList(head);

    return 0;
}

