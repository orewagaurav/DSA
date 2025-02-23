#include <stdio.h>
#include <stdlib.h>

// Definition of a Tree Node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to calculate the height of a binary tree
int height(struct TreeNode* root) {
    if (root == NULL)
        return -1; // Return 0 if height is measured in nodes instead of edges
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
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