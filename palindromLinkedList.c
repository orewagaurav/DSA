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
    int n,m,value;
    printf("Enter the no. of linked list: ");
    scanf("%d",&n);
    struct node **head=(struct node**)malloc(n*sizeof(struct node*));
    for(int i=0;i<n;i++){
        head[i]=NULL;
    }
    for(int i=0;i<n;i++){
        printf("Enter the elements of linkedList %d: ",i+1);
        for(int j=0;;j++){
            scanf("%d",&value);
            if(value==-1)
            break;
            else
            create(&head[i],value);
        }
    }
    for(int i =0;i<n;i++){
        printf("LinkedList %d: ",i+1);
        display(head[i]);
    }
}
// test case:
// 2	
// 0 2 3 2 5 -1	
// -1	
// false⏎
// 1	
// 9 2 3 3 2 9 -1	
// true