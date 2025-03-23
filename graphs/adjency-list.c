#include <stdio.h>
#include <stdlib.h>
#define max 5

struct node {
    int data;
    struct node *next;
};

struct graph{
    int vertices;
    struct node *adj[max];
};

void initgraph(struct graph *g,int vertices){
    g->vertices=vertices;
    for(int i=0;i<vertices;i++){
        g->adj[i]=NULL;
    }
}
void addEdge(struct graph *g,int src,int dst){
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data =dst;
    new->next=g->adj[src];
    g->adj[src]=new;

    new = (struct node*)malloc(sizeof(struct node));
    new->data = src;
    new->next = g->adj[dst];
    g->adj[dst] = new;
}

void display(struct graph *g){
    printf("Adjacency List: \n");
    for(int i=0;i<g->vertices;i++){
        printf("%d: ",i);
        struct node *temp=g->adj[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct graph* g = (struct graph*)malloc(sizeof(struct graph));
    initgraph(g, 5);
    
    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);
    
    display(g);
    
    free(g);
    return 0;
}