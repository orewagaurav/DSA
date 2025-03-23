#include <stdio.h>
#define MAX 5

void initGraph(int matrix[MAX][MAX], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            matrix[i][j] = 0;
        }
    }
}

void addEdge(int matrix[MAX][MAX], int src, int dst) {
    matrix[src][dst] = 1;
    matrix[dst][src] = 1; 
}

void display(int matrix[MAX][MAX], int vertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX][MAX];
    int vertices = 5;
    
    initGraph(matrix, vertices);
    addEdge(matrix, 0, 1);
    addEdge(matrix, 0, 4);
    addEdge(matrix, 1, 2);
    addEdge(matrix, 1, 3);
    addEdge(matrix, 1, 4);
    addEdge(matrix, 2, 3);
    addEdge(matrix, 3, 4);
    
    display(matrix, vertices);
    return 0;
}