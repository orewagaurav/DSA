#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;

};
struct node *create(){
    struct node * new;
    int data;
    new =(struct node *)malloc(sizeof(struct node));
    printf("Enter data(-1 for no node): ");
    scanf("%d",&data);
    if(data==-1){
        return 0;
    }
    new->data=data;
    printf("left child of %d: ",data);
    new->left=create();
    printf("right child of %d: ",data);
    new->right=create();
    return new;
}
int height(struct node *root){
    if(root==NULL){
        return 0;
    }
    int leftH=height(root->left);
    int rightH=height(root->right);

    if(leftH == -1 || rightH==-1){
        return -1;
    }
    if(abs(leftH-rightH)>1){
        return -1;
    }
    return (leftH>rightH ? leftH:rightH)+1;
}
void isBalanced(struct node *root){
    if(height(root)==-1){
        printf("Tree is not balanced");
    }
    else{
        printf("Tree is balanced");
    }
}
int main(){
    struct node *tmp;
    tmp=create();
    isBalanced(tmp); 
}