#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Create a new node
void create(struct node **head, int value) {
    struct node *ptr = malloc(sizeof(struct node));
    ptr->next = NULL;
    ptr->data = value;
    struct node *tmp;
    if (*head == NULL) {
        *head = ptr;
    } else {
        tmp = *head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = ptr;
    }
}
struct node* reverse(struct node* head) {
    struct node *curr = head, *nxt = NULL, *pre = NULL;
    while (curr != NULL) {
        nxt = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nxt;
    }
    return pre;
}

// Check if the linked list is a palindrome
int isPalindrome(struct node* head) {
    if (head == NULL) {
        return 0;
         // Empty list or single node list is a palindrome
    }
    else if(head->next==NULL){
        return 1;
    }
    
    // Find the middle of the linked list
    struct node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse the second half of the list
    struct node *secondHalf = reverse(slow);
    struct node *firstHalf = head;
    
    // Compare the two halves
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            return 0;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return 1;
}

int main() {
    int n, value;
    scanf("%d", &n);
    struct node **head = (struct node**)malloc(n * sizeof(struct node*));
    for (int i = 0; i < n; i++) {
        head[i] = NULL;
    }   
    for (int i = 0; i < n; i++) {
        while (1) {
            scanf("%d", &value);
            if (value == -1) break;
            create(&head[i], value);
        }
    } 
    for (int i = 0; i < n; i++) {
        int result = isPalindrome(head[i]);
        if(head[i]!=NULL){
            if (result == 1) {
                printf("true\n");
            }
            else {
                printf("false\n");
            }
        }
    }
    
    return 0;
}