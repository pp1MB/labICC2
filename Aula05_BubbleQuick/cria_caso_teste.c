#include <stdio.h>
#include <stdlib.h>

#define PRIORIDADE 300000
#define TEMPO 3000
#define NOME 50

#define CASOS 1000

int superRand(int tam){
    return rand() % tam;
}

char *randNome(){
    char *nome = (char *) malloc(NOME * sizeof(char));
    for(int i = 0;i < NOME;i++){
        nome[i] = superRand(26) + 'a';
    }
    return nome;
}

int main(){
    for(int i = 827;i < CASOS;i++){
        char *nome_arquivo = (char *) malloc(30 * sizeof(char));
        sprintf(nome_arquivo, "casoteste2/%d.in", i);
        FILE *arq = fopen(nome_arquivo, "w");

        fprintf(arq, "%d\n", i * 300);

        for(int j = 0;j < i * 300;j++){
            char *nome = randNome();
            fprintf(arq, "%d %d %s\n", superRand(PRIORIDADE), superRand(TEMPO), randNome());
            free(nome);
        }

        printf("Caso %d criado.\n", i);

        fclose(arq);
        free(nome_arquivo);
    }
}
