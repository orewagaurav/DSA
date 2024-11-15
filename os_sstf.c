#include <stdio.h>
#include <stdlib.h>

// Function to calculate total head movement using SSTF
int calculateTotalHeadMovement(int requests[], int n, int head) {
    int totalHeadMovement = 0;
    int processed[n];
    int i, min_distance, closest_index;

    // Initialize processed array to track completed requests
    for (i = 0; i < n; i++)
        processed[i] = 0;

    // Process each request
    for (i = 0; i < n; i++) {
        min_distance = __INT_MAX__;
        closest_index = -1;

        // Find the closest unprocessed request
        for (int j = 0; j < n; j++) {
            if (!processed[j]) {
                int distance = abs(requests[j] - head);
                if (distance < min_distance) {
                    min_distance = distance;
                    closest_index = j;
                }
            }
        }

        // Mark the request as processed
        processed[closest_index] = 1;

        // Update total head movement
        totalHeadMovement += min_distance;

        // Move head to the position of the processed request
        head = requests[closest_index];
    }

    return totalHeadMovement;
}

int main() {
    int n, i, head;

    // Input: number of requests
    printf("Enter the number of Requests: ");
    scanf("%d", &n);

    // Input: request sequence
    int requests[n];
    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    // Input: initial head position
    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Calculate total head movement
    int totalHeadMovement = calculateTotalHeadMovement(requests, n, head);
    printf("Total head movement is %d\n", totalHeadMovement);

    return 0;
}