#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 50

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

// Faz print de uma lista
void printList(LInt l) {
    if (l != NULL) {
        printf("[ ");
        while(l != NULL) {
            printf("%d ", l->valor);
            l = l->prox;
        }
        printf("]\n");
    }
}

// Cria uma lista de um dado tamanho
LInt makeLInt (int tamanho) {
    if (tamanho == 0) return NULL;

    int num;
    LInt new = malloc(sizeof(struct lligada));

    printf("Insere um valor: ");
    scanf("%d",&num);

    new->valor = num;
    new->prox = makeLInt(tamanho - 1);

    return new;
}

// Cria uma lista circular de um dado tamanho
LInt getLIntCirc(int len) {

    LInt list = NULL;
    LInt prev = NULL;

    for(int i = 0; i < len; i++) {

        LInt new = malloc(sizeof(struct lligada));
        // Guardar o inicio da lista com 'list'
        if (list == NULL) list = new;
        if (prev != NULL) prev->prox = new;

        int num;
        printf("Insere um valor: ");
        scanf("%d",&num);

        new->valor = num;
        prev = new; // atualiza o pointer
    }
    prev->prox = list; // de modo a ficar uma lista circular
    return list;
}

// Retorna o tamanho de uma lista
int length(LInt l) {
    int count = 0;
    while (l != NULL) {
        count++;
        l = l->prox;
    }   
    return count;
}

// 1º Verifica-se se a cabeça da lista é NULL, se sim a lista é vazia e faz-se return;
// 2º Guarda-se a cabeça da lista numa variável auxiliar, e faz-se com que aponte para o próximo node
// 3º Já se pode fazer free da cabeça da lista de modo seguro
// 4º Repetir os passos anteriores até a cabeça ser NULL
void freeL(LInt l) {
    LInt aux;
    while(l != NULL) {
        aux = l;
        l = l->prox;
        free(aux);
    }
    return;
}

// Inverte uma lista (sem criar uma nova lista)
LInt reverseL (LInt l) {
    LInt prev = NULL;
    LInt current = l;
    LInt prox;

    while(current != NULL) {
        // Guardar o próximo
        prox = current->prox;
        // O próximo do node atual passa a ser o node anterior
        current->prox = prev;
        // Mover os pointers uma posição à frente
        prev = current;
        current = prox;
    }
    // valor do current antes de ser NULL
    l = prev;
    return l;
}

// Insere ordenadamente um dado valor numa lista ordenada
void insertOrd(LInt *l, int x) {
    LInt ant = NULL;
    
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;

    while ((*l) != NULL && (*l)->valor < x) {
        ant = (*l);
        l = &((*l)->prox);
    }

    if (ant == NULL) {
        new->prox = (*l);
        (*l) = new;
    } else {
        new->prox = (*l);
        ant->prox = new;
    }
}

// Retira um valor de uma lista ordenada
void removeOneOrd(LInt *l, int x) {
    LInt ant = NULL;
    while ((*l) != NULL && (*l)->valor < x) {
        ant = (*l);
        l = &((*l)->prox); // nao modifica a lista; modifica para onde aponta
    } 
    
    if (ant == NULL) {
        (*l) = (*l)->prox; // modifica a cabeça da lista
    } else {
        ant->prox = (*l)->prox;
    }
}

// Junta duas listas ordenadas (a e b) numa única lista ordenada (r)
void merge (LInt *r, LInt l1, LInt l2) {

    while (l1 != NULL && l2 != NULL) {
        if (l1->valor <= l2->valor) {
            *r = l1; // cabeça da lista igual à cabeça da lista de l1
            l1 = l1->prox; // a cabeça da lista passa a ser uma posição à frente
        } else {
            *r = l2;
            l2 = l2->prox;
        }
        r = &(*r)->prox; // r passa a conter o endereço do proximo
    }

    if (l1 != NULL) // se l1 nao for nulo ent é porque l2 é nulo ent o que está em l1 passa a ser o ultimo elemento
        *r = l1;
    else
        *r = l2; // o caso contrario
}

// Dada uma lista ligada e um inteiro x, parte a lista em duas
// Uma com os elementos menores do que x e a outra com os restantes
void splitQS (LInt l, int x, LInt *mx, LInt *Mx) {

    LInt ant = NULL;
    while (l != NULL && l->valor < x) {
        *mx = l;
        l = l->prox;
        mx = &((*mx)->prox);
    }

    *mx = NULL;
    *Mx = l;
}

// Passei a 9 à frente (já foi feita antes)

// int removeAll (LInt *l, int x) {
//     int count = 0;
//     LInt ant = NULL;

//     while ((*l) != NULL) {
//         if ((*l)->valor == x && ant != NULL && (*l)->prox != NULL) {
//             ant->prox = (*l)->prox;
//             count++;
//         } else if ((*l)->valor == x && ant != NULL && (*l)->prox == NULL) {
//             ant->prox = NULL;
//             count++;
//         } else if ((*l)->valor == x && ant == NULL) {
//             (*l) = (*l)->prox;
//             count++;
//         }
        
//         if ((*l)-> prox != NULL) 
//             ant = (*l);
//         l = &((*l)->prox);
//     }

//     return count;
// }

// Remove todas as ocorrências de um dado inteiro de uma lista, retornando o número de células removidas
int removeAll(LInt *l, int x) {
    int count = 0;
    LInt aux;
    while(*l != NULL) {
        if ((*l)->valor == x) {
            aux = *l;
            (*l) = (*l)->prox; // modifica a lista
            count++;
        } else 
            l = &(*l)->prox;   // não modifica a lista
    }
    free(aux);
    return count;
}

