#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatenate(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *res = malloc(len1 + len2 + 1);
    if (!res) return NULL;
    strcpy(res, s1);
    strcat(res, s2);
    return res;
}

int main(void) {
    char *total = malloc(1);
    if (!total) return 0;
    total[0] = '\0';
    char buf1[1024], buf2[1024];

    while (1) {
        printf("Enter first string (Q to quit): ");
        if (!fgets(buf1, sizeof(buf1), stdin)) break;
        buf1[strcspn(buf1, "\n")] = '\0';
        if (strcmp(buf1, "Q") == 0) break;

        printf("Enter second string: ");
        if (!fgets(buf2, sizeof(buf2), stdin)) break;
        buf2[strcspn(buf2, "\n")] = '\0';

        char *new_total = concatenate(total, buf1);
        if (!new_total) { printf("Memory error\n"); continue; }
        free(total);
        total = new_total;

        new_total = concatenate(total, buf2);
        if (!new_total) { printf("Memory error\n"); continue; }
        free(total);
        total = new_total;

        printf("Concatenated: %s\n", total);
    }
    free(total);
    return 0;
}