#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int stack[MAX];
int top = -1;
void push(int value){
    if(top==MAX-1){
        printf("Overflow");
    }
    top++;
    stack[top]=value;

}
void pop(){
    if(top==-1)
    printf("Underflow");
    top--;
}
void display(){
    printf("\nThe elements in stack are: ");
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main(){
    printf("Enter the element: ");
    for(int i=0;;i++){
        int value;
        scanf("%d",&value);
        char ch = getchar();
        push(value);
        if(ch=='\n')
        break; 
    }
    display();
        

}