// Função auxilar da função removeDups que verifica se um elemento está num array
int verifica(int arr[], int x) {
    int flag = 0;
    for (int i = 0; i <= MAX && flag == 0; i++) {
        if (arr[i] == x)
            flag = 1;
    }
    return flag;
}

// Remove os valores repetidos de uma lista
int removeDups (LInt *l) {
    int arr[MAX];  
    int i = 0, count = 0; 

    while((*l) != NULL) {
        if (verifica(arr, (*l)->valor) == 0) {
            arr[i] = (*l)->valor;
            l = &((*l)->prox);
            i++;
        } else {
            LInt aux = *l;
            (*l) = (*l)->prox;
            free(aux);
            count++;
        }
    }
    return count;
}

// Encontra o maior valor de uma lista
int find_maiorL (LInt l) {
    int maximo = 0;
    while (l != NULL) {
        if (l->valor > maximo)
            maximo = l->valor;
        l = l->prox;        
    }
    return maximo;
}

// Remove o maior elemento (a primeira ocorrência) de uma lista, retornando o valor desse elemento
int removeMaiorL (LInt *l) {
    int maximo = find_maiorL(*l);

    while((*l) != NULL) {
        if ((*l)->valor == maximo) {
            LInt aux = (*l);
            (*l) = (*l)->prox;
            free(aux);
        } else {
            l = &((*l)->prox);
        }
    }
    return maximo;
}

// Remove o último elemento da lista
void init(LInt *l) {

    LInt ant = NULL;

    if ((*l) == NULL) return;
    
    while((*l)->prox != NULL) {
        ant = (*l);
        l = &((*l)->prox);
    }
    
    free(*l);
    *l = NULL;
}

// Acrescenta um elemento ao fim da lista
void appendL (LInt *l, int x) {

    LInt ant = NULL, new = malloc(sizeof(struct lligada));
    new->valor = x,
    new->prox = NULL;

    while((*l) != NULL) {
        ant = (*l);
        l = &((*l)->prox);
    }

    if (ant != NULL)        // lista nao vazia
        ant->prox = new;
    else                    // lista vazia
        (*l) = new;
}

// Acrescenta a lista b à lista a
// Easy one
void concatL2 (LInt *a, LInt b) {

    while((*a) != NULL) {
        a = &((*a)->prox);
    }

    *a = b;
}

// nao me lembro do que fiz aqui, mas resulta
void concatL(LInt *a, LInt b) {
    LInt aux = NULL;
    while ((*a) != NULL) {
        a = &((*a)->prox);
    }

    while (b != NULL) {
        (*a) = b;
        b = b->prox;
        a = &((*a)->prox);
    }
}

LInt cloneL(LInt l) {
    
    if (l == NULL) return NULL; // verifica se a lista é vazia

    LInt new = malloc(sizeof(struct lligada));      // cria uma nova lista
    new->valor = l->valor;                          // dá valor à cabeça da lista
    LInt aux = new;                                 // de modo a se poder usar 'new' no return

    l = l->prox;                                    // avança para o proximo node da lista l
    while(l != NULL) {
        aux->prox = malloc(sizeof(struct lligada)); // cria espaço para o novo node na nova lista
        aux = aux->prox;
        aux->valor = l->valor;
        l = l->prox;
    }
    aux->prox = NULL;                               // marca o fim da nova lista com NULL

    return new;                                     // return à cabeça da lista
}

LInt cloneL2(LInt l) {

    LInt list = NULL, temp = NULL;

    while(l != NULL) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = NULL;

        if (list == NULL) list = temp = new;
        else temp = temp->prox = new;
        l = l->prox;
    }
    return list;

}

LInt cloneL3 (LInt l) {

    if (l != NULL) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = cloneL(l->prox);
        return new;
    } else 
        return NULL;

}


// Cria um clone da inversão de uma dada lista
LInt cloneRev(LInt l) {
    
    LInt list = NULL;

    while(l != NULL) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = list;   // é como se ficasse a apontar para o anterior, formando uma lista ao contrário
        list = new;         // esta declaração não afeta o valor anterior (new->prox)!! 
        l = l->prox;        // avança a cabeça da lista
    }

    return list;
}

// Elimina e liberta os elementos para além de um dado n-ésimo elemento
int take(int x, LInt *l) {

    int comprimento = 0;
    while ((*l) != NULL && x > 0) {
        l = &((*l)->prox);
        comprimento++;
        x--;
    }

    if ((*l) != NULL) {
        while((*l) != NULL) {
            LInt aux = (*l);
            (*l) = (*l)->prox;
            free(aux);
        }
    }

    (*l) = NULL;
    return comprimento;
}

int take2 (int n, LInt *l) {
    LInt aux, prev;
    int size = 0;
    while ((*l) != NULL && n > 0) {
        prev = (*l);
        l = &((*l)->prox);
        size++;
        n--;
    }
    if ((*l) != NULL) {
        prev->prox = NULL;
        while ((*l) != NULL) {
            aux = (*l);
            (*l) = (*l)->prox;
            free(aux);
        }
    }

    return size;
}

// Remove (e liberta o respetivo espaço) os n primeiros elementos
int drop(int x, LInt *l) {

    int count = 0;
    LInt aux = NULL;

    while((*l) != NULL && x > 0) {
        aux = (*l);
        (*l) = (*l)->prox;
        free(aux);
        count++;
        x--;
    }    
    return count;
}

