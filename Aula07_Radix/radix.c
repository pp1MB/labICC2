#include <stdio.h>
#include <stdlib.h>

#define COUNT 29

typedef struct {
    char* naipe;
    char* valor;
} CARTA;

CARTA *count_sort(CARTA *baralho, int n, int k){
    CARTA *saida = (CARTA *) malloc(sizeof(CARTA) * n);
    int *count = (int *) malloc(sizeof(int) * COUNT);

    for(int i = 0;i < COUNT;i++)
        count[i] = 0;

    for(int i = 0;i < n;i++){
        int index = baralho[i].valor[k] - '4';

        if(index < 0)
            index = COUNT - 1 + index;
        
        if(index == 13) index = 24;
        
        count[index]++;
    }

    count[0]--;    
    for(int i = 1;i < COUNT;i++)
        count[i] += count[i - 1];

    for(int i = n - 1;i >= 0;i--){
        int index = baralho[i].valor[k] - '4';

        if(index < 0)
            index = COUNT - 1 + index;
        
        if(index == 13) index = 24;

        saida[count[index]] = baralho[i];
        count[index]--;
    }

    return saida;
}

int main(){
    int cartas, n;
    scanf("%d %d", &cartas, &n);

    CARTA *baralho = (CARTA *) malloc(sizeof(CARTA) * n);

    for(int i = 0;i < cartas;i++){
        CARTA carta;
        carta.naipe = (char *) malloc(10 * sizeof(char));
        carta.valor = (char *) malloc(10 * sizeof(char));
        scanf(" %s %s", carta.naipe, carta.valor);

        baralho[i] = carta;
    }

    for(int i = n - 1;i >= 0;i--){
        baralho = count_sort(baralho, cartas, i);
    }

    for(int i = 0;i < cartas;i++){
        printf("%s %s\n", baralho[i].naipe, baralho[i].valor);
    }
}
