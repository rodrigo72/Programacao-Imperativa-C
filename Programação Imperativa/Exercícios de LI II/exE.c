#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *str0 = malloc(sizeof(char) * 10001);
    char *str  = malloc(sizeof(char) * 20002);

    if (fgets(str0, 10001, stdin) != NULL) {

        int lengthStr0 = strlen(str0), i = 0, j = 0;
        int lengthStr  = (lengthStr0 - 1) * 2 + 1;

        while (i < lengthStr0*2) {
            str[i] = '#'; 
            str[i+1] = str0[j];
            i += 2;
            j++;
        }

        int radius, center = 0, max = 0;

        while (center < lengthStr) {
            radius = 0;
            while (center - (radius + 1) >= 0 && center + (radius + 1) < lengthStr && str[center - (radius + 1)] == str[center + (radius + 1)]) {
                radius += 1;
            }
            if (radius > max) max = radius;
            center += 1;
        }

        printf("%d\n", max);
    }

    return 0;
}
