#include <stdio.h>
#include <stdlib.h>

/* Struct para armazenar as informações dos pratos. */
typedef struct prato_{
    char nome[51];
    int prioridade;
    int tempo;
} PRATO;

/* QuickSort */
void qSort(PRATO *pratos, int inicio, int fim){
    int i = inicio;
    int j = fim;
    int pivo = pratos[(i + j)/2].prioridade;
    int pivot = pratos[(i + j)/2].tempo;
    
    while(i <= j){
        while(pratos[i].prioridade < pivo || (pratos[i].prioridade == pivo && pratos[i].tempo > pivot)) i++;
        while(pratos[j].prioridade > pivo || (pratos[j].prioridade == pivo && pratos[j].tempo < pivot)) j--;
        
        if(i <= j){
            PRATO aux = pratos[i];
            pratos[i] = pratos[j];
            pratos[j] = aux;
            i++;
            j--;
        }
    }

    if(j > inicio) qSort(pratos, inicio, j);
    if(i < fim) qSort(pratos, i, fim);

    return;
}

/* BubbleSort */
void bSort(PRATO *pratos, int n){
    int troca = 1;
    PRATO aux;
    while(troca){
        troca = 0;
        for(int i = 1; i < n; i++)
            if(pratos[i-1].prioridade > pratos[i].prioridade || (pratos[i-1].prioridade == pratos[i].prioridade && pratos[i-1].tempo < pratos[i].tempo)){
                troca = 1;
                aux = pratos[i-1];
                pratos[i-1] = pratos[i];
                pratos[i] = aux;
            }
    }

    return;
}

int main(void){
    /* Leitura das informações dos pratos. */
    int n;
    scanf("%d", &n);
    PRATO *pratos = (PRATO *) malloc(sizeof(PRATO) * n);
    for(int i = 0; i < n; i++)
        scanf("%d %d %s", &pratos[i].prioridade, &pratos[i].tempo, pratos[i].nome);

    /* Sort */
    qSort(pratos, 0, n-1);
    // bSort(pratos, n);

    /* Print dos maiores pratos. */
    for(int i = 0; i < n; i++)
       printf("%s\n", pratos[i].nome);

    free(pratos);

    return 0;
}