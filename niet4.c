#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

typedef struct QueueNode {
    TreeNode *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

TreeNode* createNode(int value) {
    if (value == -1) return NULL;
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, TreeNode* node) {
    if (!node) return;
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    if (!queue->rear) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

TreeNode* dequeue(Queue* queue) {
    if (!queue->front) return NULL;
    QueueNode* temp = queue->front;
    TreeNode* node = temp->treeNode;
    queue->front = queue->front->next;
    if (!queue->front) queue->rear = NULL;
    free(temp);
    return node;
}

bool isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

TreeNode* insertLevelOrder(TreeNode* root, int value) {
    TreeNode* newNode = createNode(value);
    if (!newNode) return root;
    
    if (!root) return newNode;
    
    Queue* queue = createQueue();
    enqueue(queue, root);
    
    while (!isQueueEmpty(queue)) {
        TreeNode* temp = dequeue(queue);
        if (!temp->left) {
            temp->left = newNode;
            break;
        } else {
            enqueue(queue, temp->left);
        }
        
        if (!temp->right) {
            temp->right = newNode;
            break;
        } else {
            enqueue(queue, temp->right);
        }
    }
    
    free(queue);
    return root;
}

void inOrder(TreeNode* root) {
    if (root) {
        inOrder(root->left);
        printf("%d.", root->value);
        inOrder(root->right);
    }
}

void preOrder(TreeNode* root) {
    if (root) {
        printf("%d.", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(TreeNode* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d.", root->value);
    }
}

bool search(TreeNode* root, int value) {
    if (!root) return false;
    if (root->value == value) return true;
    return search(root->left, value) || search(root->right, value);
}

int main() {
    TreeNode* root = NULL;
    int command, value;
    char output[1000] = "";
    
    while (1) {
        if (scanf("%d", &command) == EOF) break;
        if (command == 1) {
            scanf("%d", &value);
            root = insertLevelOrder(root, value);
        } else if (command == 2) {
            if (!root) printf("-1\n");
            else {
                inOrder(root);
                printf("\n");
            }
        } else if (command == 3) {
            if (!root) printf("-1\n");
            else {
                preOrder(root);
                printf("\n");
            }
        } else if (command == 4) {
            if (!root) printf("-1\n");
            else {
                postOrder(root);
                printf("\n");
            }
        } else if (command == 5) {
            scanf("%d", &value);
            printf("%s\n", search(root, value) ? "found" : "not found");
        } else if (command == 6) {
            break;
        }
    }
    return 0;
}
