#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct aluno {
    int  numero;
    char nome[100];
    int  miniT [6];
    float teste;
} Aluno;

int nota(Aluno a) {
    int nota = 0, i;

    for (i = 0; i < 6; i++) {
        nota += a.miniT[i];
    }

    nota = nota * 0.25 * 20 / 12.0 + a.teste * 0.75;
    if (nota < 9.5) return 0;
    else return nota;
}

int procuraNum(int num, Aluno t[], int N) {
    int i = 0, l = 1, r = N, m = 1; 

    while (l <= r) {
        m = (l + r) / 2;

        if (t[m].numero == num) return m;
        if (t[m].numero > num)
            r = m - 1;
        else 
            l = m + 1;

    }
    return -1;
}

void ordenaPorNum(Aluno t[], int N) {
    int i, j, m;

    for (i = 0; i < N-1; i++) {
        m = i;
        for (j = i + 1; j < N; j++) 
            if (t[j].numero < t[m].numero)
                m = j;
        if (m != i) {
            Aluno temp = t[i];
            t[i] = t[m];
            t[m] = temp;
        }
    }
}

void criaIndPorNum(Aluno t[], int N, int ind[]) {
    int i, j, m, temp;
    
    for(i = 0; i < N; i++) ind[i] = i;

    for(i = 0; i < N-1; i++) {
        m = i;
        for (j = i+1; j < N; j++)
            if (t[ind[j]].numero < t[ind[m]].numero)
                m = j;
        
        if (m != i) {
            temp = ind[i];
            ind[i] = ind[m];
            ind[m] = temp;
        }
    }
}

void criaIndPorNome(Aluno t[], int N, int ind[]) {
    int i, j, temp, m;

    for(i = 0; i < N; i++) ind[i] = i;

    for(i = 0; i < N-1; i++) {
        m = i;
        for (j = i+1; j < N; j++)
            if (t[ind[j]].nome[0] < t[ind[m]].nome[0])
                m = j;

        if (m != i) {
            temp = ind[i];
            ind[i] = ind[m];
            ind[m] = temp;
        }
    }
}

int main() {

    int ind[7];

    Aluno Turma [7] = {{1111, "André", {2,1,0,2,2,2}, 10.5}
                       ,{2222, "Paulo", {0,0,2,2,2,1},  8.7}
                       ,{3333, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{4444, "Joana", {2,0,2,1,0,2},  3.5}
                       ,{5555, "Maria", {2,2,2,2,2,1},  5.5}
                       ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
                       ,{7777, "Diogo", {2,2,1,1,1,0},  8.5}
                       } ;

    Aluno Turma2 [7] = {{2222, "André", {2,1,0,2,2,2}, 10.5}
                       ,{5555, "Paulo", {0,0,2,2,2,1},  8.7}
                       ,{3333, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{4444, "Joana", {2,0,2,1,0,2},  3.5}
                       ,{9999, "Maria", {2,2,2,2,2,1},  5.5}
                       ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
                       ,{7777, "Diogo", {2,2,1,1,1,0},  8.5}
                       } ;

    Aluno Turma3 [7] = {{2222, "André", {2,1,0,2,2,2}, 10.5}
                       ,{5555, "Paulo", {0,0,2,2,2,1},  8.7}
                       ,{3333, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{4444, "Joana", {2,0,2,1,0,2},  3.5}
                       ,{9999, "Maria", {2,2,2,2,2,1},  5.5}
                       ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
                       ,{7777, "Diogo", {2,2,1,1,1,0},  8.5}
                       } ;

    Aluno Turma4 [7] = {{2222, "André", {2,1,0,2,2,2}, 10.5}
                       ,{5555, "Paulo", {0,0,2,2,2,1},  8.7}
                       ,{3333, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{4444, "Joana", {2,0,2,1,0,2},  3.5}
                       ,{9999, "Maria", {2,2,2,2,2,1},  5.5}
                       ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
                       ,{7777, "Diogo", {2,2,1,1,1,0},  8.5}
                       } ;

    printf("Nota: %d\n\n", nota(Turma[2]));
    printf("Indice de um aluno: %d\n\n", procuraNum(4444, Turma, 7));
    ordenaPorNum(Turma2, 7);

    for (int i = 0; i < 7; i++) {
        printf("%d ", Turma2[i].numero);
    }
    printf("\n");

    criaIndPorNum(Turma3, 7, ind);

    for (int i = 0; i < 7; i++) {
        printf("%d ", Turma3[ind[i]].numero);
    }
    printf("\n\n");

    criaIndPorNome(Turma4, 7, ind);

    for (int i = 0; i < 7; i++) {
        printf("%s ", Turma4[ind[i]].nome);
    }
    printf("\n\n");

    return 0;
}