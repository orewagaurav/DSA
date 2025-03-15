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
void inOrder(struct node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
int isBst(struct node *root){
    static struct node *prev;
    if(root!=NULL){
        if(!isBst(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev=root;
        return isBst(root->right);

    }
    else{
        return 1;
    }
}

struct node* bstSearchItr(struct node *root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}


void insert(struct node *root,int key){
    struct node *prev =NULL;
    while(root!=NULL){
        prev=root;
        if(root->data==key){
            printf("Key allready exists so can't be inserted.\n");
            return;
        }
        else if(root->data>key){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node *new =createNode(key);
    if(key<prev->data){
        prev->left=new;
    }
    else{
        prev->right=new;
    }
}

int main(){
    int key2;
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
    
    printf("\nBefore Insertion: \n");
    printf("  Inorder: ");
    inOrder(p1);
    printf("\n");
    if(isBst(p1)){
        printf("  Yes,It's a BST !\n");
    }
    else
    printf("  No,It's not a BST !\n");
    struct node *tmp;
    int key;
    printf("  Enter the element to search: ");
    scanf("%d",&key);
    tmp=bstSearchItr(p1,key);
    
    if(tmp!=NULL){
        printf("  Fond %d in this BST\n",tmp->data);
    }
    else{
        printf("  Element not found !\n");
    }

    printf("\nEnter the key to insert: ");
    scanf("%d",&key2);
    insert(p1,key2);
    printf("\nAfter Insertion: \n");
    printf("  Inorder: ");
    inOrder(p1);
    printf("\n");
    if(isBst(p1)){
        printf("  Yes,It's a BST !\n");
    }
    else
    printf("  No,It's not a BST !\n");
    printf("  Enter the element to search: ");
    scanf("%d",&key);
    tmp=bstSearchItr(p1,key);
    
    if(tmp!=NULL){
        printf("  Fond %d in this BST\n",tmp->data);
    }
    else{
        printf("  Element not found !\n");
    }
}