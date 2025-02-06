#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 20

typedef enum {
    A,
    B,
    C,
    D,
    F
} grades;

struct Node {
    char name[MAX_LEN];
    grades grade;
    struct Node *next;
};

struct Node *printList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node *temp = head;
        while (temp != NULL) {
            printf("Name: %s Grade: ", temp->name);
            switch (temp->grade) {
                case A: printf("A\n"); break;
                case B: printf("B\n"); break;
                case C: printf("C\n"); break;
                case D: printf("D\n"); break;
                case F: printf("F\n"); break; 
            }
            temp = temp->next;
        }
    }
    return head;
}

struct Node *createList(struct Node *head) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter name: ");
    scanf("%s", newNode->name); 
    getchar();
    char gr;
    printf("Enter grade: ");
    scanf("%c", &gr);

    grades g;
    switch (gr) {
        case 'A': g = A; break;
        case 'B': g = B; break;
        case 'C': g = C; break;
        case 'D': g = D; break;
        case 'F': g = F; break;
        default:
        printf("Invalid grade. \n");
        break;
    }

    newNode->grade = g;
    newNode->next = NULL;  

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

struct Node *sortStudent(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    struct Node *ptr1=NULL;
    struct Node *ptr;
    int flag;

    do{
        flag=0;
        ptr=head;
        while(ptr->next!=ptr1){
            if(ptr->grade>ptr->next->grade){
                 int temp=ptr->grade;
                 ptr->grade=ptr->next->grade;
                 ptr->next->grade=temp;

                 char tempname[MAX_LEN];
                 strcpy(tempname,ptr->name);
                 strcpy(ptr->name,ptr->next->name);
                 strcpy(ptr->next->name,tempname);
                 flag=1;
            }
            ptr=ptr->next;
        }
        ptr1=ptr;
    }while(flag);

    return head;
}

int main() {
    struct Node *head = NULL;
    int number;

    printf("Enter number of nodes: ");
    scanf("%d", &number);
    getchar(); 

    for (int i = 0; i < number; i++) {
        head = createList(head);
    }

    printf("\nOriginal List:\n");
    printList(head);

    printf("\nSorted List:\n");
    head = sortStudent(head);
    printList(head);

    return 0;
}

