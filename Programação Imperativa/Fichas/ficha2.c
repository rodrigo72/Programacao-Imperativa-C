#include <stdio.h>

float multInt(int n, float m) {
    
    float x = 0;
    for (int i = 1; i <= n; i++) {
        x += m; 
    }
    return x;
}

float multInt2(int n, float m) {
    
    float x = 0;
    while (n > 0) {
        if (n % 2) x += m;
        n /= 2;
        m *= 2;
    }
    return x;
}

// calcula o m.d.c entre dois numeros inteiros nao negativos

int min(int a, int b) {
    if (a > b) 
        return b;
    else 
        return a;
}

int mdc(int a, int b) {

    int temp, resultado;
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }

    for (int i = 1; i <= b; i++) {
        if (a % i == 0 && b % i == 0)
            resultado = i;
    }
    return resultado;
}

int mdc2(int a, int b) {

    if (a > b)
        return mdc(a-b,b);
    else if (a < b) 
            return mdc(a, b-a);
         else 
            return a;
}

int euclizar(int a, int b) {

    int r, temp;
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }

    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    if (a == 0) return b;
    else return a;
}

int fibbo(int a) {

    // if (a == 1 || a == 2)
    //     return 1;
    // else 
    //     return fibbo(a-1) + fibbo(a-2);

    int resultado;
    if (a == 1 || a == 2)
        resultado = 1;
    else 
        resultado = fibbo(a - 1) + fibbo(a-2);
    
    return resultado;
}

int fib(int n) {

    int resultado, resultado2, resultado3;
    resultado  = 0;
    resultado2 = 1;
    resultado3 = 1;

    while (n > 2) {
        resultado = resultado2 + resultado3;
        resultado2 = resultado3;
        resultado3 = resultado;
        n--;
    }

    return resultado;
}

int main() {

    int opt, num1, num2;
    float fl1, resultado;

    printf("Introduza o número da pergunta: ");
    scanf("%d", &opt);

    switch (opt) {
        case 1: 
            printf("\nFunção que multiplica inteiros.\nInsira dois números: \n");
            scanf("%d%f", &num1, &fl1);
            resultado = multInt(num1, fl1);
            printf("Resposta: %f\n", resultado);
            break;

        case 2:
            printf("\nFunção que multiplica inteiros.\nInsira dois números (mas mais eficiente): \n");
            scanf("%d%f", &num1, &fl1);
            resultado = multInt2(num1, fl1);
            printf("Resposta: %f\n", resultado);
            break;

        case 3: 
            printf("\nFunção que devolve o máximo divisor comun entre dois números.\nIntroduza dois números:\n");
            scanf("%d%d", &num1, &num2);
            printf("Resposta: %d\n", mdc(num1, num2));
            break;

        case 4:
            printf("\nFunção que devolve o máximo divisor comun entre dois números. (mais eficiente)\nIntroduza dois números:\n");
            scanf("%d%d", &num1, &num2);
            printf("Resposta: %d\n", mdc2(num1, num2));
            break;
        
        case 5:
            printf("\nFunção que devolve o máximo divisor comun entre dois números. (mais eficiente x2)\nIntroduza dois números:\n");
            scanf("%d%d", &num1, &num2);
            printf("Resposta: %d\n", euclizar(num1, num2));
            break;

        case 6:
            printf("\nSequência de Fibonacci. (recursivamente)\nIntroduza um número:\n");
            scanf("%d", &num1);
            printf("Resposta: %d\n", fibbo(num1));
            break;

        case 7:
            printf("\nSequência de Fibonacci. (iterativamente)\nIntroduza um número:\n");
            scanf("%d", &num1);
            printf("Resposta: %d\n", fib(num1));
            break;

        default: 
            break;
    }
    return 0;
}