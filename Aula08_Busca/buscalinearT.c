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


int busca_linear(int *v, int n, int k){
    for(int i = 0;i < n; i++){
        if(v[i] == k){
            return i;
        }
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int *v = (int *) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    Timer timer;
    start_timer(&timer);
    
    int pos = busca_linear(v, n, k);

    printf("%d %lf\n", n, stop_timer(&timer));
}

