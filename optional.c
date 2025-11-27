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

    int faults = 0;

    for(int i = 0; i < n; i++) {
        int hit = 0;

        for(int j = 0; j < frames; j++)
            if(f[j] == page[i]) {
                hit = 1;
                break;
            }

        if(!hit) {
            int pos[frames];
            for(int j = 0; j < frames; j++) {
                int found = 0;
                for(int k = i + 1; k < n; k++) {
                    if(f[j] == page[k]) {
                        pos[j] = k;
                        found = 1;
                        break;
                    }
                }
                if(!found) pos[j] = 99999;
            }

            int max = 0;
            for(int j = 1; j < frames; j++)
                if(pos[j] > pos[max])
                    max = j;

            f[max] = page[i];
            faults++;
        }
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
