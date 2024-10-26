#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

void create(struct  node **head,int value){
    struct node *ptr=malloc(sizeof(struct node));
    ptr->next=NULL;
    ptr->data=value;
    struct node *tmp;
    if(*head==NULL)
    *head=ptr;
    else{
        tmp = *head;
        while(tmp->next!=NULL){
        tmp= tmp->next;
        }
        tmp->next=ptr;
    }
    
}
void display(struct node *head){
    struct node *tmp = head;
    while(tmp!=NULL){
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
int main(){
    struct node *head1 =NULL;
    struct node *head2 =NULL;
    int n1,n2,value;
    printf("Enter the no. of elements in head1: ");
    scanf("%d",&n1);
    printf("Enter the elements: ");
    for(int i=0;i<n1;i++){
        scanf("%d",&value);
        create(&head1,value);
    }
    printf("Enter tne no. of elements in head2: ");
    scanf("%d",&n2);
    for(int i =0;i<n2;i++){
        scanf("%d",&value);
        create(&head2,value);
    }
    display(head1);
    display(head2);
}

