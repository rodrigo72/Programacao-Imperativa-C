#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000

int bitsUm (unsigned int bits) {
    int r = 0;
    while (bits > 0) {
        r += (bits % 2);
        bits /= 2;
    }
    return r;
}

int trailingZ (unsigned int n) {
    
    int r = 0;
    while (n > 0) {
        if (n % 2 == 0) r += 1;
        else return r;
        n /= 2;
    }
    return r;
}

int qDig (unsigned int n) {
    int r = 0;

    while (n > 1) {
        r += 1;
        n /= 10;
    }

    return r += 1;

}

char *strcatDoRudrigu (char str1[], char str2[]) {

    int size = strlen(str1);

    for (int i = 0; i < size && str2[i] != '\0'; i++)
        str1[size + i] = '\0';
}

char *strcpyDoRudrigu (char *dest, char source[]) {
    int i;
    for (i = 0; source[i] != '\0'; i++) 
        dest[i] = source[i];
    
    dest[i] = '\0';
}

int strcmpDoRudrigu(char s1[], char s2[]) {
    int r = 0;

    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        r += s1[i] - s2[i]; 
    }

    return r;
}

char *mystrstr (char haystack[], char needle[]) {

    if (haystack == NULL || needle == NULL) return NULL;

    for (; *haystack; haystack++) {
        char *h, *n;

        for (h = haystack, n = needle; *h && *n && (*h == *n); ++h, ++n) ;
        if (*n == '\0') return haystack;

    }
    return NULL; 
}

char *mystrstr2 (char *s1, char *s2) {
    int flag = 0, i;

    while (*s1 && strlen(s1) >= strlen(s2) && flag != 1) {

        i = 0;
        flag = 1;

        while (*(s2 + i) && flag != 0) {
            if (*(s1 + i) != *(s2 + i)) flag = 0;
            i++;
        }

        if (flag == 0)
            s1++;
    }

    if (flag == 0 && *s2) return NULL;
    return s1;
}

void mystrrev (char s[]) {
    int i, j;
    char temp;

    for (j = 0; s[j] != '\0'; j++);
    j -= 1;

    for (i = 0, j; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void mystrnoV (char s[]) {
    int i, size = 0, r = 0;
    for (size; s[size] != '\0'; size++);
    char arr[size-1];

    for (i = 0; s[i] != '\0'; i++) {
        if ((s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' 
        || s[i] == 'U' || s[i] == 'a'|| s[i] == 'e' || s[i] == 'i' 
        || s[i] == 'o' || s[i] == 'u'));
        else {
            arr[r] = s[i];
            r += 1;
        }
    }

    for (i = 0; i < r; i++) {
        s[i] = arr[i];
    }

    s[r] = '\0';
}

void truncW (char t[], int n) {
    int i, j = 0, size, counter = 0;
    for (size = 0; t[size] != '\0'; size++);
    char arr[size-1];

    for (i = 0; t[i] != '\0'; i++) {

        if (t[i] == ' ') {
            arr[j] = t[i];
            counter = 0;
            j++;
        } else 
            if (counter < n) {
                arr[j] = t[i];
                counter++;
                j++;
            }
    }

    for (i = 0; i < j; i++) {
        t[i] = arr[i];
    }
    t[j] = '\0';
}

char charMaisFreq(char s[]) {
    int i, max = 0, count[26], pos;
    char alfabeto[26];

    for (i = 0; i < 26; i++) {
        alfabeto[i] = 'a' + i;
    }

    alfabeto[26] = '\0';

    for (i = 0; i < 26; i++) {
        count[i] = 0;
    }

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z' )
            count[s[i] - 'a']++;
        if (s[i] >= 'A' && s[i] <= 'Z')
            count[s[i] - 'A']++;
    }
 
    for (i = 0; i < 26; i++) {
        if (count[i] > max) {
            max = count[i];
            pos = i;
        }
    }

    return alfabeto[pos];

}

int iguaisConsecutivos (char s[]) {
    int i, j = 0, max = 0, size = 0, r = 0;
    for (size; s[size] != '\0'; size++);
    size -= 1;
    int subs[size];

    for (i = 0; i < size+1; i++) subs[i] = 1;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == s[i+1]) subs[j]++;
        else j++;
    }

    for (i = 0; i < j; i++) 
        if (subs[i] > max) max = subs[i];

    return max;
}

