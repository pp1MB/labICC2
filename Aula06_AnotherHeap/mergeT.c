#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

typedef struct prato_{
    char nome[51];
    int prioridade;
    int tempo;
} PRATO;

void intercala(PRATO *pratos, int inicio, int meio, int fim){
    int tam1 = meio - inicio + 1;
    int tam2 = fim - meio;
    PRATO *p1 = (PRATO *) malloc(tam1 * sizeof(PRATO));
    PRATO *p2 = (PRATO *) malloc(tam2 * sizeof(PRATO));
    
    for(int i = 0; i < tam1; i++)
        p1[i] = pratos[inicio + i];

    for(int i = 0; i < tam2; i++)
        p2[i] = pratos[meio + 1 + i];

    int i = 0, j = 0, k = inicio;
    while(i < tam1 && j < tam2){
        if(p1[i].prioridade < p2[j].prioridade || (p1[i].prioridade == p2[j].prioridade && p1[i].tempo > p2[j].tempo))
            pratos[k++] = p1[i++];
        else
            pratos[k++] = p2[j++];
    }

    while(i < tam1)
        pratos[k++] = p1[i++];

    while(j < tam2)
        pratos[k++] = p2[j++];

    free(p1);
    free(p2);

    return;

}

void mergeSort(PRATO *pratos, int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim)/2;
        mergeSort(pratos, inicio, meio);
        mergeSort(pratos, meio + 1, fim);
        intercala(pratos, inicio, meio, fim);
    }
}

int main(void){

     /* Leitura das informações dos pratos. */
    int n;
    scanf("%d", &n);
    PRATO *pratos = (PRATO *) malloc(sizeof(PRATO) * n);
    for(int i = 0; i < n; i++)
        scanf("%d %d %s", &pratos[i].prioridade, &pratos[i].tempo, pratos[i].nome);

    /* Sort */
    Timer timer;
    start_timer(&timer);
    mergeSort(pratos, 0, n-1);
    printf("%d %lf\n", n, stop_timer(&timer));

    // for(int i = 0; i < n; i++)
    //     printf("%s\n", pratos[i].nome);

    free(pratos);

    return 0;
}