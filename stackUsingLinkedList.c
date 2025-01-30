#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    int data;
    printf("Enter value\n");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        printf("stack underflow\n");
    }
    else
    {
        struct Node *temp = top;
        printf("popped element is %d ", top->data);
        top = top->next;
        free(temp);
    }
    printf("\n");
}

void peek()
{
    if (top == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("top element is %d ", top->data);
    }
    printf("\n");
}

void findSize()
{
    if (top == NULL)
    {
        printf("size of stack is 0\n");
    }
    else
    {
        struct Node *temp = top;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        printf("size of stack is %d ", count);
    }
    printf("\n");
}

bool isEmpty()
{
    if (top == NULL)
    {
        return true;
    }

    return false;
}

int main()
{
    int choice;
    bool empty;
    printf("1. push element in stack\n");
    printf("2. pop an element from stack\n");
    printf("3. find top element of stack\n");
    printf("4. check stack is empty or not\n");
    printf("5. find size of stack\n");
    printf("for exit enter 0\n");
    do
    {

        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            empty = isEmpty();
            if (empty)
            {
                printf("Stack is Empty\n");
            }
            else
            {
                printf("Stack is not Empty\n");
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