#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, size;
    double seek_time;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter request queue:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    printf("Enter seek time per track (ms): ");
    scanf("%lf", &seek_time);

    int arr[n+2], k = 0;
    for(int i = 0; i < n; i++) arr[k++] = req[i];
    arr[k++] = head;
    arr[k++] = size - 1;

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

    movement += abs((size - 1) - current);
    movement += (size - 1);
    current = 0;

    for(int i = 0; i < pos; i++) {
        movement += abs(arr[i] - current);
        current = arr[i];
    }

    double avg = (movement * seek_time) / n;

    printf("\nTotal Head Movement = %d tracks", movement);
    printf("\nAverage Seek Time   = %.4f ms\n", avg);

    return 0;
}
