#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data){
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void preOrder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
//       5
//     /  \
//     3   6
//    / \  
//   1  4

int main(){
    struct node *p1,*p2,*p3;
    p1 = createNode(3);
    p2=createNode(4);
    p3=createNode(7);
    
    p1->left=p3;
    p1->right=p2;
    printf("Hello world\n");
    
    preOrder(p1);
}