int difConsecutivos (char s[]) {
    int i, j = 0, max = 0, size = 0, r = 0;
    for (size; s[size] != '\0'; size++);
    size -= 1;
    int subs[size];

    for (i = 0; i < size+1; i++) subs[i] = 1;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != s[i+1]) subs[j]++;
        else j++;
    }

    for (i = 0; i < j; i++) 
        if (subs[i] > max) max = subs[i];

    return max;
}

int maiorPrefixo (char s1[], char s2[]) {
    int count = 0;
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
        if (s1[i] == s2[i]) count++;
        else return count;
    
    return count;
}

int maiorSufixo (char s1[], char s2[]) {
    int i, j, count = -1;
    for(i = 0; s1[i]; i++);
    for(j = 0; s2[j]; j++);
    i--; j--;

    for (i,j; i >= 0 && j >= 0; i--, j--) 
        if (s1[i] == s2[j]) count++;
        else return count;
    return count;

}

int sufPref (char s1[], char s2[]) {
    int i, j = 0, r = 0;

    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[j]) {r++; j++;}
        else {r = 0; j = 0;}
    }
    return r;
}

int contaPal (char s[]) {
    // int size, count = 0, i, flag = 0; 
    // for(size = 0; s[size]; size++);
    // size -= 2;
    // for (i = 0; i < size; i++) 
    //     if (s[i] == ' ' && s[i+1] != ' ') flag = 1;
    //     else if (s[i] == ' ' && s[i + 1] == ' ');
    //          else if (flag == 1 && s[i] != ' ') {count++; flag = 0;};
    
    int i = 0, count = 0, size;
    for (size = 0; s[size] != '\0'; size++);
    size--;

    while (i < size) {
        while (s[i] == ' ') i++;
        if (s[i] != ' ' && i < size) count++;
        while(s[i] != ' ') i++;
    }
    return count;
}

int contaVogais (char s[]) {
    int i, count = 0; 
    
    for (i = 0; s[i] != '\0'; i++) 
        if ((s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' 
        || s[i] == 'U' || s[i] == 'a'|| s[i] == 'e' || s[i] == 'i' 
        || s[i] == 'o' || s[i] == 'u')) count++;

    return count;
}

