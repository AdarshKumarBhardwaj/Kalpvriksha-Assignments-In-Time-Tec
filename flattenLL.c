#include <stdio.h>
#include<stdlib.h>
 
struct node 
{
    int data;
    struct node *next;
    struct node *child;
};
 
struct node * flatten(struct node *head){
    if(!head) return NULL;
    if(!head->child) {
        if(head->next) flatten(head->next);  
        return head;
    }
    struct node * nextNode = head->next; 
    struct node *childNode = flatten(head->child);  
    head->next = childNode;
    while(childNode && childNode->next){
        childNode = childNode->next;
    }
    childNode->next = nextNode;
    flatten(nextNode);
    return head;
}
 
void print(struct node * head){
    if(!head) return ;
    
    printf("%d\n",head->data);
    printf("child of %d:",head->data);
    if(head->child){
        printf("%d\n",head->child->data);
    }
    else printf("\n");
    printf("next of %d:",head->data);
    if(head->next){
        printf("%d\n",head->next->data);
    }
    else printf("\n");
    print(head->child);
    print(head->next);
}
 
void printnormi(struct node * head){
    struct node *temp = head;
    while(temp){
        printf("%d",temp->data);
        temp = temp->next;
    }
}
 
 
void createLinkedList(struct node *head,int n, int num){
    if(num == n) return ;
    printf("enter child of %d\n",head->data);
    struct node *temp1 = malloc(sizeof(struct node));
     int data1;
    scanf("%d",&data1);
    if(data1 != -1)
    {
    temp1->data = data1;
    head->child = temp1;
    num++;
    }else
    {
        head->child = NULL;
    }
    printf("enter next of %d\n",head->data);
    struct node *temp = malloc(sizeof(struct node));
 
    int data;
    scanf("%d",&data);
    if(data != -1){
    temp->data = data;
    head->next = temp;
    num++;
    }else{
        head->next = NULL;
    }
    if(head->child)
    createLinkedList(head->child,n,num);
    if(head->next)
    createLinkedList(head->next,n,num);

}
 
int main() {
    printf("Enter the number of nodes\n");
    int num;
    scanf("%d",&num);
    struct node *head = malloc(sizeof(struct node));
    printf("Enter the head node:\n");
    scanf("%d",&head->data);
    createLinkedList(head,num,0);
    print(head);
    flatten(head);
    printnormi(head);
    return 0;
}

