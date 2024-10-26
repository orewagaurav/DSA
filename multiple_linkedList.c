#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct node** head, int data) {
    struct node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, m, data;

    printf("Enter the number of linked lists: ");
    scanf("%d", &n);

    struct node** heads = (struct node**)malloc(n * sizeof(struct node*));
    for (int i = 0; i < n; i++) {
        heads[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the number of elements in linked list %d: ", i + 1);
        scanf("%d", &m);
        printf("Enter the elements:\n");
        for (int j = 0; j < m; j++) {
            scanf("%d", &data);
            insertNode(&heads[i], data);
        }
    }

    printf("Displaying all linked lists:\n");
    for (int i = 0; i < n; i++) {
        printf("Linked List %d: ", i + 1);
        displayList(heads[i]);
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        struct node* current = heads[i];
        struct node* next;
        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
    }
    
    free(heads);

    return 0;
}