// Dada uma lista circular dá como resultado o endereço do elemento da lista que está N posições à frente
LInt Nforward(LInt l, int N) {
    for(int i = 0; i < N; i++) {
        l = l->prox;
    }
    return l;
}

// Preenche um array a partir de uma lista
int listToArray(LInt l, int v[], int N) {

    int count = 0;
    while(l != NULL && N > 0) {
        v[count] = l->valor;
        l = l->prox;
        count++;
        N--;
    }
    return count;
}

int listToArray2 (LInt l, int v[], int N) {
    int i = 0;
    while(l != NULL && N > 0) {
        v[i] = l->valor;
        l = l->prox;
        i++;
        N--;
    }
    return i;
}

// Cria uma lista a partir de um array (duas versões)
LInt arrayToList2 (int v[], int N) {

    int i = 0;
    LInt new = malloc(sizeof(struct lligada));
    new->valor = v[i];
    LInt aux = new;
    i++;

    while(i < N) {
        aux->prox = malloc(sizeof(struct lligada));
        aux = aux->prox; 
        aux->valor = v[i];
        i++;
    }
    aux->prox = NULL;

    return new;
}

LInt arrayToList (int v[], int N) {

    int i = 0;
    LInt head = NULL, current = NULL;

    while(i < N) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = v[i];
        new->prox = NULL;

        if (head == NULL) {
            head = new;         // list fica com a cabeça da nova lista e o temp vai criando o resto da lista
            current = new;
        } else {
            current->prox = new;
            current = current->prox;    // assim o temp->prox é como se tornasse em new->prox na proxima iteraçao
        }                               // caso i chegue a N, new passa a ser o fim da lista, que está correto
        i++;
    }
    return head;

}

LInt arrayToList3 (int v[], int N) {

    int i = 0;
    LInt list = NULL, temp = NULL;

    while (N > 0) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = v[i];
        new->prox = NULL;

        if (list == NULL) {
            list = new;
            temp = new;
        } else {
            temp->prox = new;
            temp = new;
        }

        i++;
        N--;

    }
    return list;
}

// Dada uma lista de inteiros, constroi uma nova lista de inteiros contendo as somas acumuladas da lista original
LInt somasAcL (LInt l) {

    int acumulador = 0;
    LInt head = NULL, current = NULL;

    while (l != NULL) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor + acumulador;
        new->prox = NULL;
        acumulador += l->valor;

        if (head == NULL) {
            head = new;
            current = new;
        } else {
            current->prox = new;
            current = current->prox;
        }

        l = l->prox;
    }

    return head;
}

// a forma correta é a de cima ^
// Da maior soma até à mais pequena
// Exemplo de output: [ 1 2 3 4 ] -> [ 10 9 7 4 ]
LInt somasAcL2 (LInt l) {

    LInt temp = NULL, aux = NULL, list = NULL;
    int acc;
    while (l != NULL) {
        temp = l;
        acc = 0;
        while (temp != NULL) {
            acc += temp->valor;
            temp = temp->prox;
        }

        LInt new = malloc(sizeof(struct lligada));
        new->valor = acc;
        new->prox = NULL;

        if (list == NULL) {
            list = new;
            aux = new;
        } else {
            aux->prox = new;
            aux = new;
        }

        l = l->prox;
    }

    return list;
}

// Dada uma lista ordenada de inteiros, elimina e liberta todos os valores repetidos
void remreps (LInt l) {
    if (l != NULL) {
        while(l->prox != NULL) {
            if (l->prox->valor == l->valor) {
                LInt temp = l->prox;
                l->prox = (l->prox)->prox;      // modifica o pointer
                free(temp);
            } else 
                l = l->prox;
        }
    }
}

// Errado
// LInt rotateL (LInt l) {
//     if (l != NULL) {
//         LInt aux;
//         LInt head = l;
//         head->prox = NULL;

//         LInt inicio = l;
//         while (l->prox != NULL) {
//             aux = l;
//             l = l->prox;
//         } 
//         l->prox = inicio;
//         inicio->prox = NULL;
//         return head;
//     }
//     return NULL;
// }

// Coloca o primeiro elemento de uma lista no fim
// Não deve alocar nem libertar memória
LInt rotateL (LInt l) {
    
    if (l == NULL || l->prox == NULL) return l;

    LInt temp = l;
    LInt head = l->prox;

    while (temp->prox != NULL) {       // utiliza-se uma copia do pointer original para navegar ate ao final da lista
        temp = temp->prox;
    }

    temp->prox = l;                    // igual ao pointer original para o primeiro elemento da lista
    (temp->prox)->prox = NULL;         // modifica o pointer de modo a nao ficar uma lista circular

    return head;                       // equivale ao inicio da nova lista
}

// Não resultou:
// LInt parte (LInt l) {
    
//     LInt aux = l;
//     LInt head = NULL;
//     LInt temp = NULL;
//     LInt ant;

//     while(l != NULL ) {
//         if (l->valor % 2 == 0) {

//             if (head == NULL) {
//                 head = l;
//                 temp = l;
//             } else {
//                 temp->prox = l;
//                 temp = temp->prox;
//             }

//             if (l->prox != NULL)
//                 *l = *(l->prox);
//             else
//                 (ant->prox) = NULL;

//         }

//         l = l->prox;
//         ant = l;
//     }

//     return head;
// }

