
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int data){
    struct node* ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

int main(){
    int p1,p2,p3;
    printf("Enter the p1 value: ");
    scanf("%d",&p1);
    struct node* n1=createNode(p1);
    printf("Enter the p2 value: ");
    scanf("%d",&p2);
    struct node* n2=createNode(p2);
    printf("Enter the p3 value: ");
    scanf("%d",&p3);
    struct node* n3=createNode(p3);
    n1->left=n2;
    n1->right=n3;

    return 0;
}