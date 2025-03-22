#include <stdio.h>
#define max 5

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

int dequeue(){
    if(front==-1 || front>rear){
        printf("underflow");
        return -1;
    }
    int value = queue[front];
    front++;
    return value;
}

void bfs(int graph[max][max],int start,int visited[]){
    visited[start]=1;
    enqueue(start);

    while(front<=rear){
        int current = dequeue();
        printf("%d ",current);

        for(int i=0;i<max;i++){
            if(graph[current][i]==1 && visited[i]==0){
                visited[i]=1;
                enqueue(i);
            }
        }
    }
}

int main(){
    int graph[max][max]={
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0}
    };
    int visited[max]={0};
    printf("The BFS of the Graph starting from node 0: ");
    bfs(graph,0,visited);
}