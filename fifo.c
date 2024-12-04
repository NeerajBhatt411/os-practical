#include <stdio.h>

int main() {
    int n, frames;

    // Input: Number of pages and frames
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int pages[n];

    printf("Enter the page sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("Page %d: ", i + 1);
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    int memory[frames];
    
    // Initialize frames to -1 (indicating empty)
    for (int i = 0; i < frames; i++) {
        memory[i] = -1;
    }

    int pageFaults = 0, front = 0;

    // Process each page
    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if the page is already in memory (hit)
        for (int j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) { // If the page is not in memory (miss)
            memory[front] = pages[i]; // Replace the oldest page
            front = (front + 1) % frames; // Move to the next frame (FIFO)
            pageFaults++;
        }

        // Display memory state
        printf("Memory: ");
        for (int j = 0; j < frames; j++) {
            if (memory[j] != -1)
                printf("%d ", memory[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    // Output total page faults
    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}
