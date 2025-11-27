#include <stdio.h>

int main() {
    int b, p;

    printf("Enter number of memory blocks: ");
    scanf("%d", &b);
    int block[b];

    printf("Enter block sizes:\n");
    for(int i = 0; i < b; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &p);
    int process[p];

    printf("Enter process sizes:\n");
    for(int i = 0; i < p; i++)
        scanf("%d", &process[i]);

    int allocFF[p], allocBF[p], allocWF[p];

    for(int i = 0; i < p; i++) {
        allocFF[i] = allocBF[i] = allocWF[i] = -1;
    }

    // ---------- FIRST FIT ----------
    int tempB[b];
    for(int i = 0; i < b; i++) tempB[i] = block[i];

    for(int i = 0; i < p; i++) {
        for(int j = 0; j < b; j++) {
            if(tempB[j] >= process[i]) {
                allocFF[i] = j;
                tempB[j] -= process[i];
                break;
            }
        }
    }

    // ---------- BEST FIT ----------
    for(int i = 0; i < b; i++) tempB[i] = block[i];

    for(int i = 0; i < p; i++) {
        int best = -1;
        for(int j = 0; j < b; j++) {
            if(tempB[j] >= process[i]) {
                if(best == -1 || tempB[j] < tempB[best])
                    best = j;
            }
        }
        if(best != -1) {
            allocBF[i] = best;
            tempB[best] -= process[i];
        }
    }

    // ---------- WORST FIT ----------
    for(int i = 0; i < b; i++) tempB[i] = block[i];

    for(int i = 0; i < p; i++) {
        int worst = -1;
        for(int j = 0; j < b; j++) {
            if(tempB[j] >= process[i]) {
                if(worst == -1 || tempB[j] > tempB[worst])
                    worst = j;
            }
        }
        if(worst != -1) {
            allocWF[i] = worst;
            tempB[worst] -= process[i];
        }
    }

    printf("\nProcess\tSize\tFF\tBF\tWF\n");
    for(int i = 0; i < p; i++) {
        printf("P%d\t%d\t", i, process[i]);
        printf("%d\t", allocFF[i]);
        printf("%d\t", allocBF[i]);
        printf("%d\n", allocWF[i]);
    }

    return 0;
}
