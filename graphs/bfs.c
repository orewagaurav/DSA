#include <stdio.h>
#define max 10

int queue[max];
int front= -1;
int rear= -1;

void enqueue(int value){
    if(rear==max-1){
        printf("Overflow");
    }
    if(front==-1)
        front++;
    rear++;
    queue[rear]=value;
}