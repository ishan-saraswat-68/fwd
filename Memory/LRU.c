#include <stdio.h>
#include <limits.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

void printFrames(int frames[], int n_frames) {
    for (int i = 0; i < n_frames; i++) {
        if (frames[i] != -1) printf("%d ", frames[i]);
        else printf("- ");
    }
    printf("\n");
}

// --- LRU Logic ---
void LRU(int pages[], int n_pages, int n_frames) {
    int frames[MAX_FRAMES];
    int last_used[MAX_FRAMES]; // Stores index when frame was last used
    for (int i = 0; i < n_frames; i++) frames[i] = -1;

    int page_faults = 0;

    printf("\nRef\tFrames\n");
    for (int i = 0; i < n_pages; i++) {
        printf("%d\t", pages[i]);

        int found_idx = -1;
        for (int j = 0; j < n_frames; j++) {
            if (frames[j] == pages[i]) {
                found_idx = j;
                break;
            }
        }

        if (found_idx != -1) {
            last_used[found_idx] = i; // Update usage time
            printFrames(frames, n_frames);
        } else {
            page_faults++;
            int lru_idx = -1;
            int min_time = INT_MAX;

            // Fill empty slots first
            for (int j = 0; j < n_frames; j++) {
                if (frames[j] == -1) {
                    lru_idx = j;
                    break;
                }
            }

            // Find LRU if no empty slots
            if (lru_idx == -1) {
                for (int j = 0; j < n_frames; j++) {
                    if (last_used[j] < min_time) {
                        min_time = last_used[j];
                        lru_idx = j;
                    }
                }
            }

            frames[lru_idx] = pages[i];
            last_used[lru_idx] = i;
            printFrames(frames, n_frames);
        }
    }
    printf("\nTotal Page Faults: %d\n", page_faults);
}

int main() {
    int pages[MAX_PAGES];
    int n_pages, n_frames;

    printf("--- LRU Page Replacement ---\n");
    printf("Enter number of frames: ");
    scanf("%d", &n_frames);

    printf("Enter number of pages: ");
    scanf("%d", &n_pages);

    printf("Enter reference string: ");
    for (int i = 0; i < n_pages; i++) scanf("%d", &pages[i]);

    LRU(pages, n_pages, n_frames);

    return 0;
}