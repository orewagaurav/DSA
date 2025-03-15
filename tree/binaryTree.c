#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node* createNode(){
    int data;
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the node (-1 for no node): ");
    scanf("%d ",&data);
    if(data==-1){
        return 0;
    }
    new->data=data;
    printf("Left child of %d",data);
    new->left=createNode();
    printf("Right child of %d",data);
    new->right=createNode();
    return new;
}

void preOrder(struct node *root){
    if(root!=NULL){
        printf("%d",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    struct node *root1;
    root1=createNode();
    printf("\nThe preorder traversal of the tree: \n");
    preOrder(root1);
    printf("\n");
}