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


typedef struct{
    int valor;
    int pos;
} TUPLA;


int cmpfunc(const void *a, const void *b) {
    TUPLA *tuplaA = (TUPLA *)a;
    TUPLA *tuplaB = (TUPLA *)b;
    return (tuplaA->valor - tuplaB->valor);
}


int busca_binaria(TUPLA *v, int n, int k){
    int ini = 0, fim = n-1;
    while(ini <= fim){
        int meio = (ini + fim) / 2;
        if(v[meio].valor == k){
            return meio;
        }else if(v[meio].valor > k){
            fim = meio - 1;
        }else{
            ini = meio + 1;
        }
    }
    return -1;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    TUPLA *v = (TUPLA *) malloc(n * sizeof(TUPLA));
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i].valor);
        v[i].pos = i;
    }

    qsort(v, n, sizeof(TUPLA), cmpfunc);

    // for(int i = 0; i < n; i++){
    //     printf("%d - %d\n", v[i].valor, v[i].pos);
    // }
    // printf("\n");

    Timer timer;
    start_timer(&timer);

    int pos = busca_binaria(v, n, k);

    // printf("%d\n", pos);

    while(v[pos].valor == v[pos-1].valor){
        if(pos == 0){
            break;
        }

        pos--;
    }

    printf("%d %lf\n", n, stop_timer(&timer));
}
