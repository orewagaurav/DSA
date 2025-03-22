#include <stdio.h>
#define max 5

void dfs(int graph[max][max],int start,int visited[]){
    visited[start]=1;
    printf("%d ",start);
    for(int i=0;i<max;i++){
        if(graph[start][i]==1 && visited[i]==0){
            visited[i]=1;
            dfs(graph,i,visited);
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

    printf("DFS of the graph : ");
    dfs(graph,0,visited);
}