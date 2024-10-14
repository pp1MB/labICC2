#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Struct carta utilizada para armazenar o naipe e sua sequência de cartas. */
typedef struct {
    char naipe[4];
    char* valor;
} CARTA;

void stoogeSort(CARTA *baralho, int inicio, int fim);
int getSeq(char valor);
bool compararCartas(CARTA c1, CARTA c2);

int main(void){
    int cartas, n;
    scanf("%d %d", &cartas, &n);

    CARTA *baralho = (CARTA *) malloc(sizeof(CARTA) * cartas);

    for(int i = 0; i < cartas; i++){
        CARTA carta;
        carta.valor = (char *) malloc((n + 1) * sizeof(char));
        scanf("%s %s", carta.naipe, carta.valor);

        baralho[i] = carta;
    }
    
    stoogeSort(baralho, 0, cartas - 1);

    for(int i = 0; i < cartas; i++){
        printf("%s %s;", baralho[i].naipe, baralho[i].valor);
        free(baralho[i].valor);
        baralho[i].valor = NULL;
    }

    printf("\n");

    free(baralho);
    baralho = NULL;

    return 0;
}

void stoogeSort(CARTA *baralho, int inicio, int fim){
    if(compararCartas(baralho[inicio], baralho[fim])){
        CARTA temp = baralho[inicio];
        baralho[inicio] = baralho[fim];
        baralho[fim] = temp;
    }

    if(fim - inicio > 1){
        int divisor = (fim - inicio + 1)/3;
        stoogeSort(baralho, inicio, fim - divisor);
        stoogeSort(baralho, inicio + divisor, fim);
        stoogeSort(baralho, inicio, fim - divisor);
    }

    return;
}

int getSeq(char valor){
    char seq[10] = {'4', '5', '6', '7', 'Q', 'J', 'K', 'A', '2', '3'};
    for(int i = 0; i < 10; i++)
        if(valor == seq[i])
            return i;
}

bool compararCartas(CARTA c1, CARTA c2){
    int naipe_c1, naipe_c2;

    if(strcmp("♦", c1.naipe) == 0)
        naipe_c1 = 0;
    else if(strcmp("♠", c1.naipe) == 0)
        naipe_c1 = 1;
    else if(strcmp("♥", c1.naipe) == 0)
        naipe_c1 = 2;
    else if(strcmp("♣", c1.naipe) == 0)
        naipe_c1 = 3;

    if(strcmp("♦", c2.naipe) == 0)
        naipe_c2 = 0;
    else if(strcmp("♠", c2.naipe) == 0)
        naipe_c2 = 1;
    else if(strcmp("♥", c2.naipe) == 0)
        naipe_c2 = 2;
    else if(strcmp("♣", c2.naipe) == 0)
        naipe_c2 = 3;

    if(naipe_c1 != naipe_c2)
        return naipe_c1 > naipe_c2;

    for(int i = 0; i <= strlen(c1.valor); i++){
        if(getSeq(c1.valor[i]) > getSeq(c2.valor[i]))
            return true;
        else if(getSeq(c1.valor[i]) < getSeq(c2.valor[i]))
            return false;
    }

    return false;
}       