#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000000

typedef struct no_{
    int valor;
    struct no_ *esquerda;
    struct no_ *direita;
} NO;


int superRand(int max){
    return rand() % max;
}

int compara(const void *a, const void *b){
    return (*(int *) a - *(int *) b);
}

void apagarABB(NO *raiz){
    if(raiz == NULL)
        return;

    apagarABB(raiz->esquerda);
    apagarABB(raiz->direita);

    free(raiz);
    raiz = NULL;

    return;
}

NO *balanceia(int *vetor, int inicio, int fim){
    if(inicio > fim)
        return NULL;

    int meio = (inicio + fim) / 2;
    NO *raiz = (NO *) malloc(sizeof(NO));
    raiz->valor = vetor[meio];

    NO *esquerda = balanceia(vetor, inicio, meio - 1);
    NO *direita = balanceia(vetor, meio + 1, fim);

    raiz->esquerda = esquerda;
    raiz->direita = direita;

    return raiz;
}

int *noParaVetor(NO *raiz, int *vetor, int tam){
    NO **nos = (NO **) malloc(sizeof(NO *) * tam);

    int pos = 0, indice = 0;
    nos[pos] = raiz;
    pos++;

    while(pos < tam){
        if(nos[indice]->esquerda != NULL) {
            nos[pos] = nos[indice]->esquerda;
            pos++;
        }
        if(nos[indice]->direita != NULL) {
            nos[pos] = nos[indice]->direita;
            pos++;
        }

        indice++;
    }

    for(int i = 0; i < tam; i++)
        vetor[i] = nos[i]->valor;

    free(nos);
    return vetor;
}

void displayTree(NO *raiz, int altura){
    if(raiz == NULL)
        return;

    displayTree(raiz->esquerda, altura + 1);
    printf("Node: %d - altura %d\n", raiz->valor, altura);
    displayTree(raiz->direita, altura + 1);
}

int *cria_vetor(int tamanaho){
    int *vetor = (int *) malloc(tamanaho * sizeof(int));

    for(int i = 0; i < tamanaho; i++)
        vetor[i] = superRand(MAX);
    
    qsort(vetor, tamanaho, sizeof(int), compara);

    NO *raiz = balanceia(vetor, 0, tamanaho - 1);

    int altura = 0;
    // displayTree(raiz, altura);
    vetor = noParaVetor(raiz, vetor, tamanaho);

    apagarABB(raiz);
    return vetor;
}



int main(int argc, char *argv[]) {
    srand(time(NULL));

    if(argc > 2)
        return 1;

    int n = atoi(argv[1]);

    for (int i = 1; i < n + 1; ++i) {
        char filename[50];
        sprintf(filename, "casos_teste/%d.in", i);
        
        FILE *file = fopen(filename, "w");
        if (file == NULL) {
            perror("Failed to open file");
            return 1;
        }

        int m = i * 1000;
        int *vetor = cria_vetor(m);

        fprintf(file, "%d\n", m);
        int procurado = vetor[m - 1];

        for (int j = 0; j < m; j++) {
            fprintf(file, "%d ", vetor[j]);
        }
    
        fprintf(file, "\n%d", procurado);

        free(vetor);

        fclose(file);
    }
}