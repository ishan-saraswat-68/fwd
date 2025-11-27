#include <stdio.h>

#define TLB_SIZE 4
#define PT_SIZE 32

int main() {
    int pageTable[PT_SIZE];
    int tlbPage[TLB_SIZE], tlbFrame[TLB_SIZE];

    for(int i = 0; i < PT_SIZE; i++)
        pageTable[i] = i;  // simple mapping: page = frame

    for(int i = 0; i < TLB_SIZE; i++)
        tlbPage[i] = tlbFrame[i] = -1;

    int page_size = 1024;
    int logical, hit = 0, miss = 0;

    printf("Enter logical addresses (-1 to stop):\n");

    while(1) {
        scanf("%d", &logical);
        if(logical == -1) break;

        int page = logical / page_size;
        int offset = logical % page_size;

        int tlbHit = 0;

        for(int i = 0; i < TLB_SIZE; i++) {
            if(tlbPage[i] == page) {
                tlbHit = 1;
                int frame = tlbFrame[i];
                int physical = frame * page_size + offset;
                printf("TLB HIT -> Physical Address: %d\n", physical);
                hit++;
                break;
            }
        }

        if(!tlbHit) {
            miss++;
            int frame = pageTable[page];
            for(int i = TLB_SIZE - 1; i > 0; i--) {
                tlbPage[i] = tlbPage[i - 1];
                tlbFrame[i] = tlbFrame[i - 1];
            }
            tlbPage[0] = page;
            tlbFrame[0] = frame;

            int physical = frame * page_size + offset;
            printf("TLB MISS -> Physical Address: %d\n", physical);
        }
    }

    float hitRatio = (float)hit / (hit + miss);
    printf("\nTLB Hit Ratio = %.2f\n", hitRatio);

    return 0;
}
