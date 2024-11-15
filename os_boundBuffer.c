#include <stdio.h>
#include <stdlib.h>

#define MAX 3  // Define the maximum size of the buffer

int buffer[MAX];
int count = 0;   // Number of items in the buffer
int in = 0;      // Index for the next producer item
int out = 0;     // Index for the next consumer item

void producer() {
    if (count == MAX) {
        printf("Buffer is full!!\n");
    } else {
        buffer[in] = ++count;  // Produce an item
        printf("Producer produces the item %d\n", buffer[in]);
        in = (in + 1) % MAX;
    }
}

void consumer() {
    if (count == 0) {
        printf("Buffer is empty!!\n");
    } else {
        printf("Consumer consumes item %d\n", buffer[out]);
        buffer[out] = 0;  // Clear the consumed item
        out = (out + 1) % MAX;
        count--;
    }
}

int main() {
    int choice;
    printf("\n1. Producer\n");
    printf("2. Consumer\n");
    printf("3. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!!\n");
        }
    }
    return 0;
}
