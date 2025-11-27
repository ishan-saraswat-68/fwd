#include <stdio.h>

int main() {
    int n, frames;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int page[n];
    printf("Enter page reference string:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int f[frames];
    for(int i = 0; i < frames; i++)
        f[i] = -1;

    int faults = 0, front = 0;

    for(int i = 0; i < n; i++) {
        int hit = 0;

        for(int j = 0; j < frames; j++) {
            if(f[j] == page[i]) {
                hit = 1;
                break;
            }
        }

        if(!hit) {
            f[front] = page[i];
            front = (front + 1) % frames;
            faults++;
        }
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
