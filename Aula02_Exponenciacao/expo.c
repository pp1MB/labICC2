#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int expo_iterativo(int n, int i);
int expo_recursivo(int n, int k);

/* Configurações timer */

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

/* ---------------- */

int main(void){
    Timer timer;
    int n, i;
    scanf("%d %d", &n, &i);

    /* Execução Recursivo */
    start_timer(&timer);   
    printf("%lld\n", expo_recursivo(n, i));
    stop_timer(&timer);
    printf("Tempo de execução Recursivo: %f segundos\n", stop_timer(&timer));

    /* Execução Iterativo */
    start_timer(&timer);
    printf("%lld\n", expo_iterativo(n, i));
    stop_timer(&timer);
    printf("Tempo de execução Iterativo: %f segundos\n", stop_timer(&timer));

    return 0;
}

/* Exponenciação Iterativo: Recebe n^i*/
int expo_iterativo(int n, int i){
    int res = n;
    for(i; i > 1; i--){
        n *= res;
        n %= 10000;
    }

    return n;
}

/* Exponenciação Recursivo: Recebe n^k*/
int expo_recursivo(int n, int k){
    if(k == 1)
        return n;

    int p = expo_recursivo(n, k/2);

    if(k % 2)
        n = p * p * n;
    else
        n = p * p;

    n %= 10000;
    return n;
}