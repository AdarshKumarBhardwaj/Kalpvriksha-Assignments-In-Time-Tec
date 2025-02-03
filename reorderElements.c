#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *createLinkedList()
{
    struct Node *head = NULL, *temp = NULL;
    int number, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &number);

    for (int index = 0; index < number; index++)
    {
        printf("Enter value for node %d: ", index + 1);
        scanf("%d", &value);

        struct Node *newNode = createNode(value);
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    return head;
}

struct Node *findMiddle(struct Node *head)
{
    struct Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL, *curr = head, *nextNode = NULL;
    while (curr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

struct Node *reorderList(struct Node *head)
{
    if (!head || !head->next)
        return head;

    struct Node *middle = findMiddle(head);
    struct Node *secondHalf = middle->next;
    middle->next = NULL;

    secondHalf = reverseList(secondHalf);

    struct Node *firstHalf = head, *temp1, *temp2;
    while (secondHalf)
    {
        temp1 = firstHalf->next;
        temp2 = secondHalf->next;

        firstHalf->next = secondHalf;
        secondHalf->next = temp1;

        firstHalf = temp1;
        secondHalf = temp2;
    }

    return head;
}

struct Node *printList(struct Node *head)
{
    struct Node *temp = head;
    if (!head)
    {
        printf("The list is empty.\n");
        return head;
    }

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return head;
}

int main()
{
    struct Node *head = createLinkedList();

    printf("Original List:\n");
    printList(head);

    head = reorderList(head);

    printf("Reordered List:\n");
    printList(head);

    return 0;
}

