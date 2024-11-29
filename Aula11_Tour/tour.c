#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 100

typedef struct local_{
    char *nome;
    int adj;
} LOCAL;

void caminho(LOCAL *vet, char *começo, int n_passos){
    int index_start = 0;

    while(strcmp(vet[index_start].nome, começo)) index_start++; // Otimize aqui
    
    int index_passo = index_start;
    for(int j = 0; j < n_passos; j++){
        index_passo = vet[index_passo].adj - 1;

        // Trata loop
        if(index_passo == index_start){
            if(j != 0) n_passos = n_passos % (j + 1) + 1;
            j = 0;
        }
    }

    printf("%s\n", vet[index_passo].nome);

    return;
}

int main(void){
    int n_local, n_passeio;
    scanf("%d %d", &n_local, &n_passeio);

    char temp[NAME_MAX];
    LOCAL *vet = (LOCAL *) malloc(n_local * sizeof(LOCAL));

    // Lendo locais
    for(int i = 0; i < n_local; i++){
        scanf("%s %d", temp, &(vet[i].adj));

        // Copiando string
        int tam = strlen(temp);
        vet[i].nome = (char *) malloc((tam + 1) * sizeof(char));
        strcpy(vet[i].nome, temp);
    }

    // Fazendo passeios
    for(int i = 0; i < n_passeio; i++){
        int n_passos;
        char começo[NAME_MAX];
        scanf("%s %d", começo, &n_passos);
        caminho(vet, começo, n_passos);
    }

    for(int i = 0; i < n_local; i++){
        free(vet[i].nome);
        vet[i].nome = NULL;
    }

    free(vet);
    vet = NULL;

    return 0;
}