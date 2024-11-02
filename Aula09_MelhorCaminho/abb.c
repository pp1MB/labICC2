#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    int valor;
    struct no_ *esquerda;
    struct no_ *direita;
} NO;

NO *inserirABB(NO *raiz, int valor);
NO *procurarABB(NO *raiz, int valor);
void apagarABB(NO *raiz);

int main(void){
    int n;
    scanf("%d", &n);
    
    int res;
    scanf("%d", &res);
    NO *raiz = inserirABB(NULL, res);

    for(int i = 0; i < n - 1; i++){
        scanf("%d", &res);
        inserirABB(raiz, res);
    }

    scanf("%d", &res);
    procurarABB(raiz, res);

    apagarABB(raiz);

    return 0;
}

NO *inserirABB(NO *raiz, int valor){
    if(raiz == NULL){
        NO *novo = (NO *) malloc(sizeof(NO));
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;

        return novo;
    }

    if(valor < raiz->valor)
        raiz->esquerda = inserirABB(raiz->esquerda, valor);
    else if(valor > raiz->valor)
        raiz->direita = inserirABB(raiz->direita, valor);

    return raiz;
}

NO *procurarABB(NO *raiz, int valor){
    if(raiz == NULL){
        printf("-1");
        return raiz;
    }

    printf("%d ", raiz->valor);
    if(raiz->valor == valor)
        return raiz;

    if(valor < raiz->valor)
        return procurarABB(raiz->esquerda, valor);
    else if(valor > raiz->valor)
         return procurarABB(raiz->direita, valor);
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