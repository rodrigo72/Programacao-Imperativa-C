#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

typedef struct stack {
    int valores[MAX];
    int tamanho;
} STACK, *SStack;

typedef struct staticQueue {
    int inicio;
    int tamanho;
    int valores[MAX];
} QUEUE, *SQueue;

void printStack(STACK* s) {
    printf("SP = %d\n",s->tamanho);
    printf("[");
    for(int i = 0; i < s->tamanho; i++) printf("%d%s", s->valores[i], i == s->tamanho - 1 ? "" : ", ");
    printf("]\n");
}

void printQueue(QUEUE *q) {
    printf("[");
    for(int i = 0; i < q->tamanho; i++) printf("%d%s",q->valores[q->inicio + i],i == q->tamanho - 1 ? "" : ", ");
    printf("] %d - start index\n",q->inicio);
}

void SinitStack (SStack s) {
    s->tamanho = 0;
}

int SisEmpty (SStack s) {
    return (s->tamanho == 0);
}

int Spush (SStack s, int x) {
    if (s->tamanho == MAX) return 1;
    s->valores[s->tamanho] = x;
    s->tamanho++;
    return 0;
}

int Spop (SStack s, int *x) {
    if (s->tamanho == 0) return 1;
    s->tamanho--;
    *x = s->valores[s->tamanho];
    return 0;
}

int Stop (SStack s, int *x) {
    if (s->tamanho == 0) return 1;
    int aux = s->tamanho - 1;
    *x = s->valores[aux];
    return 0;
}

void SinitQueue (SQueue q) {
    q->tamanho = 0;
}

int SisEmptyQ (SQueue q) {
    if (q->tamanho == 0) return 1;
    return 0;
}

int Senqueue (SQueue q, int x) {
    if (q->tamanho + q->inicio >= MAX) return 1;
    q->valores[q->tamanho + q->inicio] = x;
    q->tamanho++;
    return 0;
}

int Sdequeue (SQueue q, int *x) {
    if (q->inicio == MAX) return 1;
    *x = q->valores[q->inicio];
    q->inicio++;
    q->tamanho--;
    return 0;
}

int Sfront (SQueue q, int *x) {
    if (q->tamanho == 0) return 1;
    *x = q->valores[q->inicio];
    return 0;
}

typedef struct dinStack {
    int size; // guarda o tamanho do array valores
    int sp;
    int *valores;
} StackD, *DStack;

void printStack2(DStack s) {
    printf("SP = %d\n",s->sp);
    printf("[");
    for(int i = 0; i < s->sp; i++) printf("%d%s", s->valores[i], i == s->sp - 1 ? "" : ", ");
    printf("]\n");
}

void SinitStack2(DStack s) {
    s->sp = 0;
    s->size = 12;
    s->valores = malloc(s->size * sizeof(int));
}

void SDpush(DStack s, int x) {
    if (s->sp >= s->size) {
        s->valores = (int*)realloc(s->valores, 2 * s->size * sizeof(int));
        s->size *= 2;
    } 
    s->valores[s->sp] = x;
    s->sp++;
}

void SDpop(DStack s, int *x) {
    if (s->sp > 0) {
        s->sp--;
        *x = s->valores[s->sp];
    }
}

typedef struct dinQueue {
    int size; // guarda o tamanho do array values
    int front;
    int length;
    int *values;
} QueueD, *DQueue;

void printDQueue(DQueue q) {
    printf("[");
    for(int i = 0; i < q->length; i++) printf("%d%s",q->values[q->front + i],i == q->length - 1 ? "" : ", ");
    printf("] %d - start index\n",q->front);
}

void initDQueue(DQueue q) {
    q->length = 0;
    q->front = 0;
    q->size = 1;
    q->values = malloc(q->size * sizeof(int));
}

void pushDQueue(DQueue s, int x) {
    if (s->front + s->length >= s->size) {
        s->values = (int*)realloc(s->values, 2 * s->size * sizeof(int));
        s->size *= 2;
    }
    s->values[s->length + s->front] = x;
    s->length++;
}

void popDQueue(DQueue s) {
    if (s->length > 0) {
        s->front++;
        s->length--;
    }
}

