#include <stdio.h>
struct da {
    int max[10], a1[10], need[10], before[10], after[10];
} p[10];

int main() {
    int n, r, tot[10], av[10], c = 0, temp = 0;
    printf("ENTER THE NO. OF PROCESSES: ");
    scanf("%d", &n);
    printf("ENTER THE NO. OF RESOURCES: ");
    scanf("%d", &r);

    for (int i = 0; i < n; i++) {
        printf("PROCESS %d\n", i + 1);
        for (int j = 0; j < r; j++) {
            printf("MAXIMUM VALUE FOR RESOURCE %d: ", j + 1);
            scanf("%d", &p[i].max[j]);
        }
        for (int j = 0; j < r; j++) {
            printf("ALLOCATED FROM RESOURCE %d: ", j + 1);
            scanf("%d", &p[i].a1[j]);
            p[i].need[j] = p[i].max[j] - p[i].a1[j];
        }
    }

    for (int i = 0; i < r; i++) {
        printf("ENTER TOTAL VALUE OF RESOURCE %d: ", i + 1);
        scanf("%d", &tot[i]);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < n; j++) {
            temp += p[j].a1[i];
        }
        av[i] = tot[i] - temp;
        temp = 0;
    }

    printf("RESOURCES  ALLOCATED  NEEDED  TOTAL  AVAIL\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t", i + 1);
        for (int j = 0; j < r; j++) printf("%d ", p[i].max[j]);
        printf("\t");
        for (int j = 0; j < r; j++) printf("%d ", p[i].a1[j]);
        printf("\t");
        for (int j = 0; j < r; j++) printf("%d ", p[i].need[j]);
        if (i == 0) {
            printf("\t");
            for (int j = 0; j < r; j++) printf("%d ", tot[j]);
            printf("\t");
            for (int j = 0; j < r; j++) printf("%d ", av[j]);
        }
        printf("\n");
    }

    printf("\tAVAIL  BEFORE  AVAIL  AFTER\n");
    for (int l = 0; l < n; l++) {
        for (int i = 0; i < n; i++) {
            int cn = 0, cz = 0;
            for (int j = 0; j < r; j++) {
                if (p[i].need[j] > av[j]) cn++;
                if (p[i].max[j] == 0) cz++;
            }
            if (cn == 0 && cz != r) {
                for (int j = 0; j < r; j++) {
                    p[i].before[j] = av[j] - p[i].need[j];
                    p[i].after[j] = p[i].before[j] + p[i].max[j];
                    av[j] = p[i].after[j];
                    p[i].max[j] = 0;
                }
                printf("P%d\t", i + 1);
                for (int j = 0; j < r; j++) printf("%d ", p[i].before[j]);
                printf("\t");
                for (int j = 0; j < r; j++) printf("%d ", p[i].after[j]);
                printf("\n");
                c++;
                break;
            }
        }
    }
    if (c == n)
        printf("THE ABOVE SEQUENCE IS A SAFE SEQUENCE\n");
    else
        printf("DEADLOCK OCCURRED\n");

    return 0;
    
    
}
