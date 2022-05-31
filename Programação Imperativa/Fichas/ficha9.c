#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura que define a árvore binária
// O valor contido em cada nodo é um int
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

// Gera uma nova árvore
ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc(sizeof(struct nodo));
    if (a != NULL) {
        a->valor = r; 
        a-> esq = e;
        a->dir = d;
    }
    return a;
}

// Gera uma árvore aleatória a partir de um array
ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
    	m = rand() % N;
    	a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;	
}

// Free completo da árvore binária
void freeABin (ABin a) {
    if (a == NULL) return;
    freeABin(a->esq);
    freeABin(a->dir);
    free(a);
}

// Função auxiliar da printTree (não funciona muito bem, é difícil fazer print a uma árvore binária)
void imprimeLevel (ABin a, int N, int fixed_N, int altura, int flag){
    if (N > 0 && a != NULL) {

        if (flag == 0)
            for (int i = 0; i < altura - fixed_N; i++) printf(" ");
        else
            for (int i = 0; i < flag; i++) printf(" ");

        if (N == 1) {
            printf("%d", a->valor);
        } else {
            imprimeLevel(a->esq, N - 1, fixed_N, altura, flag++);
            imprimeLevel(a->dir, N - 1, fixed_N, altura, flag++);
        }
    }
}

// Retorna a altura da árvore
int altura (ABin a) {
    if (a == NULL) return 0;
    int e, d;
    e = altura(a->esq);
    d = altura(a->dir);
    if (e > d) return 1 + e;
    return 1 + d;
}

// Cria uma representação da árvore no terminal (mal feita :kermitSip:)
void printTree(ABin a) {
    for (int i = 0; i <= altura(a); i++) {
        imprimeLevel(a, i, i, altura(a), 0);
        printf("\n");
    }
}

// Não esta a ser utilizada
void dumpABin(ABin a) {

}

// Imprime os elementos de um nível, tendo em conta q o nível mais baixo é o nível 1
void imprimeNivel (ABin a, int N) {
    if (N > 0 && a != NULL) {
        if (N == 1)
            printf("%d ", a->valor);
        else {
            imprimeNivel(a->esq, N-1);
            imprimeNivel(a->dir, N-1);
        }
    }
}

// Número de folhas ou seja de nodos com ramificações nulas
int nFolhas (ABin a){
    if (a == NULL) return 0;
    if (a->esq == NULL && a->dir == NULL) return 1;
    return(nFolhas(a->esq) + nFolhas(a->dir));
}

// Nodo mais à esquerda
ABin maisEsquerda (ABin a){
    if (a->esq == NULL) return a;
    maisEsquerda(a->esq);
}

// Verifica se um elemento existe ou não numa árvore binária
int procuraE (ABin a, int x){
    if (a == NULL) return 0;
    if (a->valor == x) return 1;
    return (procuraE(a->esq, x) || procuraE(a->dir, x));
}
// return (a != NULL && (a->valor == x || procuraE(a->esq, x) || procuraE(a->dir, x)))

// RECURSIVAMENTE
struct nodo *procura2 (ABin a, int x){
    if (a == NULL) return NULL;
    if (a->valor == x) return a;
    if (a->valor > x) return procura2(a->esq, x);
    return procura2(a->dir, x);
}

// SEM RECURSIVIDADE
struct nodo *procura (ABin a, int x){
    while(a != NULL && a->valor != x) {
        if (a->valor > x) a = a->esq;
        else a = a->dir;
    }
    return a;
}

// Verifica a que nível está um elemento
int nivel (ABin a, int x){
    int count = 1;
    while(a != NULL && a->valor != x) {
        if (a->valor > x) a = a->esq;
        else a = a->dir;
        count++;
    }
    if (a != NULL)
        return count;
    else 
        return 0;
}

// Imprime no ecrã, por ordem crescente, todos os elementos da árvore que são 
// (estritamente) menores do que um dado valor
void imprimeAte (ABin a, int x){
    if (a != NULL) {
        imprimeAte(a->esq, x);
        if (a->valor < x) {
            printf("%d ", a->valor);
            imprimeAte(a->dir, x);
        }
    }
}

int main() {

    int v1[15] = { 1, 3, 5, 7, 9,11,13,15,17,19,21,23,25,27,29},
        v2[15] = {21, 3,15,27, 9,11,23, 5,17,29, 1,13,25, 7,19},
        N=11;
    ABin a1, a2,r;
    
    srand(time(NULL));
    
    printf ("_______________ Testes _______________\n\n");
    //N = rand() % 16;
    a1 = RandArvFromArray (v2, N);
    printf ("Primeira árvore de teste (%d elementos)\n", N);
    printTree (a1);
    
    printf ("altura = %d\n", altura (a1));
    printf ("numero de folhas: %d\n", nFolhas (a1));
    printf ("Nodo mais à esquerda: ");
    r = maisEsquerda (a1);
    if (r==NULL) printf ("(NULL)\n"); else printf ("%d\n", r->valor);
    printf ("Elementos no nivel 3_______\n");
    imprimeNivel (a1, 3);
    printf ("\n___________________________\n");

    printf ("procura de 2: %d\n", procuraE (a1, 2));
    printf ("procura de 9: %d\n", procuraE (a1, 9));
    
    freeABin (a1);
    
    //N = rand() % 16;
    a2 = RandArvFromArray (v1, N);
    printf ("\nSegunda árvore de teste (%d elementos)\n", N);
    printTree (a2);
    
    printf ("procura de 9: ");
    r = procura (a2, 9);
    if (r==NULL) printf ("(NULL)\n"); else printf ("%d\n", r->valor);   
    printf ("procura de 2: ");
    r = procura (a2, 2);
    if (r==NULL) printf ("(NULL)\n"); else printf ("%d\n", r->valor);   
    printf ("nível do elemento 2: %d\n", nivel (a2, 2));
    printf ("nível do elemento 9: %d\n", nivel (a2, 9));
    printf("Imprime até menor que 20:\n");
    imprimeAte (a2, 20);

    freeABin (a2);

    printf ("\n\n___________ Fim dos testes ___________\n\n");
    return 0;

    return 0;
}