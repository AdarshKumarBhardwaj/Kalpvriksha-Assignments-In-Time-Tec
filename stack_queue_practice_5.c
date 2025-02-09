// Problem Satement:Browser History Management Using Stack
// Design and implement a browser history management system using the stack data structure in C.
// This system should simulate the behavior of storing and managing visited websites.
// Write a C program with options that let users interactively choose and perform operations mentioned in below tasks section.:

// Tasks:
// Implement the functions to perform the following operations on a stack:
// Add a Website (Push): Allow the user to add a new URL to the history.
// View History (Read): Display the list of all visited websites in reverse order of visits (most recent first).
// Edit a URL (Update): Provide an option to modify a specific URL in the history.
// Remove Recent Website (Pop): Delete the most recently visited website from history.
// Include additional functions for features such as:
// A Clear History option to delete all stored URLs.
// A Peek Function to view the most recently visited website without removing it.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 50

typedef struct
{
    char stack[SIZE][SIZE];
    int top;
} url;

void push(url *urlPointer)
{
    char URL[100];
    printf("Enter url to push\n");
    scanf("%s", URL);
    if (urlPointer->top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    urlPointer->top++;
    strcpy(urlPointer->stack[urlPointer->top], URL);
}

void pop(url *urlPointer)
{
    if (urlPointer->top == -1)
    {
        printf("Underfow\n");
    }
    char result[100];
    strcpy(result, urlPointer->stack[urlPointer->top--]);
    printf("Popped URL is %s \n", result);
}

void display(url *urlPointer)
{
    if (urlPointer->top == -1)
    {
        printf("List is Empty\n");
    }
    else
    {
        for (int index = urlPointer->top; index >= 0; index--)
        {
            printf("%s \n", urlPointer->stack[index]);
        }
    }
    printf("\n");
}

void updateSpecificUrl(url *urlPointer)
{
    char targetUrl[100];
    char updatedUrl[100];
    int targetIndex;
    bool isFound = false;
    printf("Enter the Url you want to edit\n");
    scanf("%s", targetUrl);
    for (int index = urlPointer->top; index >= 0; index--)
    {
        if (strcmp(targetUrl, urlPointer->stack[index]) == 0)
        {
            isFound = true;
            targetIndex = index;
            break;
        }
    }
    if (isFound)
    {
        printf("Enter the updated URL\n");
        scanf("%s", updatedUrl);
        strcpy(urlPointer->stack[targetIndex], updatedUrl);
    }
    else
    {
        printf("Enterred URL is not Present in stack\n");
    }
}

void deleteAllURL(url *urlPointer)
{
    if (urlPointer->top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        while (urlPointer->top != -1)
        {
            pop(urlPointer);
        }
    }
    printf("\n");
}

void peek(url *urlPointer)
{
    if (urlPointer->top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element is %s ", urlPointer->stack[urlPointer->top]);
    }
    printf("\n");
}

int main()
{
    url myURL;
    myURL.top = -1;
    int choice;
    printf("1. push url in stack\n");
    printf("2. Display all url\n");
    printf("3. update specific url\n");
    printf("4. pop an url\n");
    printf("5. delete all url\n");
    printf("6. display top element\n");
    do
    {
        printf("Enter Your Choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(&myURL);
            break;
        case 2:
            display(&myURL);
            break;
        case 3:
            updateSpecificUrl(&myURL);
            break;
        case 4:
            pop(&myURL);
            break;
        case 5:
            deleteAllURL(&myURL);
            break;
        case 6:
            peek(&myURL);
            break;
        case 0:
            printf("Existing\n");
            break;
        default:
            printf("Enter Vlaid Choice\n");
            break;
        }
    } while (choice != 0);

    return 0;
}

