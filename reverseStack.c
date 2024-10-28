#include <stdio.h>
#include <stdlib.h>

// Define the stack structure
struct stack {
    int data;
    struct stack *next;
} *top = NULL;

// Function to push an element onto the stack
void push(int value) {
    struct stack *tmp,*ptr = malloc(sizeof(struct stack));
    ptr->next = NULL;
    ptr->data =value;
    // if (ptr == NULL) return;
    if(top==NULL)
    top=ptr;
    else{
        tmp =top;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=ptr;
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == NULL) return -1;
    struct stack *temp = top,*temp1;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    int poppedValue = temp->next->data;
    temp1 = temp->next;
    temp->next =NULL;
    // free(temp1);
    return poppedValue;
}

// Function to insert an element at the bottom of the stack
void insertAtBottom(int value) {
    if (top == NULL) {
        push(value);
    } else {
        int temp = pop();
        insertAtBottom(value);
        push(temp);
    }
}

// Recursive function to reverse the stack
void reverseStack() {
    if (top != NULL) {
        int temp = pop();
        reverseStack();
        insertAtBottom(temp);
    }
}

// Function to display the stack
void display() {
    struct stack *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, value;
    scanf("%d", &n);

    // Reading elements into the stack
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Reverse the stack
    reverseStack();

    // Display the reversed stack
    display();

    return 0;
}
