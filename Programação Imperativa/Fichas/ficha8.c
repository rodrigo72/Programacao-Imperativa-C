#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

typedef LInt Stack;

Stack newStack (int x, Stack xs) {
    Stack r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x; r->prox = xs;
    }
    return r;
}

Stack newStack2 (int tamanho) {

    if (tamanho == 0) return NULL;

    int num;
    Stack new = malloc(sizeof(struct slist));

    printf("Insere um valor:\n> ");
    scanf("%d", &num);

    new->valor = num;
    new->prox = newStack2(tamanho - 1);

    return new;

}

void printStack(Stack s){
    Stack aux;

    printf("Stack:");
    for (aux = s; aux; aux = aux->prox) {
        printf(" %d", aux->valor);
    } printf("\n");

}

void initStack(Stack *s) {
    *s = NULL;
}

int SisEmpty(Stack s) {
    return (s == NULL);
}

// int push(Stack *s, int x) {
//     Stack new = malloc(sizeof(struct slist));
//     new->valor = x;
//     new->prox = *s;
//     *s = new;
//     if (new == NULL) return 1;
//     return 0;
// }

LInt newLInt(int x, LInt xs) {
    LInt r = malloc(sizeof(struct slist));

    if (r != NULL) {
        r->valor = x;
        r->prox = xs;
    }

    return r;
}

int push(Stack *s, int x) {
    LInt new = newLInt(x, (*s));

    if (new != NULL) {
        (*s) = new;
        return 1;
    }

    return 0;
}

int pop(Stack *s, int *x) {
    if (*s != NULL) {

        Stack aux = (*s);
        *x = (*s)->valor;
        *s = (*s)->prox;
        free(aux);

        return 0;
    } else 
        return 1;
}

// int pop(Stack *s, int *x) {
//     if ((*s) == NULL) {
//         return 1;
//     }

//     *x = (*s)->valor;
//     (*s) = (*s)->prox;

//     return 0;
// }

void top(Stack *s, int *x) {
    *x = (*s)->valor;
}

typedef struct queue {
    LInt inicio,fim;
} Queue;

void printQueue(Queue q) {
    LInt aux;

    printf("Queue: ");
    for (aux = q.inicio; aux; aux = aux->prox) {
        printf(" %d", aux->valor);
    }
    printf("\n");
}

void initQueue(Queue *q) {
    (*q).inicio = NULL;
    (*q).fim = NULL;
}

int QisEmpty (Queue *q) {
    return ((*q).inicio == NULL);
}

int enqueue (Queue *q, int x) {
    LInt new = malloc(sizeof(struct slist));
    new->valor = x;
    new->prox = NULL;

    if ((*q).inicio != NULL) {
        (*q).fim->prox = new;
        q->fim = new;
    } else {
        q->inicio = q->fim = new;
    }
}

void dequeue (Queue *q, int *x) {
    *x = q->inicio->valor;
    LInt aux = q->inicio;
    q->inicio = q->inicio->prox;
    free(aux);
}

void front (Queue q, int *x) {
    *x = q.inicio->valor;
}

Queue makeQueue(int tamanho) {
    int elem;
    Queue q;
    for (int i = 0; i < tamanho; i++) {
        printf("Introduz um valor:\n> ");
        scanf("%d", &elem);
        enqueue(&q, elem);
    } printf("\n");

    return q;
}

typedef LInt QueueC;

void initQueueC (QueueC *q) {
    (*q) = NULL;
}

int QCisEmpty (QueueC q) {
    return (q == NULL);
}

int enqueueC (QueueC *q, int x) {
    if ((*q) == NULL) {

        QueueC new = malloc(sizeof(struct slist));
        new->valor = x;
        new->prox = new;
        (*q) = new;

    } else {

        QueueC temp = (*q);
        while (temp != (*q)->prox) {
            q = &((*q)->prox);
        }

        QueueC new = malloc(sizeof(struct slist));
        new->valor = x;
        new->prox = temp;

        (*q)->prox = new;

    }
}

QueueC makeQueueC(int tamanho) {

    QueueC head = NULL;
    QueueC prev = NULL;

    if (tamanho == 0) return NULL;

    for(int i = 0; i < tamanho; i++) {

        QueueC new = malloc(sizeof(struct slist));
        // Guardar o inicio da queue com 'head'
        if (head == NULL) head = new;
        if (prev != NULL) prev->prox = new;

        int num;
        printf("Introduz um valor:\n> ");
        scanf("%d", &num);

        new->valor = num;
        prev = new; // atualiza o pointer

    }
    prev->prox = head; // de modo a ficar uma queue circular
    return head;
}

void printQueueC (QueueC q) {
    QueueC temp = q;

    if (q == NULL) {
        printf("Queue vazia.\n");
        return;
    }

    printf("QueueC: ");
    do {

        printf(" %d", temp->valor);
        temp = temp->prox;
        
    } while (q != temp);
    printf("\n");

}

// void dequeueC (QueueC *q, int *x) {

//     if ((*q) == NULL) return;
//     if ((*q)->prox == (*q)) {
//         (*q) = NULL;
//         return;
//     }

//     QueueC temp = (*q);
//     QueueC prev;
//     do {
//         prev = (*q);
//         q = &((*q)->prox);
//     } while ((*q) != temp);

//     prev = temp;

// }

void dequeueC(QueueC *q, int *x) {
    if ((*q) == NULL) {
        return;
    } if ((*q) == (*q)->prox) {
        (*q) = NULL;
    } else {

        QueueC temp = (*q);
        while (temp != (*q)->prox) {
            q = &((*q)->prox);
        }

        (*q)->prox = temp->prox;
        (*q) = temp;

    }
}

typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} *DList;

typedef struct {
    DList back, front;
} Deque;


int main() {

    int op, tamanho, elem;
    printf("Introduz o número da pergunta:\n> ");
    scanf("%d", &op);
    printf("\n");

    switch (op) {
        case 1: {

            printf("Introduz a quantidade de elementos que queres inserir na stack:\n> ");
            scanf("%d", &tamanho);
            printf("\n");
            Stack s = newStack2(tamanho);

            if (SisEmpty(s) == 0)
                printf("\nA stack não está vazia.\n");
            else 
                printf("\nA stack está vazia.\n");

            printStack(s);

            printf("\nIntroduz um elemento para inserir na stack:\n> ");
            scanf("%d", &elem);

            push(&s, elem);
            printf("\n");
            printStack(s);

            pop(&s, &elem);
            printf("\nPop do elemento '%d':\n", elem);
            printStack(s);
            top(&s, &elem);
            printf("\nValor do topo: '%d'.\n", elem);

            break;
        }
        case 2: {

            Queue q = makeQueue(3);

            if (QisEmpty(&q) == 0) 
                printf("A queue não está vazia.\n");
            else 
                printf("A queue está vazia.\n");

            printQueue(q);
            dequeue(&q, &elem);
            printf("Elemento retirado da queue: '%d'\n", elem);
            printQueue(q);
            
            front(q, &elem);
            printf("Elemento do inicio: '%d'\n", elem);

            break;

        }
        case 3: {
        
            QueueC qc = makeQueueC(3);
            printQueueC(qc);
            enqueueC(&qc, 7);
            enqueueC(&qc, 8);
            dequeueC(&qc, &elem);
            printQueueC(qc);

        }
        default:
            break;
    }
}