#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
// #include <unistd.h>
// #include <sys/resource.h>
// #include <windows.h>


typedef struct {
    clock_t start;
    clock_t end;
} Timer;

void start_timer(Timer *timer) {
    timer->start = clock();
}

double stop_timer(Timer *timer) {
    timer->end = clock();
    return ((double) (timer->end - timer->start)) / CLOCKS_PER_SEC;
}

typedef struct no_{
    int valor;
    struct no_ *esquerda;
    struct no_ *direita;
} NO;

NO *inserirABB(NO *raiz, int valor);
NO *procurarABB(NO *raiz, int valor);
void apagarABB(NO *raiz);

bool dfs(NO *raiz, int valor) {
    if (raiz == NULL) {
        // printf("-1\n");
        return false;
    }

    // printf("%d ", raiz->valor);

    if (raiz->valor == valor) {
        // printf("\n");
        return true;
    }

    if (raiz->esquerda != NULL && dfs(raiz->esquerda, valor))
        return true;
    if (raiz->direita != NULL && dfs(raiz->direita, valor))
        return true;

    return false;
}

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

    Timer timer;
    start_timer(&timer);

    // struct timespec start, end;
    // clock_gettime(CLOCK_MONOTONIC, &start);

    procurarABB(raiz, res);
    // dfs(raiz, res);

    // clock_gettime(CLOCK_MONOTONIC, &end);
    // long seconds = end.tv_sec - start.tv_sec;
    // long time = end.tv_nsec - start.tv_nsec;

    // long elapsed = seconds * 100000000 + time;


    printf("%d %lf\n", n, stop_timer(&timer));

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
        // printf("-1");
        return raiz;
    }

    // printf("%d ", raiz->valor);
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