// Parte uma lista l em duas: na lista l ficam apenas os elementos das POSIÇÕES (antes tinha lido mal) ímpares;
// na lista resultante ficam os restantes elementos

// esta está mal no codeboard pelos vistos (dá segmentation fault - num dos testes provavelmente)
LInt parte2 (LInt l) {

    LInt head    = NULL;
    LInt current = NULL;

    while (l != NULL && l->prox != NULL) {

        if (head == NULL) {
            head = l->prox;                 // a lista ficará apenas com os elementos nas posiçoes ímpares, daí o l->prox
            current = l->prox;
        } else {
            current->prox = l->prox;
            current = current->prox;
        }

        l->prox = l->prox->prox;            // avança um elemento - o elemento na posição ímpar, alterando o pointer
        l = l->prox;
    }

    current->prox = NULL;                   // termina a lista
    return head;
}

// VERSAO CORRETA
// Com testes corretos no codeboard
LInt parte (LInt l) {
    LInt list = NULL;
    LInt temp = NULL;

    while (l != NULL && l->prox != NULL) {

        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->prox->valor;
        new->prox = NULL;

        if (list == NULL) {
            list = new;
            temp = new; 
        } else {
            temp->prox = new;
            temp = new;
        }

        l->prox = l->prox->prox;
        l = l->prox;
    }
    return list;
}

// PARTE 2
// ÁRVORES BINÁRIAS

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

