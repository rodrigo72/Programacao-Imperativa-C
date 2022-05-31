#include <stdio.h>
#define pi 3.14

int main() {

    int a, b, c, volume;
    // const int pi = 3.14;
    if (scanf("%d%d%d", &a, &b, &c) == 3) {
        volume = (pi * b)/3 * (a*a + c*a + c*c);
        printf("%d\n", volume);
    }

    return 0;
}