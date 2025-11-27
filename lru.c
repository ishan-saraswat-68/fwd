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

    int f[frames], time[frames], t = 0;

    for(int i = 0; i < frames; i++) {
        f[i] = -1;
        time[i] = 0;
    }

    int faults = 0;

    for(int i = 0; i < n; i++) {
        t++;
        int hit = 0;

        for(int j = 0; j < frames; j++) {
            if(f[j] == page[i]) {
                hit = 1;
                time[j] = t;
                break;
            }
        }

        if(!hit) {
            int lru = 0;
            for(int j = 1; j < frames; j++)
                if(time[j] < time[lru])
                    lru = j;

            f[lru] = page[i];
            time[lru] = t;
            faults++;
        }
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
