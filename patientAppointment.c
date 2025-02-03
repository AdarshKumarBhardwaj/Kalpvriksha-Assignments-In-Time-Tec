#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define situationSize 20

struct Node
{
    char situation[situationSize];
    int id;
    struct Node *next;
};

struct Node *printLinkedList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d %s ", temp->id, temp->situation);
        printf("\n");
        temp = temp->next;
    }
    return head;
}

struct Node *createLinkedList(struct Node *head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    int data;
    char situation[situationSize];
    printf("Enter Id and situation\n");
    scanf("%d %s", &data, situation);

    newNode->id = data;
    strcpy(newNode->situation, situation);
    newNode->next = NULL;

    struct Node *temp;
    if (head == NULL)
    {
        head = temp = newNode;
    }
    else
    {
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

struct Node *findMid(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node *merge(struct Node *left, struct Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    struct Node *mergedHead = NULL;
    if (strcmp(left->situation, right->situation) <= 0)
    {
        mergedHead = left;
        left = left->next;
    }
    else
    {
        mergedHead = right;
        right = right->next;
    }

    struct Node *current = mergedHead;
    while (left != NULL && right != NULL)
    {
        if (strcmp(left->situation, right->situation) <= 0)
        {
            current->next = left;
            left = left->next;
        }
        else
        {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    while (left != NULL)
    {
        current->next = left;
        left = left->next;
        current = current->next;
    }
    while (right != NULL)
    {
        current->next = right;
        right = right->next;
        current = current->next;
    }
    return mergedHead;
}

struct Node *mergeSort(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct Node *mid = findMid(head);
    struct Node *left = head;
    struct Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);
    struct Node *result = merge(left, right);
    return result;
}

int main()
{
    struct Node *head = NULL;
    int number;
    printf("Enter number of record want to insert\n");
    scanf("%d", &number);
    for (int index = 0; index < number; index++)
    {
        head = createLinkedList(head);
    }
    head = printLinkedList(head);
    printf("\n");
    head = mergeSort(head);
    head = printLinkedList(head);
    return 0;
}

