#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 1000000
#define NUM_LETTERS 1

char *rand_str(int len){
    char *s = (char*) malloc((len + 1) * sizeof(char));

    for(int i = 0; i < len; i++){
        s[i] = 'a' + rand() % 26;
    }

    s[len] = '\0';

    return s;
}

void criar_caso(char *nome_arquivo, int n){
    FILE *arq = fopen(nome_arquivo, "w");

    fprintf(arq, "%d\n", n);

    for(int i = 0; i < n; i++){
        char *s = rand_str(NUM_LETTERS);
        fprintf(arq, "%s %d\n", s, 10 * i);
        free(s);
    }

    fclose(arq);
}

int main(){
    int caso;
    // printf("Digite o numero do caso teste: ");
    // scanf("%d", &caso);

    // int n;
    // printf("Digite o numero de elementos: ");
    // scanf("%d", &n);

    for(int i = 1; i <= 200; i++){
        char *nome_arquivo = (char*) malloc(100 * sizeof(char));
        sprintf(nome_arquivo, "casos_teste_nr2.1/%d.in", i);
        criar_caso(nome_arquivo, 5000 * i);
        free(nome_arquivo);
    }
    return 0;
}