int main() {
    
    int x;
    STACK s1;
    QUEUE *q1 = malloc(sizeof(QUEUE));
    StackD s;
    QueueD q; 

    printf("Digite (1) para testar a Stack ou (2) para testar a Queue.\nOu um número qualquer, talvez aconteça alguma coisa.\n");
    char c = getchar();

    if (c == '4') {
        initDQueue(&q);
        printf("Queue dinâmica inicializada.\n");
        printDQueue(&q);
        printf("----\n");

        printf("Insira um valor para inserir na queue:\n> ");
        scanf("%d", &x);
        pushDQueue(&q, x);
        printf("Insira outro valor para inserir na queue:\n> ");
        scanf("%d", &x);
        pushDQueue(&q, x);
        printDQueue(&q);
        printf("Elemento do inicio retirado.\n");
        popDQueue(&q);
        printDQueue(&q);

    } else if (c == '3') {
        SinitStack2(&s);
        printf("Stack dinâmica inicializada.\n");
        printStack2(&s);
        printf("----\n");

        printf("Insira um numero para inserir na stack:\n> ");
        scanf("%d", &x);
        SDpush(&s, x);
        printStack2(&s);
        printf("----\n");

        SDpop(&s, &x);
        printf("Elemento retirado: %d.\n", x);
        printStack2(&s);
        printf("----\n");

    } else if (c == '2') {
        SinitQueue(q1);
        printf("Queue inicializada.\n");
        if (SisEmptyQ(q1)) printf("A queue está vazia.\n");
        else printf("A queue não está vazia.\n");

        printQueue(q1);
        printf("\n");

        printf("Insira um número para inserir na queue:\n");
        scanf("%d", &x);
        if (Senqueue(q1, x) == 0) printf("Função Senqueue executada com sucesso.\n");
        else printf("Não foi possível executar a função Senqueue.\n");
        if (SisEmptyQ(q1)) printf("A queue está vazia.\n");
        else printf("A queue não está vazia.\n");

        printQueue(q1);
        printf("\n");

        printf("Insira um número para inserir na queue:\n");
        scanf("%d", &x);
        if (Senqueue(q1, x) == 0) printf("Função Senqueue executada com sucesso.\n");
        else printf("Não foi possível executar a função Senqueue.\n");
        if (SisEmptyQ(q1)) printf("A queue está vazia.\n");
        else printf("A queue não está vazia.\n");

        printQueue(q1);
        printf("\n");

        if (Sdequeue(q1, &x) == 0) printf("Função Sdequeue executada com sucesso. Elemento que estava no início %d.\n", x);
        else printf("Não foi possível executar a função Sdequeue.\n");

        printQueue(q1);
        printf("\n");

        if (Sfront(q1, &x) == 0) printf("Função Sfront executada com sucesso. Elemento que está no início: %d.\n", x);
        else printf("Não foi possível executar a função Sfront.\n");

        printQueue(q1);
        printf("\n");

    } else if (c == '1') {

        SinitStack(&s1);
        if (SisEmpty(&s1)) printf("A stack está vazia.\n");
        else printf("A stack não está vazia.\n");
    
        printStack(&s1);
        printf("\n");
    
        printf("Insira um número para inserir na stack:\n");
        scanf("%d", &x);
        if (Spush(&s1, x) == 0) printf("Foi possível fazer push.\n");
        else printf("Não foi possível fazer push.\n");
    
        if (SisEmpty(&s1)) printf("A stack está vazia.\n");
        else printf("A stack não está vazia.\n");
    
        printStack(&s1);
        printf("\n");
    
        if (Spop(&s1, &x) == 0) printf("Foi possível fazer pop.\nElemento que estava no topo da stack: %d.\n", x);
        else printf("Não foi possível fazer pop.\n");
    
        if (SisEmpty(&s1)) printf("A stack está vazia.\n");
        else printf("A stack não está vazia.\n");
    
        printStack(&s1);
        printf("\n");
    
        printf("Insira um número para inserir na stack:\n");
        scanf("%d", &x);
        if (Spush(&s1, x) == 0) printf("Foi possível fazer push.\n");
        else printf("Não foi possível fazer push.\n");
    
        printf("Insira um número para inserir na stack:\n");
        scanf("%d", &x);
        if (Spush(&s1, x) == 0) printf("Foi possível fazer push.\n");
        else printf("Não foi possível fazer push.\n");
    
        if (SisEmpty(&s1)) printf("A stack está vazia.\n");
        else printf("A stack não está vazia.\n");
    
        printStack(&s1);
        printf("\n");
    
        if (Stop(&s1, &x) == 0) printf("Foi possível fazer top.\nElemento que está no topo da stack: %d.\n", x);
        else printf("Não foi possível fazer top.\n");
    
        if (SisEmpty(&s1)) printf("A stack está vazia.\n");
        else printf("A stack não está vazia.\n");

        printStack(&s1);
        printf("\n");

        if (Spop(&s1, &x) == 0) printf("Função Pop executada.\nElemento que estava no topo da stack: %d.\n", x);
        else printf("Não foi possível executar a função pop.\n");

        if (Spop(&s1, &x) == 0) printf("Função Pop executada.\nElemento que estava no topo da stack: %d.\n", x);
        else printf("Não foi possível executar a função pop.\n");

        if (SisEmpty(&s1)) printf("A stack está vazia.\n");
        else printf("A stack não está vazia.\n");

        printStack(&s1);
        printf("\n");

    } else if (c == 'o' || c == 'h' || c == 'f' || c == 'a' || c == 'c' || c == 'i' || c == 'l')
        printf("\nOhhhhhhhhhhhh faaaaaaaaaaaaaaaaaaaaaaaacil\n");

    return 0;
}