// Problem Statement:-Printer Job Queue Management Using Queue 
// Simulate a network printer's job queue management system using the queue data structure in C. 
// The system should handle print requests in a First In, First Out (FIFO) manner. 
// Write a C program with options that let users interactively choose and perform printing operations mentioned in below tasks section: 

// Tasks: Implement the functions to perform the following operations on a queue: 
// Add a Print Job (Enqueue): Allow users to add new print jobs, including details like the document name and number of pages. 
// View Pending Jobs (Read): Display all pending print jobs in the order they will be processed. 
// Edit a Job (Update): Provide an option to update the details of a specific print job before it starts printing. 
// Process a Job (Dequeue): Remove the job at the front of the queue after it has been printed. 
// Cancel a Job: Enable users to delete a specific job from the queue. 


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_QUEUE_SIZE 5

typedef struct
{
    char documentName[MAX_NAME_LENGTH];
    int pages;
} PrintJob;

typedef struct
{
    PrintJob jobs[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int jobCounter;
} PrintQueue;

void initializeQueue(PrintQueue *queuePointer)
{
    queuePointer->front = -1;
    queuePointer->rear = -1;
    queuePointer->jobCounter = 1;
}

void customStrcpy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void enqueue(PrintQueue *queuePointer)
{
    char documentName[MAX_NAME_LENGTH];
    int pages;

    printf("Enter document name: ");
    getchar();
    fgets(documentName, MAX_NAME_LENGTH, stdin);
    documentName[strcspn(documentName, "\n")] = 0;

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    if (queuePointer->rear == MAX_QUEUE_SIZE - 1)
    {
        printf("Overflow\n");
        return;
    }
    else if (queuePointer->front == -1 && queuePointer->rear == -1)
    {
        queuePointer->front = 0;
        queuePointer->rear = 0;
        queuePointer->jobs[queuePointer->rear].pages = pages;
        customStrcpy(queuePointer->jobs[queuePointer->rear].documentName, documentName);
    }
    else
    {
        queuePointer->rear++;
        queuePointer->jobs[queuePointer->rear].pages = pages;
        customStrcpy(queuePointer->jobs[queuePointer->rear].documentName, documentName);
    }
}

void dequeue(PrintQueue *queuePointer)
{
    if (queuePointer->front == -1 && queuePointer->rear == -1)
    {
        printf("Underflow\n");
        return;
    }
    char result[MAX_NAME_LENGTH];
    int page = queuePointer->jobs[queuePointer->front].pages;
    customStrcpy(result, queuePointer->jobs[queuePointer->front].documentName);
    printf("Popped job is %s %d \n", result, page);
    if (queuePointer->front == queuePointer->rear)
    {
        queuePointer->front = queuePointer->rear = -1;
    }
    else
    {
        queuePointer->front++;
    }
}

void displayJobs(PrintQueue *queuePointer)
{
    if (queuePointer->front == -1 && queuePointer->rear == -1)
    {
        printf("List is Empty\n");
    }
    else
    {
        int index = queuePointer->front;
        while (index != queuePointer->rear)
        {
            printf("%s %d \n", queuePointer->jobs[index].documentName, queuePointer->jobs[index].pages);
            index++;
        }
        printf("%s %d \n", queuePointer->jobs[queuePointer->rear].documentName, queuePointer->jobs[queuePointer->rear].pages);
    }
    printf("\n");
}

void updateSpecificjob(PrintQueue *queuePointer)
{
    if (queuePointer->front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        char targetjob[MAX_NAME_LENGTH];
        char updatedjob[MAX_NAME_LENGTH];
        int updatedPage;
        int targetIndex;
        bool isFound = false;
        printf("Enter the name of job you want to edit\n");
        getchar();
        fgets(targetjob, MAX_NAME_LENGTH, stdin);
        targetjob[strcspn(targetjob, "\n")] = '\0';

        for (int index = queuePointer->front; index <= (queuePointer->rear); index++)
        {
            if (strcmp(targetjob, queuePointer->jobs[index].documentName) == 0)
            {
                isFound = true;
                targetIndex = index;
                break;
            }
        }
        if (isFound)
        {
            printf("Enter the name of updated job\n");
            fgets(updatedjob, MAX_NAME_LENGTH, stdin);
            updatedjob[strcspn(updatedjob, "\n")] = '\0';

            printf("Enter updated page numbers\n");
            scanf("%d", &updatedPage);
            customStrcpy(queuePointer->jobs[targetIndex].documentName, updatedjob);
            queuePointer->jobs[targetIndex].pages = updatedPage;
        }
        else
        {
            printf("Entered job is not present in queue\n");
        }
    }
}

void deleteSpecificjob(PrintQueue *queuePointer)
{
    if (queuePointer->front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    char targetjob[MAX_NAME_LENGTH];
    printf("Enter the name of the job you want to delete: ");
    getchar();
    fgets(targetjob, MAX_NAME_LENGTH, stdin);
    targetjob[strcspn(targetjob, "\n")] = '\0';
    int targetIndex = -1;
    for (int i = queuePointer->front; i <= queuePointer->rear; i++)
    {
        if (strcmp(targetjob, queuePointer->jobs[i].documentName) == 0)
        {
            targetIndex = i;
            break;
        }
    }

    if (targetIndex == -1)
    {
        printf("Entered job is not present in queue.\n");
        return;
    }

    for (int i = targetIndex; i < queuePointer->rear; i++)
    {
        queuePointer->jobs[i] = queuePointer->jobs[i + 1];
    }

    queuePointer->rear--;

    if (queuePointer->rear < queuePointer->front)
    {
        queuePointer->front = queuePointer->rear = -1;
    }

    printf("Job deleted successfully.\n");

    printf("\n");
}

int main()
{
    PrintQueue myQueue;
    initializeQueue(&myQueue);
    int choice;
    printf("1. Add a Print job\n");
    printf("2. View Pending Jobs \n");
    printf("3. Edit a Job \n");
    printf("4. Remove Front job\n");
    printf("5. Remove Specific job\n");
    do
    {
        printf("Enter Your Choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&myQueue);
            break;
        case 2:
            displayJobs(&myQueue);
            break;
        case 3:
            updateSpecificjob(&myQueue);
            break;
        case 4:
            dequeue(&myQueue);
            break;
        case 5:
            deleteSpecificjob(&myQueue);
            break;
        case 0:
            printf("Exiting\n");
            break;
        default:
            printf("Enter a Valid Choice\n");
            break;
        }
    } while (choice != 0);

    return 0;
}


