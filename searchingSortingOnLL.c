#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *printLL(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
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
struct Node *createLL(struct Node *head)
{
    int data;
    printf("Enter value\n");
    scanf("%d", &data);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
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
    if (left->data < right->data)
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
        if (left->data < right->data)
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

int findTemperature(struct Node *head, int temperature)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return -1;
    }
    struct Node *temp = head;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->data == temperature)
        {
            return position;
            break;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

int main()
{
    struct Node *head = NULL;
    int number;
    printf("Enter number of records want to insert\n");
    scanf("%d", &number);
    for (int index = 0; index < number; index++)
    {
        head = createLL(head);
    }
    printf("Temperature Values Before sorting\n");
    head = printLL(head);
    head = mergeSort(head);
    printf("\nTemperature Values After sorting\n");
    head = printLL(head);

    int temperature;
    printf("\nEnter Temperature you want to search\n");
    scanf("%d", &temperature);
    int isPresent = findTemperature(head, temperature);
    if (isPresent != -1)
    {
        printf("Temperature %d degree celsius present at %d position \n", temperature, isPresent);
    }
    else
    {
        printf("Temperature %d degree celsius not present \n", temperature);
    }
    return 0;
}

