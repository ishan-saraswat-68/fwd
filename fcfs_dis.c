#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head;
    double seek_time;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter request queue:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head: ");
    scanf("%d", &head);

    printf("Enter seek time per track (ms): ");
    scanf("%lf", &seek_time);

    int movement = 0, current = head;

    for(int i = 0; i < n; i++) {
        movement += abs(req[i] - current);
        current = req[i];
    }

    double avg_seek = (movement * seek_time) / n;

    printf("\nTotal Head Movement = %d tracks", movement);
    printf("\nAverage Seek Time   = %.4f ms\n", avg_seek);

    return 0;
}
