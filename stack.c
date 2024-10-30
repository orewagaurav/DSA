#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push(int value){
    if(top==MAX-1){
        printf("Overflow");
    }
    else{
        top++;
        stack[top]=value;
    }

}
void pop(){
    if(top==-1)
    printf("UNDERFLOW");
    else{
    top--;
    }
}
void isEmpty(){
    if(top==-1){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}
void isFull(){
    if(top==MAX-1){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}
void display(){
    if(top==-1){
        printf("NO Elements");
    }
    else{
        printf("\nThe elements in stack are: ");
            for(int i=top;i>=0;i--){
                printf("%d ",stack[i]);
            }
        printf("\n");
    }
}
int main(){
    while(1){
        int n;
        printf("\n1-push\n2-pop\n3-display\n4-Exit\n5-isEmpty\n6-isFull\n\n");
        printf("Enter your choice: ");
        scanf("%d",&n);
        if(n==1){
            printf("Enter the element: ");
            for(int i=0;;i++){
                int value;
                scanf("%d",&value);
                char ch = getchar();
                push(value);
                if(ch=='\n')
                break; 
            }
        }
        else if(n==2){
            pop();
        }
        else if(n==3){
            display();
        }
        else if(n==4){
        break;
        }
        else if(n==5){
            isEmpty();
        }
        else if(n==6){
            isFull();
        }
        else{
            printf("Enter the correct choice: ");
        }
    }  
}