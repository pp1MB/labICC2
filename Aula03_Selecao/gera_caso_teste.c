#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 1000
#define NUM_LETTERS 10

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
        fprintf(arq, "%s %d\n", s, rand() % MAX_VALUE);
        free(s);
    }

    fclose(arq);
    free(nome_arquivo);
}

int main(){
    int caso;
    // printf("Digite o numero do caso teste: ");
    // scanf("%d", &caso);

    // int n;
    // printf("Digite o numero de elementos: ");
    // scanf("%d", &n);

    for(int i = 1; i <= 50; i++){
        char *nome_arquivo = (char*) malloc(100 * sizeof(char));
        sprintf(nome_arquivo, "casos_teste_nr/%d.in", i);
        criar_caso(nome_arquivo, 500 * i * i);
    }
    return 0;
}