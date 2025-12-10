#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a[10];
    int n;

    for (int i = 0; i < 10; ++i) {
        scanf("%d", &n);
        a[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j)
            a[i][j] = i + 1;
    }

    for (int i = 0; i < 10; ++i) {
        int cols = 0;
        while (a[i][cols] == i + 1) ++cols;
        printf("Row %d -> ", i + 1);
        for (int j = 0; j < cols; ++j)
            printf("%d", a[i][j]);
        printf("\n");
        free(a[i]);
    }
    return 0;
}