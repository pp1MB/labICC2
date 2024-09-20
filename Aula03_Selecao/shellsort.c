#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    char nome[100];
    int pontuacao;
} JOGADOR;


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

void shellSort(JOGADOR * jog, int tam){
    int gap = 1;

    while(gap < tam){
        gap = 3*gap+1;
    }

    while(gap > 0){
        for(int i = gap; i < tam; i++){
            int j = i;
            JOGADOR aux = jog[i];

            while(j >= gap){
                if(aux.pontuacao > jog[j-gap].pontuacao){
                    jog[j] = jog[j-gap];
                    j = j - gap;
                }else if(aux.pontuacao == jog[j-gap].pontuacao){
                    if(strcmp(aux.nome, jog[j-gap].nome) < 0){
                        jog[j] = jog[j-gap];
                        j = j - gap;
                    }else{
                        break;
                    }
                }else{
                    break;
                }
            }

            jog[j] = aux;
        }

        gap = gap/3;
    }
}

int main(){
    Timer timer;

    int n;
    scanf("%d", &n);

    JOGADOR *jogadores = (JOGADOR*) malloc(n * sizeof(JOGADOR));

    for(int i = 0; i < n; i++){
        scanf("%s", jogadores[i].nome);
        scanf("%d", &jogadores[i].pontuacao);
    }

    //start_timer(&timer);
    shellSort(jogadores, n);

    //double tempo = stop_timer(&timer);
    //printf("%f\n", tempo);

    // for(int i = 0; i < n; i++){
    //     printf("Player %d: %s, Score: %d\n", i+1, jogadores[i].nome, jogadores[i].pontuacao);
    // }

    for(int i = 0; i < n; i++){
        printf("%s %d\n", jogadores[i].nome, jogadores[i].pontuacao);
    }
    
    free(jogadores);

    return 0;
}
