#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int height(struct TreeNode* root){
    int leftH,rightH;
    if(root==NULL)
        return 0;
    leftH=height(root->left);
    rightH=height(root->right);
    if(leftH>rightH)
        return leftH+1;
    else
        return rightH+1;
}


// Driver Code
int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Height of the tree: %d\n", height(root)); // Output: 2 (if height in edges)
    return 0;
}