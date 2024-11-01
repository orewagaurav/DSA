#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int arr[MAX];
int backInd = -1;
int frontInd = -1;

bool isEmpty(){
    if(backInd!=MAX-1)
    return true;
    else
    return false;
}
void enQueue(int value){
    bool check = isEmpty();
    if(check==true){
        backInd++;
        arr[backInd]=value;
    }
    else
    printf("Queue is Full!\n");
}
void deQueue(){
    if(backInd!=frontInd){
        frontInd++;
    }
    else
    printf("stack is Empty!\n");
}
void display(){
    for(int i = frontInd+1;i<=backInd;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int n,value;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        enQueue(value);
    }
    deQueue();
    display();
}
