#include <stdio.h>
#include <stdbool.h>

int fatorial (int a) {
    
    int i, fact;
    fact = 1;

    for (i = 1; i <= a; ++i) {
         fact = fact * i; 
    }

    return fact;

}

bool verifica (int a) {
    
    int fact, i;
    i = 0;  
    fact = 1;

    while (fact < a) {
        fact = fatorial(i);
        i++;
    }

    if (fact == a)
        return true;
    else 
        return false;

}

void swap(int *x, int *y) {

    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    
    int a, b, c;
    if (scanf("%d%d%d", &a, &b, &c) == 3) {

        if (a > c)
            swap(&a, &c);

        if (a > b)    
            swap(&a, &b);
    
        if (b > c)
            swap (&b, &c);

        if (verifica(c))
             printf("FATORIAL\n");
        else 
             printf("%d %d %d\n", a, b, c);
    }

    return 0;
}
