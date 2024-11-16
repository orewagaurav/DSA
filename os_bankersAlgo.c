#include <stdio.h>

// Function to print the frames
void print_frames(int frames[], int no_of_frames) {
    for (int i = 0; i < no_of_frames; i++) {
        if (frames[i] == -1)
            printf("-1");
        else
            printf("%d", frames[i]);
        
        if (i < no_of_frames - 1) 
            printf(" ");
    }
    printf("\n");
}

int main() {
    int no_of_frames, no_of_references;

    printf("FIFO PAGE REPLACEMENT ALGORITHM\n");

    // Input: number of frames
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    // Input: length of reference string
    printf("Enter number of references: ");
    scanf("%d", &no_of_references);

    // Input: reference string
    int reference_string[no_of_references];
    printf("Enter the reference string: ");
    for (int i = 0; i < no_of_references; i++) {
        scanf("%d", &reference_string[i]);
    }

    // Initialize frames and variables
    int frames[no_of_frames];
    for (int i = 0; i < no_of_frames; i++) {
        frames[i] = -1;  // Initialize all frames to -1
    }

    int page_faults = 0, index = 0;

    // Display the reference string
    printf("The given reference string: ");
    for (int i = 0; i < no_of_references; i++) {
        printf("%d", reference_string[i]);
        if (i < no_of_references - 1) {
            printf(" ");
        }
    }
    printf("\n");

    // FIFO page replacement process
    for (int i = 0; i < no_of_references; i++) {
        int found = 0;

        // Check if the current reference is already in a frame
        for (int j = 0; j < no_of_frames; j++) {
            if (frames[j] == reference_string[i]) {
                found = 1;
                break;
            }
        }

        // If not found, it's a page fault
        if (!found) {
            frames[index] = reference_string[i];
            index = (index + 1) % no_of_frames;  // FIFO replacement
            page_faults++;
        }

        // Print the state of frames after every reference
        printf("Reference %d -> ", reference_string[i]);
        print_frames(frames, no_of_frames);
    }

    // Output the total number of page faults
    printf("Number of page faults: %d\n", page_faults);

    return 0;
}