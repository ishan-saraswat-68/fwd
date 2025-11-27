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

    int arr[n+1], k = 0;
    for(int i = 0; i < n; i++) arr[k++] = req[i];
    arr[k++] = head;

    for(int i = 0; i < k; i++)
        for(int j = i + 1; j < k; j++)
            if(arr[j] < arr[i]) {
                int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
            }

    int pos = 0;
    for(int i = 0; i < k; i++) if(arr[i] == head) pos = i;

    int movement = 0, current = head;

    for(int i = pos + 1; i < k; i++) {
        movement += abs(arr[i] - current);
        current = arr[i];
    }

    movement += abs(current - arr[0]);
    current = arr[0];

    for(int i = 1; i < pos; i++) {
        movement += abs(arr[i] - current);
        current = arr[i];
    }

    double avg = (movement * seek_time) / n;

    printf("\nTotal Head Movement = %d tracks", movement);
    printf("\nAverage Seek Time   = %.4f ms\n", avg);

    return 0;
}
