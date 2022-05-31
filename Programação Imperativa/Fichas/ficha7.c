#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula *prox;
} * Palavras;

void libertaLista(Palavras l) {
    Palavras aux;
    while(l != NULL) {
        free(l->palavra);
        aux = l;
        l = l->prox;
        free(aux);
    }
}

int quantasP (Palavras l) {
    int c = 0;
    while(l != NULL) {
        c++;
        l = l->prox;
    }
    return c;
}

char *ultima (Palavras l) {
    char *ultima;
    while(l != NULL) 
        l = l->prox;
    ultima = l->palavra; 
    return ultima;
}

Palavras acrescentaInicio(Palavras l, char *p) {
    Palavras x;
    x = malloc(sizeof(struct celula));
    x->palavra = strdup(p);
    x->ocorr = 1;
    x->prox = l;
    return x;
}

Palavras acrescenta(Palavras l, char *p) {
    Palavras pt = l;
    while (pt != NULL) {
        if(!strcmp(p, pt->palavra)) {
            pt->ocorr++;
            break;
        }
        pt = pt->prox;
    }

    if (l != NULL) l = acrescentaInicio(l,p);
    else pt->ocorr++;

    return l;
}

Palavras acrescentaFim(Palavras l, char *p) {
    Palavras pt = l;
    while (pt != NULL) {
        pt = pt->prox;
    }
    
    Palavras x;
    x = malloc(sizeof(struct celula));
    x->palavra = strdup(p);
    x->ocorr = 1;
    x->prox = NULL;

    pt = x;
    return l;
}

struct celula *maisFreq(Palavras l) {
    struct celula *c; 
    int max = 0;

    while (l != NULL) {
        if (l->ocorr > max) {
            c = l;
            max = l->ocorr;
        }
        l = l->prox;
    }
    return c;
}

int main() {
    

    return 0;
}