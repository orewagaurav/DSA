#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int arr[MAX];
int front = -1;
int rear =-1;

void enQueue(int value){
    if((rear+1)%MAX==front){
        printf("Queue is full");
        return;
    }
    if(front ==-1)front++;
    rear = (rear+1)%MAX;
    arr[rear]=value;
    
}
void deQueue(){
    if(front==-1){
        printf("Queue is empty");
        return;
    }
    if(front ==rear)front=rear=-1;
    else{
        front = (front+1)%MAX;
    }
}
void display(){
    for(int i=front;;i=(i+1)%MAX){
        if(i!=rear)
        printf("%d*",arr[i]);
        if(i==rear){
            printf("%d\n",arr[i]);
            break;
        }
        
    }
}

int main(){
    int n,task,value;
    printf("Enter the no. of operations: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&task);
        if(task==1){
            scanf("%d",&value);
            enQueue(value); 
        }
        else if(task ==2)
        deQueue();
        
    }
    display();
}
// 6	
// 1 2	
// 1 3	
// 1 4	
// 2	
// 2	
// 1 5	
// 4·5	
// Test case 2
// 3	
// 1 11	
// 2	
// 2	
// Empty