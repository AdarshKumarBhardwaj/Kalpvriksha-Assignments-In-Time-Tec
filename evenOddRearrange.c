#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void printLL(struct Node *head) {
    if (head == NULL) {
        printf("List is Empty\n");
    } else {
        struct Node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

struct Node* createLL(struct Node *head) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    int data;
    printf("Enter value: ");
    scanf("%d", &data);
    
    newNode->data = data;
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

struct Node* rearrangeLL(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;  
    }
    struct Node *evenHead = NULL, *oddHead = NULL;
    struct Node *evenTail = NULL, *oddTail = NULL;
    
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->data % 2 == 0) { 
            if (evenHead == NULL) {
                evenHead = evenTail = temp; 
            } else {
                evenTail->next = temp; 
                evenTail = evenTail->next; 
            }
        } else { 
            if (oddHead == NULL) {
                oddHead = oddTail = temp; 
            } else {
                oddTail->next = temp; 
                oddTail = oddTail->next; 
            }
        }
        temp = temp->next;
    }
    if (evenTail != NULL) {
        evenTail->next = oddHead; 
    }
    
    if (oddTail != NULL) {
        oddTail->next = NULL; 
    }
    if(evenHead){
        return evenHead;
    }else{
        return oddHead;
    }
}

int main() {
    struct Node *head = NULL;
    int number;

    printf("Enter number of nodes you want to insert: ");
    scanf("%d", &number);
    
    for (int index = 0; index < number; index++) {
        head = createLL(head);
    }

    printf("Original List: ");
    printLL(head);

    head = rearrangeLL(head);
    
    printf("Rearranged List: ");
    printLL(head);

    return 0;
}