// (a função não é minha, é da RisinFisan)
// Cria uma árvore binária
ABin getBTree() {
    ABin new = malloc(sizeof(struct nodo));
    int num;
    printf("Valor central: ");
    scanf("%d",&num);
    new->valor = num;
    printf("(%d) Valor à esquerda? (0 - não ; 1 - sim) ", new->valor);
    scanf("%d",&num);
    if(num) new->esq = getBTree();
    else new->esq = NULL;
    printf("(%d) Valor à direita? (0 - não ; 1 - sim) ", new->valor);
    scanf("%d",&num);
    if(num) new->dir = getBTree();
    else new->dir = NULL;
    return new;
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

// Cria uma representação da árvore no terminal (mal feita :kermitSip:)
void printTree(ABin a) {
    for (int i = 0; i <= altura(a); i++) {
        imprimeLevel(a, i, i, altura(a), 0);
        printf("\n");
    }
}

// Free completo da árvore binária
void freeABin (ABin a) {
    if (a == NULL) return;
    freeABin(a->esq);
    freeABin(a->dir);
    free(a);
}

// Retorna a altura de uma árvore binária (versao 2)
int altura2 (ABin a) {
    if (a == NULL) return 0;
    if (altura(a->esq) > altura(a->dir))
        return 1 + altura(a->esq);
    return 1 + altura(a->dir);
}

// Retorna a altura de uma árvore binária (versao 3)
int altura3 (ABin tree) {
    if(tree == NULL) return 0;
    return 1 + (altura(tree->esq) > altura(tree->dir) ? altura(tree->esq) : altura(tree->dir));
}

// Retorna um clone de uma dada árvore
ABin cloneAB (ABin a) {
    if (a == NULL) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->valor = a->valor;
    new->esq = cloneAB(a->esq);
    new->dir = cloneAB(a->dir);
    return new;
}

// Inverte todas as ramificações de uma árvore binária
void mirror (ABin *a) {

    if ((*a) == NULL) return;

    ABin temp = (*a)->dir;
    (*a)->dir = (*a)->esq;
    (*a)->esq = temp;
    mirror(&((*a)->dir));
    mirror(&((*a)->esq));
}

// Cria uma lista ligada de inteiros a partir de uma travessia inorder de uma árvore binária
// Travessia *inorder* de uma árvore binária: 
void inorder(ABin a, LInt *l) {

    LInt new;
    if (a != NULL) {

        inorder(a->dir, l);                     // nao pode ser (a->esq) primeiro pois a lista será formada ao contrário

        new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = *l;                         // new fica no fim da lista
        *l = new;                               

        inorder(a->esq, l);
        
    }
}

// Cria uma lista ligada de inteiros a partir de uma travessia preorder de uma árvore binária

// num resulta
void preorderAux (ABin a, LInt *l) {

    if (a == NULL) return;
    LInt temp = NULL;

    LInt new = malloc(sizeof(struct lligada));
    new->valor = a->valor;
    new->prox = NULL;

    if (*l == NULL) {   
        *l = new;
        temp = new;
    } else {
        temp->prox = new;
        temp = new;
    }

    preorderAux(a->esq, &temp);
    preorderAux(a->dir, &temp);

}

void preorder(ABin a, LInt *l) {
    *l = NULL;
    preorderAux(a, l);
}

void preorder1(ABin a, LInt *l) {

    LInt new;

    if (a != NULL) { // normalmente seria este procedimento: criar node, recursivamente esquerda, recursivamente direita, repetir ate todos os nodes serem visitados
                     // no entanto, como a lista é formada ao contrário (visto q torna o trabalho mais fácil), tem de ser assim
                     
        preorder1(a->dir, l);
        preorder1(a->esq, l);

        new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = *l;
        *l = new;

    }
}

// Esta não funciona bem
// ideia: fazer um array de pointers e depois montar a lista a partir disso (:eyes:)
void preorder2(ABin a, LInt *l) {

    LInt new;
    LInt ant = NULL, head = NULL;

    if (a != NULL) {
        new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = new;
        new = (*l);

        preorder2(a->esq, l);
        preorder2(a->dir, l);
    }
}

void preorderAux2 (ABin a, LInt *l) {

    if (a == NULL) return;

    preorderAux2(a->dir, l);
    preorderAux2(a->esq, l);

    LInt new = malloc(sizeof(struct lligada));
    new->valor = a->valor;
    new->prox = (*l);
    (*l) = new;

}

void preorder3(ABin a, LInt *l) {
    *l = NULL;
    preorderAux2(a, l);
}

// Cria uma lista ligada de inteiros a partir de uma travessia posorder de uma árvore binária
void posorder (ABin a, LInt *l) {

    LInt new;

    if (a != NULL) {

        new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = *l;
        *l = new;

        posorder(a->dir, l);
        posorder(a->esq, l);
    }
}

// Calcula o nível (menor) a que um elemento está numa árvore binária (-1 caso não existe)
int depth (ABin a, int x) {

    if (a == NULL) return -1;
    if (a->valor == x) return 1;

    int esq = depth(a->esq, x);
    int dir = depth(a->dir, x);

    // muitos ifs desnecessarios hehehehehehehehhehe
    if (esq == -1) 
        if (dir == -1)
            return -1;
        else
            return 1 + dir;
    else
        if (dir == -1)
            return 1 + esq;
        else 
            return (esq < dir ? 1 + esq : 1 + dir);

}

// void prune (ABin *a) {

//     if((*a) == NULL) return;

//     if (*a != NULL) {
//         if ((*a)->esq != NULL)
//             prune(&(*a)->esq);
//         if ((*a)->dir != NULL)
//             prune(&(*a)->dir);
//         free(*a);
//     }
// }

// int pruneAB (ABin *a, int x) {

//     if ((*a) != NULL) {

//         if (x <= 0) {
//             prune(&(*a)->esq);
//             (*a)->esq = NULL;
//             prune(&(*a)->dir);
//             (*a)->dir = NULL;
//         } else {
//             return (1 + pruneAB(&(*a)->esq, x-1));
//             return (1 + pruneAB(&(*a)->dir, x-1));
//         }
//     }
//     return 0;

// }

// Remove (libertando o espaço respetivo) todos os elementos da árvore 
int pruneAB (ABin *a, int l) {
    int n;
    if(!(*a)) return 0;
    
    if(l == 0) { // só começa a remover quando chega a 0
        n = 1 + pruneAB(&((*a)->esq),0) + pruneAB(&((*a)->dir),0);
        free(*a);
        (*a) = NULL; // passa a ser um null pointer
    } else { // não remove estes elementos
        n = pruneAB(&((*a)->esq),l - 1) + pruneAB(&((*a)->dir),l - 1);
    }
    
    return n; // faz return do estado do acumulador
}

// Retorna 1 caso as duas árvores sejam iguais
// Retorna 0 caso as duas árvores sejam diferentes
int iguaisAB (ABin a, ABin b) {
    
    if ((a == NULL && b != NULL) || (a != NULL && b == NULL)) return 0;
    if (a == NULL && b == NULL   || a == b ) return 1;

    if (a->valor != b->valor) return 0;
    if (a->valor == b->valor) {
        int esq = iguaisAB(a->esq, b->esq);
        int dir = iguaisAB(a->dir, b->dir);

        if (esq == dir)
            return 1;
        else 
            return 0;
    }

}

int iguaisAB2 (ABin a, ABin b) {

    if ((a == NULL && b == NULL)) return 1;
    if ((a == NULL && b != NULL) || (a != NULL && b == NULL)) return 0;

    if (a->valor != b->valor) return 0;
    return (iguaisAB2(a->esq, b->esq) && iguaisAB2(a->dir, b->dir));

}

// FUNÇÕES PARA UM MINI-TESTE

//INICIO

int calcula(LInt l) {
    int pos = 0, r = 0, quantidade = 2, size = 0;
    l = l->prox;
    pos++;
    while (quantidade > 0 ) {
        if (pos % 2 == 1) { //impar
            r += l->valor;
            l = l-> prox;
            pos++;
            quantidade--;
            }
        else { //par
            pos++;
            l = l->prox;
        }
    }
    return r;
}

ABin procuraAux(ABin a, int x) {

    ABin new;
    if (a != NULL) {

        procuraAux(a->esq, x);                     

        if (x == 0) {
            return a;                     
        }
        procuraAux(a->dir, x+1);
    }
}

ABin procura3(ABin a) {
    return procuraAux(a, 2);
}

ABin criaAux(int x) {

    ABin new = NULL;
    if (x % 2 == 0 && x != 0) {
        new = malloc(sizeof(struct nodo));
        new->valor = x;
        new->dir = NULL;
        new->esq = criaAux((x/2));

    } else if (x % 2 == 1 && x != 0) {
        new = malloc(sizeof(struct nodo));
        new->valor = x;
        new->esq = NULL;
        new->dir = criaAux((x/2));
    } 

    return new;
}

ABin procuraAAux(ABin a, int x) {

    if (a == NULL) return NULL;
    if (x == 0) {

        return a;
    } 
    procuraAAux(a->esq, x);
    x--;
    procuraAAux(a->dir, x);

}

static int global = 0;

ABin procura(ABin a) {
    ABin ret = NULL;
    if (a == NULL)
        return NULL;
    if (global == 3) ret = a;
    else {
        global++;
        ret = procura(a->esq);
        if (ret == NULL)
            ret = procura(a->dir);
    }
    return ret;
}

ABin cria() {
    return criaAux(34);
}

LInt procura2(LInt l) {

    LInt aux = l;
    int tamanho = 0;
    while (aux != NULL) {
        tamanho++;
        aux = aux->prox;
    }
    if (tamanho < 4) return NULL;
    int pos = tamanho - 4;
    int i = 0;
    aux = l;
    while (i < pos) {
        aux = aux->prox;
        i++;
    }
    //aux->prox = NULL;
    return aux;
}

// FIM DAS QUESTOES DO MINI-TESTE

// Constrói uma lista com os valores dos elementos que estão armazenados na árvore ao nível n
void nivelLAux (ABin a, LInt *l, int n) {
    if (n > 0 && a != NULL) {
        if (n == 1) {
            LInt new = malloc(sizeof(struct lligada));
            new->valor = a->valor;
            new->prox = (*l);
            (*l) = new;
        } else {
            nivelLAux(a->dir, &(*l), n-1);
            nivelLAux(a->esq, &(*l), n-1);
        }
    }
}

LInt nivelL (ABin a, int n) {
    LInt l = NULL;
    if (n > 0) 
        nivelLAux(a, &l, n);
    return l;
}


// ABin removeMenor (ABin *a) {

//     ABin pt = *a; ant = NULL;
//     while (pt->esq != NULL) {
//         ant = pt;
//         pt = pt->esq;
//     }

//     if (ant == NULL) (*a) = pt->dir;
//     else ant->esq = pt->dir;

//     return pt;

// }


// Preenche um vetor v com os elementos de a que se encontram no nível n
// A função retorna o número de posições preenchidas do array
// int nivelV (ABin a, int n, int *v) {
//     if (a != NULL && n > 0) {
//         if (n == 1) {
//             *v = a->valor;
//             return 1;
//         } else {
//             int e = nivelV(a, n-1, v);
//             int d = nivelV(a, n-1, v+e);
//             return (e + d);
//         }
//     } else 
//         return 0;
// }

int nivelV (ABin a, int n, int *v){
    if(a == NULL || n < 1) return 0;
    if(n == 1){
        *v = a->valor;
        return 1;
    }

    int e = nivelV(a->esq, n-1, v);
    int d = nivelV(a->dir, n-1, v+e);

    return e+d;
}

// Dada uma árvore a, preenche o array v com os elementos da árvore segundo uma travessia inorder
// A função deve preenche no máximo N elementos e retorna o número de elementos preenchidos
int dumpABin(ABin a, int *v, int N) {

    if(a == NULL || N < 1) return 0;

    int e = dumpABin(a->esq, v, N);

    *(v + e) = a->valor;
    N = N - e - 1;

    int d = dumpABin(a->dir, v+e+1, N);
    return (e+d+1);

}

// Dada uma árvore de inteiros, calcula a ÁRVORE das somas acumuladas dessa árvore
// A árvore deve ter a mesma forma da árvore recebida como argumento 
// e em cada nodo deve conter a soma dos elementos da sub-árvore que aí se inicia
ABin somasAcA (ABin a) {
    if (a == NULL) return NULL;

    ABin new = malloc(sizeof(struct nodo));
    new->esq = somasAcA(a->esq);
    new->dir = somasAcA(a->dir);
    
    if (new->dir != NULL && new->esq != NULL) 
        new->valor = a->valor + new->dir->valor + new->esq->valor;
    else if (new->dir != NULL) 
        new->valor = a->valor + new->dir->valor;
    else if (new->esq != NULL) 
        new->valor = a->valor + new->esq->valor;
    else 
        new->valor = a->valor;
        
    return new;
}

int contaFolhas (ABin a) {
    if (a == NULL) return 0;
    if (a->esq == NULL && a->dir == NULL) return 1;
    return (contaFolhas(a->esq) + contaFolhas(a->dir));
}

ABin cloneMirror (ABin a) {
    if (a == NULL) return NULL;


    ABin new = malloc(sizeof(struct nodo));
    new->valor = a->valor;
    new->esq = cloneMirror(a->dir);
    new->dir = cloneMirror(a->esq);
    return new; 

}

int main() {

    int op, size, elem;
    printf("\n______________________________\n");
    printf("\nIntroduza o número da questão:\n> ");
    scanf("%d", &op);
    printf("______________________________\n\n");

    switch (op) {

        case -3: {

            ABin a1 = getBTree();
            printTree(a1);
            ABin a2 = procura(a1);
            printTree(a2);
            freeABin(a1);
            break;

        }
        case -2: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            LInt l2 = procura2(l1);
            printList(l2);
            break;

        } 
        case -1: {

            ABin a1 = cria();
            printTree(a1);
            break;            

        }
        case 0: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("A soma dos elemtos da lista nas posições ímpares é: %d\n", calcula(l1));
            printf("\n______________________________\n\n");
            freeL(l1);
            break;

        }
        case 1: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("O tamanho da lista é: %d\n", length(l1));
            printf("\n______________________________\n\n");
            freeL(l1);
            break;

        }
        case 2: {
            
            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("Lista depois de freeL:\n");
            freeL(l1);
            printList(l1);
            printf("\n______________________________\n\n");
            break;

        }
        case 3: {

            printf("Aplicada ao longo do código.\n");
            break;

        }
        case 4: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("Reversed List:\n");
            LInt rev = reverseL(l1);
            printList(rev);
            printf("\n______________________________\n\n");
            freeL(l1);
            break;

        }
        case 5: {   

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("Introduz um elemento para inserir na lista:\n> ");
            scanf("%d", &elem);
            insertOrd(&l1, elem);
            printList(l1);
            printf("\n______________________________\n\n");
            freeL(l1);
            break;

        }
        case 6: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("Introduz um elemento para remover da lista:\n> ");
            scanf("%d", &elem);
            removeOneOrd(&l1, elem);
            printList(l1);
            printf("\n______________________________\n\n");
            freeL(l1);
            break;
            
        }
        case 7: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("\n");
            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l2 = makeLInt(size);
            printf("\n");
            printList(l2);
            printf("\nMerged List: \n");

            LInt merged = malloc(sizeof(struct lligada));
            merge(&merged, l1, l2);
            printList(merged);
            printf("\n______________________________\n\n");
            freeL(merged);
            break;

        }
        case 8: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("Introduz um valor para dividir a lista:\n> ");
            scanf("%d", &elem);
            LInt *x = malloc(sizeof(struct lligada)), *y = malloc(sizeof(struct lligada));
            splitQS(l1, elem, x, y);
            printList(*x);
            printList(*y);
            printf("\n______________________________\n\n");
            freeL(l1);
            break;

        }
        case 10: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("Introduz um valor para ser removido da lista:\n> ");
            scanf("%d", &elem);
            printf("Quantidade de elementos iguais a %d removidos: %d\n", elem, removeAll(&l1, elem));
            printList(l1);
            printf("\n______________________________\n\n");
            freeL(l1);
            break;

        }
        case 11: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("Valores duplicados removidos da lista:\n");
            removeDups(&l1);
            printList(l1);
            printf("\n______________________________\n\n");
            freeL(l1);
            break;

        }
        case 12: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("Remove a primeira ocorrência do maior elemento da lista.\nValor desse elemento: %d\n", removeMaiorL(&l1));
            printList(l1);
            printf("\n______________________________\n\n");
            freeL(l1);

        }
        case 13: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("Remove o último elemento da lista.\n");
            init(&l1);
            printList(l1);
            printf("\n______________________________\n\n");
            freeL(l1);
            break;

        }
        case 14: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("Introduza um elemento para colocar no fum da lista:\n> ");
            scanf("%d", &elem);
            appendL(&l1, elem);
            printList(l1);
            printf("\n______________________________\n\n");
            freeL(l1);
            break;

        }
        case 15: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("\n");

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l2 = makeLInt(size);
            printf("\n");
            printList(l2);
            printf("\n");

            printf("Concat das duas listas:\n");
            concatL(&l1, l2);
            printList(l1);
            printf("\n______________________________\n\n");
            freeL(l1);
            break;

        }
        case 16: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("\nClone da lista:\n");

            LInt l2 = cloneL(l1);
            printList(l2);
            printf("\n______________________________\n\n");
            freeL(l1);
            freeL(l2);
            break;

        }
        case 17: {
            
            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("\nClone da lista com ordem reversa:\n");

            LInt l2 = cloneRev(l1);
            printList(l2);
            printf("\n______________________________\n\n");
            freeL(l1);
            break;

        }
        case 18: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("\nValor máximo encontrado na lista: %d\n", find_maiorL(l1));
            printf("\n______________________________\n\n");
            freeL(l1);
            break;

        }
        case 19: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("\nSeráo apagados os elementos para além do n-ésimo da lista.\n");   
            printf("Introduza um número n:\n> ");
            scanf("%d", &elem);

            printf("\nComprimento final da lista: %d\n", take(elem, &l1));
            printList(l1); 
            printf("\n______________________________\n\n");
            freeL(l1);
            break;                    

        }
        case 20: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printList(l1);
            printf("\nOs n primeiros elementos serão apagados e o respetivo espaço será libertado.\n");   
            printf("Introduza um número n:\n> ");
            scanf("%d", &elem);

            printf("\nNúmero de elementos removidos: %d\n", drop(elem, &l1));
            printList(l1); 
            printf("\n______________________________\n\n");
            freeL(l1);
            break;

        }
        case 21: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = getLIntCirc(size);
            printf("\n");
            // bad ideia to print a circular list
            //printList(l1);

            printf("Número de elementos a avançar:\n> ");
            scanf("%d", &elem);
            LInt l2 = Nforward(l1, elem);

            printf("Elemento inicial: %d\nElemento %d posições à frente: %d\n", l1->valor, elem, l2->valor);
            printf("\n______________________________\n\n");
            break;

        }
        case 22: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");
            printf("Introduza um número máximo para o array:\n> ");
            scanf("%d", &elem);
            
            int array[elem];
            printf("\nList to array.\nNúmero de elementos preenchidos: %d\n", listToArray(l1, array, elem));
            for (int i = 0; i < elem; i++) {
                printf("%d ", array[i]);
            }
            printf("\n______________________________\n\n");
            freeL(l1);
            break;

        }
        case 23: {

            printf("Introduza o tamanho do array:\n> ");
            scanf("%d", &size);
            printf("\n");

            int array[size];
            for (int i = 0; i < size; i++) {
                printf("Introduza um elemento: ");
                scanf("%d", &elem);
                array[i] = elem;
            }

            LInt l1 = arrayToList(array, size);
            printf("\n");
            printList(l1);
            printf("\n______________________________\n\n");
            freeL(l1);
            break;

        }
        case 24: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");

            printf("Lista com valores acumulados:\n");
            LInt l2 = somasAcL(l1);
            printList(l2);
            printf("\n______________________________\n");
            freeL(l1);
            freeL(l2);
            break;

        }
        case 25: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");

            printf("Remove duplicados numa lista ordenada:\n");
            remreps(l1);
            printList(l1);
            printf("\n______________________________\n");
            freeL(l1);
            break;

        }
        case 26: {

            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");

            printf("Coloca o primeiro elemento no fim da lista:\n");
            LInt l2 = rotateL(l1);
            printList(l2);
            printf("\n______________________________\n");
            freeL(l1);
            break;

        }
        case 27: {
            
            printf("Introduza um tamanho:\n> ");
            scanf("%d", &size);
            printf("\n");
            LInt l1 = makeLInt(size);
            printf("\n");

            printf("Lista apenas com os elementos das posições pares:\n");
            LInt l2 = parte(l1);
            printList(l2);

            printf("\nLista apenas com os elementos das posições ímpares:\n");
            printList(l1);
            printf("\n______________________________\n");
            freeL(l1);
            break;

        }
        case 28: {

            ABin a1 = getBTree();
            printf("\nAltura da árvore: %d\n", altura(a1));
            printTree(a1);
            freeABin(a1);
            break;

        }
        case 29: {

            ABin a1 = getBTree();
            printTree(a1);
            printf("\nClone da árvore:\n");
            ABin a2 = cloneAB(a1);
            printTree(a2);
            freeABin(a1);
            freeABin(a2);
            break;

        }
        case 30: {

            ABin a1 = getBTree();
            printTree(a1);
            printf("\nÁrvore invertida:\n");
            mirror(&a1);
            printTree(a1);
            freeABin(a1);
            break;

        }
        case 31: {

            ABin a1 = getBTree();
            LInt l1 = NULL;
            printTree(a1);
            inorder(a1, &l1);
            printList(l1);
            freeL(l1);
            freeABin(a1);
            break;

        }
        case 32: {

            ABin a1 = getBTree();
            LInt l1 = NULL;
            printTree(a1);
            preorder(a1, &l1);
            printList(l1);
            freeL(l1);
            freeABin(a1);
            break;

        }
        case 33: {

            ABin a1 = getBTree();
            LInt l1 = NULL;
            printTree(a1);
            posorder(a1, &l1);
            printList(l1);
            freeL(l1);
            freeABin(a1);
            break;

        }
        case 34: {

            ABin a1 = getBTree();
            printTree(a1);
            printf("Insira um número para procurar:\n");
            scanf("%d", &elem);
            printf("Nível mais baixo em que o número se encontra: %d\n", depth(a1, elem));
            freeABin(a1);
            break;

        }
        case 35: {

            printf("Função utilizada ao longo do código, it works.\n");
            break;

        }
        case 36: {

            ABin a1 = getBTree();
            printTree(a1);
            printf("Insira um número correspondente a um nível da árvore. Todos os nodos com nível superior serão removidos (libertando o espaço respetivo).\n");
            scanf("%d", &elem);
            printf("Número de elementos removidos: %d\n", pruneAB(&a1, elem));
            printTree(a1);
            freeABin(a1);
            break;

        }
        case 37: {

            ABin a1 = getBTree();
            printf("\n");
            ABin a2 = getBTree();
            if (iguaisAB(a1, a2) == 1)
                printf("\nAs árvores são iguais.\n");
            else
                printf("\nAs árvores são diferentes.\n");
            freeABin(a1);
            freeABin(a2);
            break;

        }
        case 38: {

            ABin a1 = getBTree();
            printf("\n");
            printf("Insira um numero correspondente a um nível da árvore.\n");
            scanf("%d", &elem);
            LInt l1 = nivelL(a1, elem);
            printTree(a1);
            printf("\n");
            printList(l1);
            free(l1);
            break;

        }
        case 39: {

            ABin a1 = getBTree();
            printTree(a1);

            printf("\nInsira um numero correspondente a um nível da árvore.\n");
            scanf("%d", &elem);

            int array[size];
            size = nivelV(a1, elem, array);

            printf("\nElementos do array: {");
            for (int i = 0; i < size; i++) {
                printf(" %d", array[i]);
                if ((i + 1) != size) printf(",");
            } printf(" }\n");
            freeABin(a1);
            break;

        }
        case 40: {

            ABin a1 = getBTree();
            printTree(a1);

            printf("\nInsira um numero máximo de elementos do array:\n> ");
            scanf("%d", &elem);

            int array[elem];
            size = dumpABin(a1, array, elem);

            printf("\nElementos do array: {");
            for (int i = 0; i < size; i++) {
                printf(" %d", array[i]);
                if ((i + 1) != size) printf(",");
            } printf(" }\n");
            freeABin(a1);
            break;

        } case 41: {

            // Está a dar segmentation fault (não sei porquê), mas passa nos testes do codeboard
            ABin a1 = getBTree();
            printTree(a1);

            printf("\nÁrvores das somas acumuladas da árvore anterior:\n");
            ABin a2 = somasAcA(a2);
            printTree(a2);
            freeABin(a1);
            freeABin(a2);
            break;
            
        }
        case 42: {

            ABin a1 = getBTree();
            printTree(a1);

            printf("\nNúmero de folhas: %d.\n", contaFolhas(a1));
            freeABin(a1);
            break;

        }
        case 43: {

            ABin a1 = getBTree();
            printTree(a1);
            ABin a2 = cloneMirror(a1);
            printTree(a2);
            freeABin(a1);
            freeABin(a2);
            break;

        }

        // As próximas questões são sobre árvores de procura, que (provavelmente) não saem no teste (LEI 2022)

        default:
            break;
    }

    return 0;
}