#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, head, size, direction;
    double seek_time;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter request queue:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    printf("Enter seek time per track (ms): ");
    scanf("%lf", &seek_time);

    printf("Enter direction (0 = left, 1 = right): ");
    scanf("%d", &direction);

    // Separate requests into left and right side
    int left[n], right[n];
    int lc = 0, rc = 0;

    for(int i = 0; i < n; i++) {
        if (req[i] < head)
            left[lc++] = req[i];
        else
            right[rc++] = req[i];
    }

    // Sort both sides
    qsort(left, lc, sizeof(int), compare);
    qsort(right, rc, sizeof(int), compare);

    int total_movement = 0;
    int current = head;

    printf("\nSCAN Sequence: %d", head);

    if (direction == 0) {  
        // Move left first
        for(int i = lc - 1; i >= 0; i--) {
            total_movement += abs(left[i] - current);
            current = left[i];
            printf(" -> %d", current);
        }

        // Move to 0 (end)
        total_movement += abs(current - 0);
        current = 0;
        printf(" -> 0");

        // Now move right
        for(int i = 0; i < rc; i++) {
            total_movement += abs(right[i] - current);
            current = right[i];
            printf(" -> %d", current);
        }

    } else {  
        // Move right first
        for(int i = 0; i < rc; i++) {
            total_movement += abs(right[i] - current);
            current = right[i];
            printf(" -> %d", current);
        }

        // Move to end (size - 1)
        total_movement += abs((size - 1) - current);
        current = size - 1;
        printf(" -> %d", current);

        // Move left
        for(int i = lc - 1; i >= 0; i--) {
            total_movement += abs(left[i] - current);
            current = left[i];
            printf(" -> %d", current);
        }
    }

    double avg_seek = (total_movement * seek_time) / n;

    printf("\n\nTotal Head Movement = %d tracks", total_movement);
    printf("\nAverage Seek Time   = %.4f ms\n", avg_seek);

    return 0;
}
