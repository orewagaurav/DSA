#include <stdio.h>
#include <stdlib.h>
#define max 10
struct node {
    int vertices;
    int matrix[max][max];
};

void initGraph(struct node *root,int vertices){
    root->vertices=vertices;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            root->matrix[i][j]=0;
        }
    }
}
void addEdge(struct node *root,int src,int dst){
    root->matrix[src][dst]=1;
    root->matrix[dst][src]=1;
}
void display(struct node *root){
    printf("Adjacency matrix");
    for(int i=0;i<root->vertices;i++){
        for(int j=0;j<root->vertices;j++){
            printf("%d ",root->matrix[i][j]);
        }
    }
}
int main(){
    struct node *root = (struct node *)malloc(sizeof(struct node));
    if (root == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    initGraph(root,5);

    addEdge(root,0,1);
    addEdge(root,0,4);
    addEdge(root,1,2);
    addEdge(root,1,3);
    addEdge(root,1,4);
    addEdge(root,2,3);
    addEdge(root,3,4);
    display(root);
}