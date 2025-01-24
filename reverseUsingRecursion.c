#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *printLL(struct Node *head){
    if(head==NULL){
        printf("Linked list is empty\n");
        return NULL;
    }
        struct Node *temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    return head;
}

struct Node *createLL(struct Node *head){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    int data;
    printf("Enter value ");
    scanf("%d",&data);
    newNode->data=data;
    newNode->next=NULL;
    struct Node *temp;
    if(head==NULL){
        head=temp=newNode;
    }else{
        temp->next=newNode;
        temp=newNode;
    }
    return head;
}

struct Node *reverseLinkedList(struct Node *head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    struct Node* newHead = reverseLinkedList(head->next);
    struct Node* front=head->next;
    front->next=head;
    head->next = NULL;
    return newHead;
}

int main() {
  struct Node *head=NULL;
  int number;
  printf("Enter number of nodes for insertion\n");
  scanf("%d",&number);
  for(int index=0;index<number;index++){
      head=createLL(head);
  }
  
   head=printLL(head);
   printf("\n");
   printf("Reversed linked list is\n");
   head=reverseLinkedList(head);
   head=printLL(head);
   
    return 0;
}

