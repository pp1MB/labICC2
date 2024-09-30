/* Grupo
 * Pedro Henrique de Sousa Prestes - 15507819
 * Pedro Lunkes Villela - 15484287 */

/* Trabalho 3 - Selection
 * Selection Sort x Shell Sort */

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <time.h>
#include <string.h>
typedef struct jogador{
    char nome[50];
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

// int comparar(char *str1, char *str2){
//     for(int i=0; str1[i] != '\0' || str2[i] != '\0'; i++){
//         if(str1[i] == str2[i])
//             continue;
//         if(str1[i] == str2[i])
//             min_i = i;

//         break;

//     }
// }


// void selection(JOGADOR *jog, int tam){
//     // PILHA *p = pilha_criar();
//     while(tam != 0){
//         int min_i = tam;

//         for(int i=tam; i >= 0; i--){
//             if(jog[min_i].pontuacao > jog[i].pontuacao)
//                 min_i = i;

//             else if(jog[min_i].pontuacao == jog[i].pontuacao)
//                 if(strcmp(jog[min_i].nome, jog[i].nome) < 0)
//                     min_i = i;
//         }

//         JOGADOR aux = jog[tam];
//         jog[tam] = jog[min_i];
//         jog[min_i] = aux;

//         tam--;
//     }

//     return;
// }

/* Selection Sort */
void selection(JOGADOR *jog, int tam){
    PILHA *p = pilha_criar();
    while(tam != 0){
        int min_i = 0;

        for(int i = 1; i < tam; i++){
            if(jog[min_i].pontuacao > jog[i].pontuacao)
                min_i = i;

            else if(jog[min_i].pontuacao == jog[i].pontuacao)
                if(strcmp(jog[min_i].nome, jog[i].nome) < 0)
                    min_i = i;
        }

        pilha_empilhar(p, jog[min_i]);
        jog[min_i] = jog[tam-1];

        tam--;
    }

    int i = 0;
    while(!pilha_vazia(p)){
        jog[i] = pilha_desempilhar(p);
        i++;
    }

    pilha_apagar(&p);

    return;
}

int main(void){
    int n;
    scanf("%d", &n);
    JOGADOR *jog = (JOGADOR *) malloc(sizeof(JOGADOR) * n);

    for(int i=0; i < n; i++){
        scanf("%s %d", jog[i].nome, &(jog[i].pontuacao));
    }

    Timer t;
    start_timer(&t);
    selection(jog, n);
    printf("Tempo de execução: %f segundos\n", stop_timer(&t));

    // for(int i=0; i < n; i++){
    //     printf("%s %d\n", jog[i].nome, jog[i].pontuacao);
    // }

    free(jog);

    return 0;
}