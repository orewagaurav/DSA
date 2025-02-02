// #include <stdio.h>
// #include <stdlib.h>

// // Define the structure for a node in the binary tree
// struct Node {
//     int data;
//     struct Node* left;
//     struct Node* right;
// };

// // Function to create a new node
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
    
// }

// // Function to insert a node in the binary tree
// struct Node* insertNode(struct Node* root, int data) {
//     if (root == NULL) {
//         return createNode(data);
//     }
//     if (data < root->data) {
//         root->left = insertNode(root->left, data);
//     } else {
//         root->right = insertNode(root->right, data);
//     }
//     return root;
// }

// // Function to perform inorder traversal of the binary tree
// void inorderTraversal(struct Node* root) {
//     if (root != NULL) {
//         inorderTraversal(root->left);
//         printf("%d ", root->data);
//         inorderTraversal(root->right);
//     }
// }

// // Main function to test the binary tree implementation
// int main() {
//     struct Node* root = NULL;
//     root = insertNode(root, 50);
//     insertNode(root, 30);
//     insertNode(root, 70);
//     insertNode(root, 20);
//     insertNode(root, 40);
//     insertNode(root, 60);
//     insertNode(root, 80);

//     printf("Inorder traversal of the binary tree: ");
//     inorderTraversal(root);
//     printf("\n");

//     return 0;
// }

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