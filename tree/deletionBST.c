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

int isBST(struct node *root){
     static struct node *prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}


                                                                        /* 
                                                                             5
                                                                            /  \
                                                                            3   6
                                                                           /  \  
                                                                           1   4

                                                                        */

void inOrder(struct node *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}


struct node* inOrderPredecessor(struct node *root){
    root=root->left;
    while(root->right != NULL){
        root=root->right;
    }
    return root;
}

struct node* deleteNode(struct node *root,int value){
    struct node *pre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(value < root->data){
        root->left=deleteNode(root->left,value);
    }
    else if(value >root->data){
        root->right=deleteNode(root->right,value);
    }
    else{
        pre =inOrderPredecessor(root);
        root->data=pre->data;
        deleteNode(root->left,pre->data);
    }
    return root;
}

int main(){
    struct node *p1,*p2,*p3,*p4,*p5;
    p1 = createNode(5);
    p2=createNode(3);
    p3=createNode(6);
    p4=createNode(1);
    p5=createNode(4);

    
    p1->left=p2;
    p1->right=p3;
    p2->left=p4;
    p2->right=p5;

    printf("If the tree is binary search tree then inorder traversal will be sorted\n");
    printf("\n");

    inOrder(p1);

    printf("\n");
    if(isBST(p1)==1){
        printf("Yes,This is BST\n");
    }
    else{
        printf("NO\n");
    }
    deleteNode(p1,10);

    inOrder(p1);
    printf("\n");
    if(isBST(p1)==1){
        printf("Yes,This is BST\n");
    }
    else{
        printf("NO\n");
    }
}