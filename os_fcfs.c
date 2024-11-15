#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, totalMovement = 0;
    
    printf("Enter the number of Requests: ");
    scanf("%d", &n);
    
    int requests[n];
    printf("Enter the Requests sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    
    printf("Enter initial head position: ");
    scanf("%d", &head);
    
    for (int i = 0; i < n; i++) {
        totalMovement += abs(requests[i] - head);
        head = requests[i];
    }
    
    printf("Total head movement is %d\n", totalMovement);
    
    return 0;
}
