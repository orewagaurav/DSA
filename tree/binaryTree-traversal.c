#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data){
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void preOrder(struct node *root){
    if(root !=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

void inOrder(struct node *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
int main(){
    struct node *root,*p2,*p3,*p4,*p5;
    root=createNode(4);
    p2=createNode(1);
    p3=createNode(6);
    p4 = createNode(5);
    p5 = createNode(2);

    //    4
    //   / \
    //   1  6
    //  / \
    // 5   2

//preorder-4 1 5 2 6
//postorder-5 2 1 6 4
//Inorder-5 1 2 4 6

    root->left=p2;
    root->right=p3;
    p2->left=p4;
    p2->right=p5;

    printf("Preorder: ");
    preOrder(root);
    printf("\n");

    printf("Postorder: ");
    postOrder(root);
    printf("\n");

    printf("Inorder: ");
    inOrder(root);
    printf("\n");

}
