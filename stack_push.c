#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int SArr[MAX];
int top = -1;
void push(int value){
    if(top==MAX-1)
    return;
    top++;
    SArr[top]=value;
}

void pop(){
    if(top==-1){
       return;
    }
    top--;
}
void peek(){
    if(top==-1)
    return;
    else 
    printf("%d",SArr[top]);
}

void display(){
    if(top==-1)
    printf("Empty\n");
    for(int i=top;i>=0;i--){
        if(i!=0)
        printf("%d ",SArr[i]);
        else
        printf("%d\n",SArr[i]);
    }
}

int main(){
    int n,task,value;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&task);
        if(task==1){
            scanf("%d",&value);
            push(value);
        }
        else if(task==2)
        pop();
        else if(task==3)
        peek();
    }
    display();
}
