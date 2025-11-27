#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head;
    double seek_time;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n], done[n];
    printf("Enter request queue:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        done[i] = 0;
    }

    printf("Enter initial head: ");
    scanf("%d", &head);

    printf("Enter seek time per track (ms): ");
    scanf("%lf", &seek_time);

    int movement = 0, completed = 0, current = head;

    while(completed < n) {
        int minDist = 100000, idx = -1;

        for(int i = 0; i < n; i++) {
            if(!done[i]) {
                int dist = abs(req[i] - current);
                if(dist < minDist) {
                    minDist = dist;
                    idx = i;
                }
            }
        }

        movement += abs(req[idx] - current);
        current = req[idx];
        done[idx] = 1;
        completed++;
    }

    double avg_seek = (movement * seek_time) / n;

    printf("\nTotal Head Movement = %d tracks", movement);
    printf("\nAverage Seek Time   = %.4f ms\n", avg_seek);

    return 0;
}
