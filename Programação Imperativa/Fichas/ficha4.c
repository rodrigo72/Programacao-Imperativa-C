#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 500

void minusculas(char str[], int length) {
    int ascii;
    for (int i = 0; i < length; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            ascii = str[i];
            str[i] = ascii + 32;
        }
    }
}

int contalinhas(char str[], int length) {
    int i = 0, total = 0;
    for (; i < length; i++) {
        if (str[i] == '\n') total += 1;
    }
    return total;
}

int contaPal(char str[], int length) {
    int total = 0, word = 0; 
    for (int i = 0; i < length; i++) {
        if (isspace(str[i]) && word) {
            total++;
            word = 0;
        } else 
            word = 1;
    }
    return total;
}

int procura(char *str, char *arrayStr[], int length) {
    for (int i = 0; i < length+1; i++) {
        if(strcmp(str, arrayStr[i]) == 0) {
            return 1;
        } 
    }
    return 0;
}

int procuraBinaria(char *str, char *arrayStr[], int length) {
    return 0;
}

int zeros(int N, int M, int m[N][M]) {
    int resultado = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (m[i][j] == 0) resultado += 1;
        }
    }
    return resultado;
}

void identidade(int N, int M, int m[N][M]) {

    for(int i = 0; i < N; i++)
        for(int j = 0; j <= N; j++)
            m[i][j] = i == j ? 1 : 0;

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[]) {

    int length, num, linhas, colunas;
    char str[MAX], temp[MAX];
    printf("FICHA 4:\nIntroduza o número da questão: ");
    char op = getchar();
    printf("\n");
    while((getchar()) != '\n');    

    switch (op) {
        case '1':
            printf("Função que substitui na string inserida todas as letras maiúsculas pela correspondente letra minúscula.\nIntroduza uma string:\n\n> ");
            fgets(str, MAX, stdin);
            length = strlen(str);
            minusculas(str, length);
            printf("> %s\n", str);

        case '2':
            printf("Função que conta quantas linhas tem uma string.\nIntroduza uma string:\n\n> ");
            fgets(str, MAX, stdin);
            length = strlen(str);
            printf("> %d\n", contalinhas(str, length));
            break;

        case '3':
            printf("Função que conta quantas palavras tem uma string.\nIntroduza uma string:\n\n>");
            fgets(str, MAX, stdin);
            length = strlen(str);
            printf("> %d\n", contaPal(str, length));
            break;

        case '4': {
            printf("Em manutenção.\n");
            break;

            printf("Função que procura uma string num array de strings.\nIntroduza uma string:\n\n> ");
            fgets(str, MAX, stdin);
            length = strlen(str);

            printf("Introduza o número de strings:\n\n> ");
            scanf("%d", &num); 
            while ((getchar()) != '\n');
            printf("\n");
            char **frases = malloc(sizeof *frases * num);

            for (int i = 0; i < num; i++) {
                printf("Frase %d: ", i+1);
                frases[i] = malloc(sizeof *frases[i] * (MAX + 1));
                fgets(temp, MAX, stdin);
                strcpy(frases[i],temp);
            }

            if (procura(str, frases, num) == 1) 
                printf("\n> [Found]\n");
            else   
                printf("\n> [Not found]\n");
            break;
        }

        case '5':
            printf("> [Nothing here]\n");
            break;
        
        case '6': {
            printf("Nothing here.\n");
            break;
        }
        
        case '7': {
            printf("Função que conta quandos zeros tem uma matriz.\nIntroduza o número de linhas:\n> ");
            scanf("%d", &linhas);
            printf("Introduza o número de colunas:\n> ");
            scanf("%d", &colunas);
            int mat[linhas][colunas];
            printf("\n");
            
            for (int i = 0; i < linhas; i++) {
                for (int j = 0; j < colunas; j++) {
                    printf("Linha %d, coluna %d: ", i, j);
                    scanf("%d", &mat[i][j]);
                }
            }
            printf("\n");

            for (int i = 0; i < linhas; i ++) {
                for (int j = 0; j < colunas; j++) {
                    printf("%d ", mat[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            printf("> %d\n", zeros(linhas, colunas, mat));
            printf("\nMatriz identidade de ordem N(linhas):\n");
            identidade(linhas, colunas, mat);

            break;
        }

        case '8':
            printf("> [Nothing here]\n");
            break;
        
        case '9':
            printf("> [Nothing here]\n");
            break;
        

        default:
            break;
    }

    return 0;
}