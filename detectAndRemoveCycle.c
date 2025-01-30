#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printLL(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *createLL(struct Node *head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    int data;
    printf("Enter value: ");
    scanf("%d", &data);

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

struct Node *detectLoop(struct Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return slow;
        }
    }

    return NULL;
}

struct Node *getStartingNode(struct Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct Node *intersection = detectLoop(head);

    if (intersection == NULL)
    {
        return NULL;
    }
    struct Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

struct Node *removeCycle(struct Node *head)
{
    struct Node *intersection = getStartingNode(head);

    if (intersection == NULL)
    {
        return head;
    }
    struct Node *temp = intersection;

    while (temp->next != intersection)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

int main()
{
    struct Node *head = NULL;
    int number;
    printf("Enter number of nodes you want to insert: ");
    scanf("%d", &number);

    for (int index = 0; index < number; index++)
    {
        head = createLL(head);
    }
    printLL(head);
    if (number > 1)
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head->next;
    }

    if (detectLoop(head) != NULL)
    {
        printf("\nCycle is present\n");

        head = removeCycle(head);

        printf("After removal updated linked list:\n");
        printLL(head);

        if (detectLoop(head) != NULL)
        {
            printf("\nCycle is still present\n");
        }
        else
        {
            printf("\nCycle is not present\n");
        }
    }
    else
    {
        printf("\nCycle is not present\n");
    }

    return 0;
}

