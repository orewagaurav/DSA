#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*top = NULL;

void push(int value){
    struct node *ptr;
    ptr = malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = top;
    top=ptr;
}
void pop(){
    struct node *tmp;
    if(top==NULL)
    printf("UNDERFLOW");
    else{
        tmp=top;
        top = top->next;
        free(tmp);
    }
}
void display(){
    struct node* tmp;
    if(top==NULL)
    printf("stack is empty\n");
    tmp=top;
    while(tmp!=NULL){
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
int main(){
    int n,value,task;
    printf("Enter the no. operations: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&task);
        if(task==1){
            scanf("%d",&value);
            push(value);
        }
        else if(task==2){
            pop();
        }
    }
    display();
}