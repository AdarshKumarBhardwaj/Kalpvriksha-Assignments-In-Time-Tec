#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *child;
};

struct node *flatten(struct node *head)
{
    if (!head)
    {
        return NULL;
    }

    if (!head->child)
    {
        if (head->next)
            flatten(head->next);
        return head;
    }
    struct node *nextNode = head->next;
    struct node *childNode = flatten(head->child);
    head->next = childNode;

    while (childNode && childNode->next)
    {
        childNode = childNode->next;
    }
    childNode->next = nextNode;
    flatten(nextNode);
    return head;
}

void print(struct node *head)
{
    if (!head)
        return;

    printf("%d\n", head->data);
    printf("child of %d:", head->data);
    if (head->child)
    {
        printf("%d\n", head->child->data);
    }
    else
    {
        printf("\n");
    }
    printf("next of %d:", head->data);
    if (head->next)
    {
        printf("%d\n", head->next->data);
    }
    else
    {
        printf("\n");
    }
    print(head->child);
    print(head->next);
}

void printFlattenLL(struct node *head)
{
    struct node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void createLinkedList(struct node *head, int numberOfNodes, int count)
{
    if (count == numberOfNodes)
        return;
    if (count == 0)
    {
        printf("Enter the head node:\n");
        scanf("%d", &head->data);
    }
    printf("Enter child of %d\n", head->data);
    struct node *newChildNode = malloc(sizeof(struct node));
    int data1;
    scanf("%d", &data1);
    if (data1 != -1)
    {
        newChildNode->data = data1;
        head->child = newChildNode;
        count++;
    }
    else
    {
        head->child = NULL;
    }
    printf("Enter next of %d\n", head->data);
    struct node *newNextNode = malloc(sizeof(struct node));

    int data;
    scanf("%d", &data);
    if (data != -1)
    {
        newNextNode->data = data;
        head->next = newNextNode;
        count++;
    }
    else
    {
        head->next = NULL;
    }
    if (head->child)
        createLinkedList(head->child, numberOfNodes, count);
    if (head->next)
        createLinkedList(head->next, numberOfNodes, count);
}

int main()
{
    int numberOfNodes;
    printf("Enter the number of nodes\n");
    scanf("%d", &numberOfNodes);

    struct node *head = malloc(sizeof(struct node));
    createLinkedList(head, numberOfNodes, 0);

    printf("\nOriginal Multi-Level Linked List:\n");
    print(head);

    flatten(head);

    printf("\nFlattened Linked List:\n");
    printFlattenLL(head);

    return 0;
}

