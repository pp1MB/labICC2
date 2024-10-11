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

void heapify(PRATO *arr, int n, int i) { 
    int menor = i; 
    int esq = 2 * i + 1; 
    int dir = 2 * i + 2;

    if (esq < n && (arr + esq)->prioridade < (arr + menor)->prioridade)
        menor = esq;
    else if (esq < n && (arr + esq)->prioridade == (arr + menor)->prioridade && (arr + esq)->tempo > (arr + menor)->tempo)
        menor = esq;

    if (dir < n && (arr + dir)->prioridade < (arr + menor)->prioridade)
        menor = dir;
    else if (dir < n && (arr + dir)->prioridade == (arr + menor)->prioridade && (arr + dir)->tempo > (arr + menor)->tempo)
        menor = dir;

    if (menor != i) {
        PRATO temp = *(arr + i);
        *(arr + i) = *(arr + menor);
        *(arr + menor) = temp;

        heapify(arr, n, menor);
    }
}

void heapMinima(PRATO *arr, int n) {
    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(PRATO *arr, int n) {
    heapMinima(arr, n);

    for (int i = n - 1; i > 0; i--) {
        PRATO temp = *arr;
        *arr = *(arr + i);
        *(arr + i) = temp;

        heapify(arr, i, 0);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    PRATO *pratos = (PRATO *) malloc(sizeof(PRATO) * n);
    for(int i = 0; i < n; i++)
        scanf("%d %d %s", &((pratos + i)->prioridade), &((pratos + i)->tempo), ((pratos + i)->nome));

    // Timer timer;
    // start_timer(&timer);

    heapSort(pratos, n);

    // printf("%d %f\n", n, (stop_timer(&timer)));

    for(int i = n - 1; i >= 0; i--)
        printf("%s\n", (pratos + i)->nome);

    free(pratos);

    return 0;
}
