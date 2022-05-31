#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main() {

    unsigned long int n, m,i, j, count;
    if (scanf("%lu%lu", &m, &n) == 2) {

    bool *bools_array = (bool*)malloc(33554432*sizeof(bool)); 
    n += 1;

    for (i = 2; i < n; i++) {
        bools_array[i] = 1;
    }

    for (i = 2; i < n; i++) {
        if (bools_array[i])
            for (j = i; i*j < n; j++)
                bools_array[i*j] = 0;
    }

    count = 0;
    for (i = m; i < n; i++)
        count += bools_array[i];

    unsigned long int i = 1, k = 0, count3 = 0, count2;
    while (m > k) {
        k = (i * (i+1))/2;
        i++;
    }
    count3 = i;

    while (n > k) {
        k = (i * (i+1))/2;
        i++;
    }
    count2 = i - count3;

    printf("%lu %lu\n", count2, count);

    }
    return 0;
}