#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *printList(struct Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return head;
}
struct Node *createList(struct Node *head)
{
    int value;
    printf("Enter value\n");
    scanf("%d", &value);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    struct Node *temp;
    if (head == NULL)
    {
        temp = head = newNode;
    }
    else
    {
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

struct Node *findKthNode(struct Node *head, int k)
{
    k--;
    struct Node *temp = head;
    while (k > 0 && temp != NULL)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}

struct Node *reverse(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node *reverseKgroups(struct Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct Node *temp = head;
    struct Node *prevHead = NULL;

    while (temp != NULL)
    {
        struct Node *kthNode = findKthNode(temp, k);
        if (!kthNode)
        {
            if (prevHead)
            {
                prevHead->next = temp;
            }
            break;
        }
        struct Node *nextNode = kthNode->next;
        kthNode->next = NULL;
        struct Node *reverseNode = reverse(temp);

        if (temp == head)
        {
            head = kthNode;
        }
        else
        {
            prevHead->next = kthNode;
        }
        prevHead = temp;
        temp = nextNode;
    }
    return head;
}
int main()
{
    struct Node *head = NULL;
    int number;
    printf("Enter number of nodes you want to insert\n");
    scanf("%d", &number);

    for (int i = 0; i < number; i++)
    {
        head = createList(head);
    }
    head = printList(head);
    printf("\n");
    int k;
    printf("Enter the value of k\n");
    scanf("%d", &k);
    head = reverseKgroups(head, k);
    head = printList(head);

    return 0;
}

