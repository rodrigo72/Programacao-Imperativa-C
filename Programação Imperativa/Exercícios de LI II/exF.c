	#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *line = malloc(sizeof(char) * 1000);
    int prods[26][26];

    int i, j, ms = 0, length;
    char ch, ch2;

    for (i = 0; i < 26; i++) 
        for (j = 0; j < 26; j++)
            prods[i][j] = 0;

    if(scanf("%d", &ms) != 0) {

        while(fgets(line, 1000, stdin) != NULL) {
 
            for (i = 0; line[i] != '\0'; i++);
            length = i; 

            for (i = 0; i < length; i += 2)
                for (j = 0; j < length; j += 2) {
                        prods[line[i] - 'A'][line[j] - 'A'] += 1;
                }
        }

        for (i = 0; i < 26; i++) {
            for (j = 0; j < 26; j++)
                if (prods[i][j] >= ms) {
                    if (i == j) {
                        ch  = 'A' + i;
                        printf("%c = %d\n", ch, prods[i][j]);
                    } else if (j > i) {
                        ch  = 'A' + i;
                        ch2 = 'A' + j;
                        printf("%c%c = %d\n", ch, ch2, prods[i][j]);
                    }
                }
        }

    }

    return 0;
}
