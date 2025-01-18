#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int findLength(struct Node *head)
{
    struct Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void displayNode(struct Node *head)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Linked List is Empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

struct Node *insertNodeAtBegin(struct Node *head)
{
    int data;
    printf("Enter the value for insertion at the beginning\n");
    scanf("%d", &data);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Linked List after insertion at Beginning\n");
    displayNode(head);
    return head;
}

struct Node *insertNodeAtLast(struct Node *head)
{
    int data;
    printf("Enter the value for insertion at the end\n");
    scanf("%d", &data);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
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
    printf("Linked List after insertion at last\n");
    displayNode(head);
    return head;
}

struct Node *insertNodeAtPosition(struct Node *head)
{
    int data, position;
    printf("Enter the value for insertion at position\n");
    scanf("%d", &data);
    printf("Enter the position for insertion\n");
    scanf("%d", &position);
    int length = findLength(head);

    if (position < 1 || position > length + 1)
    {
        printf("Enter a valid position\n");
        return head;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Linked List after insertion at %d position \n", position);
        displayNode(head);
    }
    return head;
}

struct Node *deleteNodeAtBegin(struct Node *head)
{
    if (head == NULL)
    {
        printf("No Node to delete, Linked list is empty\n");
    }
    else
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    printf("Linked List after deletion of starting node\n");
    displayNode(head);
    return head;
}

struct Node *deleteNodeAtLast(struct Node *head)
{
    if (head == NULL)
    {
        printf("No Node to delete, Linked list is empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *prevNode = NULL;
        struct Node *currNode = head;
        while (currNode->next != NULL)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        prevNode->next = NULL;
        free(currNode);
    }
    printf("Linked List after deletion of ending node\n");
    displayNode(head);
    return head;
}

struct Node *deleteNodeAtPosition(struct Node *head)
{
    int position;
    int length = findLength(head);
    printf("Enter the position of node to delete\n");
    scanf("%d", &position);
    if (position < 1 || position > length)
    {
        printf("Enter a valid position\n");
        return head;
    }
    if (position == 1)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        int index = 1;
        struct Node *temp = head;
        while (index < position - 1)
        {
            index++;
            temp = temp->next;
        }
        struct Node *toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
    printf("Linked List after deleting node at %d position\n", position);
    displayNode(head);
    return head;
}

struct Node *updateValueAtBegin(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        int value;
        printf("Enter the value\n");
        scanf("%d", &value);
        head->data = value;
        printf("List after updating value at first position\n");
        displayNode(head);
    }
    return head;
}

struct Node *updateValueAtLast(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        int value;
        printf("Enter the value\n");
        scanf("%d", &value);
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->data = value;
        printf("List after updating value at last position\n");
        displayNode(head);
    }
    return head;
}

struct Node *updateValueAtPosition(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        int position, value;
        printf("Enter the position\n");
        scanf("%d", &position);
        int length = findLength(head);
        if (position < 1 || position > length)
        {
            printf("Enter a valid position\n");
            return head;
        }
        printf("Enter the value\n");
        scanf("%d", &value);
        int index = 1;
        struct Node *temp = head;
        while (index < position)
        {
            index++;
            temp = temp->next;
        }
        temp->data = value;
        printf("List after updating value at %d position\n", position);
        displayNode(head);
    }
    return head;
}

int main()
{
    struct Node *head = NULL;
    int choice;
    do
    {
        printf("1. Insert Node At Start\n");
        printf("2. Insert Node At End\n");
        printf("3. Insert Node At Position\n");
        printf("4. Delete Node At Start\n");
        printf("5. Delete Node At End\n");
        printf("6. Delete Node At Position\n");
        printf("7. Update Node At Start\n");
        printf("8. Update Node At End\n");
        printf("9. Update Node At Position\n");
        printf("10. Display Linked List\n");
        printf("11. Exit\n");
        printf("Enter Choice\n");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input, please enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        switch (choice)
        {
        case 1:
            head = insertNodeAtBegin(head);
            break;
        case 2:
            head = insertNodeAtLast(head);
            break;
        case 3:
            head = insertNodeAtPosition(head);
            break;
        case 4:
            head = deleteNodeAtBegin(head);
            break;
        case 5:
            head = deleteNodeAtLast(head);
            break;
        case 6:
            head = deleteNodeAtPosition(head);
            break;
        case 7:
            head = updateValueAtBegin(head);
            break;
        case 8:
            head = updateValueAtLast(head);
            break;
        case 9:
            head = updateValueAtPosition(head);
            break;
        case 10:
            displayNode(head);
            break;
        case 11:
            printf("Exiting from program\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
            break;
        }
    } while (choice != 11);

    return 0;
}

