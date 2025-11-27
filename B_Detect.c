#include <stdio.h>

int main() {
    int n, m;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], req[n][m], avail[m];
    int finish[n];

    printf("\nEnter Allocation matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("\nEnter Request matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &req[i][j]);

    printf("\nEnter Available vector:\n");
    for(int i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for(int i = 0; i < n; i++) finish[i] = 0;

    int count = 0;
    while(1) {
        int found = 0;
        for(int p = 0; p < n; p++) {
            if(finish[p] == 0) {
                int flag = 0;
                for(int j = 0; j < m; j++)
                    if(req[p][j] > avail[j]) {
                        flag = 1; break;
                    }
                if(flag == 0) {
                    for(int k = 0; k < m; k++)
                        avail[k] += alloc[p][k];
                    finish[p] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if(!found) break;
    }

    if(count == n) {
        printf("\nNo deadlock. All processes can finish.\n");
    } else {
        printf("\nDeadlock detected. Following processes are deadlocked:\n");
        for(int i = 0; i < n; i++)
            if(finish[i] == 0)
                printf("P%d ", i);
        printf("\n");
    }

    return 0;
}
