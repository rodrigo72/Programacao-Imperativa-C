#include <stdio.h>
#include <stdlib.h>

void swapM (int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void trocaPosicoes(int vetor[], int x, int y) {
    int temp = vetor[x];
    vetor[x] = vetor[y];
    vetor[y] = temp;
}

void createArray(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i;
    }
}

void printArray(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int somaElementos (int vetor[], int tamanho) {
    int resultado = 0;
    for (int i = 0; i < tamanho; i++) {
        resultado += vetor[i];
    }
    return resultado;
}

void inverteArray(int vetor[], int tamanho) {
    int i = 0, j = tamanho - 1;
    for (i, j; i < j; i++, j--) {
        trocaPosicoes(vetor, i, j);
    }
}

int maximoArray(int v[], int tamanho, int *m) {
    if (tamanho < 1)
        return 1;
    else {
        *m = v[0];
        for (int i = 0; i < tamanho; i++) {
            if (v[i] > *m) *m = v[i];
        }
        return 0;
    } 
}

void quadrados(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i*i;
    }
}

void pascal2(int v[], int tamanho) {

    int ant[tamanho];
    for (int i = 0; i < tamanho; i++) {
        ant[i] = 0;
    }

    v[0] = 1; 
    ant[0] = 1;
    for (int i = 0; i < tamanho; i++) {

        for (int i = 1; i < tamanho; i++) {
            v[i] = ant[i-1] + ant[i];
        }

        for (int i = 0; i < tamanho; i++) {
            ant[i] = v[i];
        }
    }
    v[tamanho] = 1;

}


// versao mais simples:

void pascal(int t[], int tamanho) {
    int i, j;

    t[0] = 1;
    for (i = 1; i <= tamanho; i++) {
        t[i] = 1;
        for (j = i-1; j > 0; j--) {
            t[j] += t[j-1];
        }
    }
}

int main() {

    int op, tamanho, x, y, resultado;
    printf("Introduza o número da questão:\n");
    scanf("%d", &op);
    int *vetor;

    switch (op) {
        case 1:
            printf("Nada aqui.\n");
            break;

        case 2:
            printf("\nFunção que troca o valor de duas variáveis.\nIntroduza dois integers:\n");
            scanf("%d %d", &x, &y);
            swapM(&x,&y);
            printf("\n%d\n%d\n", x, y);
            break;

        case 3:
            printf("\nFunção que troca o valor das posições i e j do vetor v.\nIntroduza o tamanho do vetor:\n");
            scanf("%d", &tamanho);
            vetor = malloc(sizeof(int) * tamanho);
            createArray(vetor, tamanho);
            printf("\nIntroduza as posições i e j:\n");
            scanf("%d %d", &x, &y);
            trocaPosicoes(vetor, x, y);
            printArray(vetor, tamanho);
            break;

        case 4: 
            printf("\nFunção que calcula a soma dos elementos de um vetor com n inteiros.\nIntroduza o tamanho do vetor:\n");
            scanf("%d", &tamanho);
            vetor = malloc(sizeof(int) * tamanho);
            createArray(vetor, tamanho);
            printArray (vetor, tamanho);
            printf("O valor da soma dos elementos do vetor é: %d\n", somaElementos(vetor, tamanho));
            break;

        case 5:
            printf("\nFunção que inverte um array.\nIntroduza o tamanho do array:\n");
            scanf("%d", &tamanho);
            vetor = malloc(sizeof(int) * tamanho);
            createArray  (vetor, tamanho);
            printArray   (vetor, tamanho);
            inverteArray (vetor, tamanho);
            printArray   (vetor, tamanho);
            break;

        case 6:
            printf("\nFunção que coloca em *m o maior dos elementos do vetor.\nIntroduza o tamanho do vetor:\n");
            scanf("%d", &tamanho);
            vetor = malloc(sizeof(int) * tamanho);
            createArray(vetor, tamanho);
            int max;
            resultado = maximoArray(vetor, tamanho, &max);
            if (resultado)
                printf("\nErro.\n");
            else 
                printf("\nMáximo: %d\n", max);
            break;

        case 7:
            printf("\nFunção que preenche um vetor com os quadrados dos primeiros números naturais.\nIntroduza o tamanho do vetor:\n");
            scanf("%d", &tamanho);
            vetor = malloc(sizeof(int) * tamanho);
            createArray(vetor, tamanho);
            quadrados(vetor, tamanho);
            printArray(vetor, tamanho);
            break;

        case 8:
            printf("\nFunção que preenche um vetor com uma linha à escolha do triângulo de pascal.\nIntroduza o número da linha:\n");
            scanf("%d", &tamanho);
            vetor = malloc(sizeof(int) * tamanho);
            pascal(vetor, tamanho);
            printArray(vetor, tamanho+1);
            printf("\n");
            for (int i = 0; i < tamanho; i++) {
                pascal(vetor, i);
                printArray(vetor, i+1);
            }
            break;

        default:
            printf("[Não existe.]\n");
            break;
    }

    return 0;
}