void bubbleSort (int s[], int n) {
    int i, j, temp;

    for (i = 0; i < n; ++i) 
        for (j = 0; j < n - i - 1; ++j)
            if (s[j] > s[j+1]) {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
}

int contaPal2 (char s[]) {

    // versao que eu fiz: 
    int i = 0, size = 0, count = 0;
    for (size; s[size] != '\0'; size++);
    size--;

    while (i < size) {
        while (s[i] == ' ') i++;
        if (s[i] != ' ' && s[i+1] != '\0') count++; 
        while (s[i] != ' ') i++;
    }

    return count;
}

void tail(char* s) {
    while (*s) {
        *s = *(s+1); // muda o valor que o pointer guarda !
        s++;         // muda o pointer !
    }
}

int limpaEspacos (char x[]) {

    if (!(*x)) return 0;
    int i = 1;
    char prev = x[0];

    while (x[i]) {
        if (x[i] == ' ' && prev == ' ') {
            tail(x + i);
        } else {
            prev = x[i];
            i++;
        }
    }
    return i;
}

int stringElem (char *start, char *finish, char p) {
    while (*start != *finish) {
        if (*start == p) return 0;
    }
    return 1;
}


int difConsecutivos2 (char s[]) {

    if (*s) {

        int c = 0;
        int max = 0;
        char *back = s;
        char *front = s + 1;

        while (*front) {
            if (stringElem(back, front, *front) == 0) {
                c++;
                if (c > max) max = c;
            } else {
                back++;
                front = back;
                c = 1;
            }
            front++;
        }
        return max;
    }
    return 0;
}

int contida (char a[], char b[]) {

    int flag = 0;
    char *aux = b;
    while (*a) {
        aux = b;
        while (*aux) {
            if (*a == *aux) flag = 1;
            aux++;
        }

        if (flag != 1) return 0;

        a++;
    }
    return 1;
}

int palindrome (char s[]) {
    int size = strlen(s);
    for(int i = 0; s[i]; i++) 
        if(s[i] != s[size - 1 - i]) return 0;
    return 1;
}

int remRep (char x[]) {

    if (!(*x)) return 0;
    int i = 1;
    char prev = *x;

    while (x[i]) {
        
        if (x[i] == prev) 
            tail(x + i);
        else {
            prev = x[i];
            i++;
        }
    }
    return i;
}

int limpaEspacos2 (char x[]) {

    if (!(*x)) return 0;
    int i = 1;
    char prev = x[0];

    while (x[i]) {
        if (x[i] == ' ' && prev == ' ') {
            tail(x + i);
        } else {
            prev = x[i];
            i++;
        }
    }
    return i;
}

void merge (int r [], int a[], int b[], int na, int nb) {
    int i = 0, j = 0, k = 0;

    while (na + nb > k) {

        if ((a[i] < b[j] && i < na) || j >= nb) {
            r[k] = r[i];
            i++;
        } else {
            r[k] = b[j];
            j++;
        }
        k++;
    }
}

int crescente (int v[], int i, int j) {
    int flag = 1;
    while (i < j && flag != 0) {
        if (v[i] > v[i+1]) flag = 0;
        i++;
    }

    return flag;
}

int unionMSet(int N, int v1[N], int v2[N], int r[N]) {
    int len = 0;
    for (int i = 0; i < N; i++) {
        r[i] = v1[i] + v2[i];
        len += r[i];
    }
    return len;
}

int unionSet (int N, int v1[N], int v2[N], int r[N]) {
    int len = 0;
    for (int i = 0; i < N; i++) {
        r[i] = v1[i] || v2[i];
        len += r[i];
    }
    return len;
}

int main() {

    char* str1 = malloc(MAX * sizeof(char));
    char* str2 = malloc(MAX * sizeof(char));

    int op, num = 1, length, i = 0, j, k, max = 0, max2 = 0, soma = 0, media, array[MAX], temp;
    unsigned int bits, n;
    char *p;

    printf("Insira o número da questão:\n\n> ");
    scanf("%d", &op);
    while((getchar()) != '\n');
    printf("\n");

    switch(op) {

        case -3: {
            printf("Tail test:\n");
            printf("Introduza uma string:\n> ");
            fgets(str1, MAX, stdin);
            tail(str1);
            printf("%s\n", str1);
            break;
        }

        case -2: {
            printf("Exercício do miniteste.\nIntroduza uma string:\n\n> ");
            fgets(str1, MAX, stdin);
            printf("Número de palavras: %d\n", contaPal2(str1));
            break;
        }

        case -1: {
            printf("Bubble Sort.\nIntroduza uma sequência de inteiros acabada com 0:\n\n> ");
            while (num != 0) {
                scanf("%d", &num);
                if (num != 0) printf("> ");
                array[i] = num;
                i++;
            }
            length = i;


            bubbleSort(array, length);
            printf("\n> ");
            for (i = 0; i < length; i++) {
                printf("%d ", array[i]);
            }
            printf("\n");

            break;
        }

        case 1: {
            printf("Função que lê (usando a função scanf) uma sequência de números inteiros terminada com o número 0 e imprime na sequencia o maior elemento da sequencia.\nIntroduza a sequência:\n\n> ");
            while (num != 0) {
                scanf("%d", &num);
                if (num != 0) printf("> ");
                array[i] = num;
                i++;
            }
            length = i; 

            for (i = 0; i < length; i++) if (array[i] > max) max = array[i];
            printf("\nMaior elemento da sequência: %d\n", max);
            break;
        }

        case 2: {
            printf("Função que lê (usando a função scanf) uma sequência de números inteiros terminada com o número 0 e imprime no ecrã a média da sequência.\nIntroduza a sequência:\n\n> ");
            while (num != 0) {
                scanf("%d", &num);
                if (num != 0) printf("> ");
                array[i] = num;
                i++;
            }
            length = i;

            for (i = 0; i < length; i++) soma += array[i];
            media = round(soma / length);
            printf("\nMédia da sequência: %d\n", media);
            break;
        }

        case 3: {
            printf("Função que lê (usando a função scanf) uma sequência de números inteiros terminada com 0 e imprime no ecrã o segundo maior elemento da sequẽncia.\nIntroduza a sequência:\n\n> ");
            while (num != 0) {
                scanf("%d", &num);
                if (num != 0) printf("> ");
                array[i] = num;
                i++;
            }
            length = i;
            
            for (i = 0; i < length; i++) if (array[i] > max) max = array[i];
            for (i = 0; i < length; i++) if (array[i] > max2 && array[i] < max) max2 = array[i];

            // com INSERTION SORT
            
            for (i = 1; i < length; i++) {
                k = array[i];
                j = i - 1;

                /* Move elements of arr[0..i-1], that are
                   greater than key, to one position ahead
                   of their current position */

                while (j >= 0 && array[j] > k) {
                    array[j + 1] = array[j];
                    j--;
                }
            }

            printf("\nSegundo maior elemento: %d %d\n", max2, array[length-3]); 
            break;
        }

        case 4: {
            printf("Função que calcula o número de bits iguais a 1 usados na representação binaria de um dado número.\nIntroduza um número:\n\n> ");
            scanf("%d", &bits);
            printf("\nA soma dos bits iguais a 1: %d\n", bitsUm(bits));
            break;
        }

        case 5: {
            printf("Função que calcula o número de bits a 0 no final da representação binaria de um número.\nIntroduza um número:\n\n> ");
            scanf("%d", &bits);
            printf("\nA soma dos bits iguais a 0: %d\n", trailingZ(bits));
            break;
        }

        case 6: {
            printf("Função que calcula o número de digitos necessários para escrever o inteiro n em  base decimal.\nIntroduza um número:\n\n> ");
            scanf("%d", &n);
            printf("\nO número de digitos necessarios para escrever o numero introduzido:\n\n> %d\n", qDig(n));
            break;
        }

        case 7: {
            printf("Função que concatena a string s2 a s1 (retornando o endereço da primeira).\nIntroduza duas strings:\n\n> ");
            fgets(str1, MAX, stdin);
            printf("> ");
            fgets(str2, MAX, stdin);
            strcat(str1, str2);
            printf("\nString concatenada: \n%s", str1);
            break;
        }

        case 8: {
            printf("Função que copia a string source para dest retornando o valor para essa última.\nIntroduza duas strings:\n\n> ");
            fgets(str1, MAX, stdin);
            printf("> ");
            fgets(str2, MAX, stdin);
            strcpyDoRudrigu(str1, str2);
            printf("\nString 1: %s\nString 2: %s", str1, str2);
            break;
        }

        case 9: {
            printf("Função que compara (lexicograficamente) duas strings.\nIntroduza duas strings:\n\n> ");
            fgets(str1, MAX, stdin);
            printf("> ");
            fgets(str2, MAX, stdin);
            printf("\n%d\n", strcmpDoRudrigu(str1, str2));
            break;
        }

        case 10: {
            printf("Função  que determina a posição onde a string s2 ocoree em s1.\nIntroduza duas strings:\n\n> ");
            fgets(str1, MAX, stdin);
            printf("> ");
            fgets(str2, MAX, stdin);
            p = mystrstr(str1, str2);
            printf("\n%s\n", p);
            break;
        }

        case 11: {
            printf("Função que inverte uma string.\nIntroduza uma string:\n\n> ");
            fgets(str1, MAX, stdin);
            mystrrev(str1);
            printf("\nFunção invertida: %s\n", str1);
            break;            
        }

        case 12: {
            printf("Função que retira todas as vogais de uma string.\nIntroduza uma string:\n\n> ");
            fgets(str1, MAX, stdin);
            mystrnoV(str1);
            printf("Função sem vogais: %s", str1);
            break;
        }

        case 13: {
            printf("Função que dado um texto com palavras separadas por um ou mais espaços e um inteiro n, trunca todas as palavras de forma a terem no máximo n caractéres. Ou seja, cada palavra do texto pode ter no máximo 4 letras.\nIntroduza um texto/string:\n\n> ");
            fgets(str1, MAX, stdin);
            printf("\nIntroduza um númeiro inteiro:\n\n> ");
            scanf("%d", &n);
            truncW(str1, n);
            printf("\nOutput: %s\n", str1);
            break;
        }

        case 14: {
            printf("Função que determina qual é o caractére mais frequente numa string.\nIntroduza uma string:\n\n> ");
            fgets(str1, MAX, stdin);
            printf("Caractére mais frequente: %c\n", charMaisFreq(str1));
            break;
        }

        case 15: {
            printf("Função que dada uma string s, calcula o comprimento da maior substring com caracteres iguais.\nIntroduza uma string:\n\n> ");
            fgets(str1, MAX, stdin);
            printf("Comprimento da maior substring: %d\n", iguaisConsecutivos(str1));
            break;

        }

        case 16: {
            printf("Função que dada uma string s calcula o comprimento da maior substring com caracteres diferentes.\nIntroduza uma string:\n\n> ");
            fgets(str1, MAX, stdin);
            printf("Comprimento da maior substring: %d\n", difConsecutivos(str1));
            break;
        }

        case 17: {
            printf("Função que calcula o comprimento do maior prefixo entre duas strings.\nIntroduza duas strings:\n\n> ");
            fgets(str1, MAX, stdin);
            printf("> ");
            fgets(str2, MAX, stdin);
            printf("Comprimento do maior prefixo: %d\n", maiorPrefixo(str1, str2));
            break;
        }

        case 18: {
            printf("Função que calcula o comprimento do maior sufixo entre duas strings.\nIndtroduza duas strings:\n\n> ");
            fgets(str1, MAX, stdin);
            printf("> ");
            fgets(str2, MAX, stdin);
            printf("Comprimento do maior sufixo: %d\n", maiorSufixo(str1, str2));
            break;
        }

        case 19: {
            printf("Função que calcula o tamanho do maior sufixo de s1 que é um prefixo de s2.\nIntroduza duas strings:\n\n> ");
            fgets(str1, MAX, stdin);
            printf("> ");
            fgets(str2, MAX, stdin);
            printf("Comprimento: %d\n", sufPref(str1, str2));
            break;
        }

        case 20: {
            printf("Função que conta as palavras de uma string.\nIntroduza uma string:\n\n> ");
            fgets(str1, MAX, stdin);
            printf("Número de palavras: %d\n", contaPal(str1));
            break;
        }

        case 21: {
            printf("Função que conta vogais.\nIntroduza uma string:\n\n> ");
            fgets(str1, MAX, stdin);
            printf("Número de vogais: %d\n", contaVogais(str1));
            break;
        }

        default:
            break;
    }    

    return 0;
}
