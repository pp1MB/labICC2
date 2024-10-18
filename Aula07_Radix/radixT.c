#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/* Struct carta utilizada para armazenar o naipe e sua sequência de cartas. */
typedef struct {
    char naipe[4];
    char* valor;
} CARTA;

void radix_sort(CARTA *baralho, int cartas, int n);
CARTA *count_sort(CARTA *baralho, int n, int k);
CARTA *count_sort_naipe(CARTA *baralho, int n);

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

    radix_sort(baralho, cartas, n);

    return 0;
}

void radix_sort(CARTA *baralho, int cartas, int n){
    // Printa a sequência original
    // for(int i = 0; i < cartas; i++)
    //     printf("%s %s;", baralho[i].naipe, baralho[i].valor);

    // printf("\n");

    Timer tempo;
    double tempo_s = 0;
    // Ordena sequência de cartas.
    for(int i = n - 1; i >= 0; i--){
        // printf("Após ordenar o %d° dígito dos valores:\n", i+1);

        start_timer(&tempo);
        baralho = count_sort(baralho, cartas, i);
        tempo_s += stop_timer(&tempo);

        // for(int i = 0; i < cartas; i++)
        //     printf("%s %s;", baralho[i].naipe, baralho[i].valor);
        
        // printf("\n");
    }

    // Ordena naipe de cartas.
    // printf("Após ordenar por naipe:\n");
    start_timer(&tempo);
    baralho = count_sort_naipe(baralho, cartas);
    tempo_s += stop_timer(&tempo);

    for(int i = 0; i < cartas; i++){
        // printf("%s %s;", baralho[i].naipe, baralho[i].valor);
        free(baralho[i].valor);
        baralho[i].valor = NULL;
    }
    
    free(baralho);
    baralho = NULL;

    // printf("\n");

    printf("%d %lf\n", n * cartas, tempo_s);

    return;
}

/* Count Sort para a sequência de cartas. */
CARTA *count_sort(CARTA *baralho, int n, int k){
    CARTA *saida = (CARTA *) malloc(sizeof(CARTA) * n);
    char seq[10] = {'4', '5', '6', '7', 'Q', 'J', 'K', 'A', '2', '3'};
    int count[10] = {0};
    
    for(int i = 0; i < n; i++){
        int index;
        for(index = 0; index < 10 && baralho[i].valor[k] != seq[index]; index++); 
        count[index]++;
    }
 
    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for(int i = n - 1; i >= 0; i--){
        int index;
        for(index = 0; index < 10 && baralho[i].valor[k] != seq[index]; index++); 

        saida[count[index] - 1] = baralho[i];
        count[index]--;
    }

    free(baralho);
    baralho = NULL;

    return saida;
}

/* Count Sort para o naipe. */
// Pode criar um vetor de index pra melhorar se quiser.
CARTA *count_sort_naipe(CARTA *baralho, int n){
    CARTA *saida = (CARTA *) malloc(sizeof(CARTA) * n);
    int *count = (int *) calloc(4, sizeof(int));

    for(int i = 0; i < n; i++){
        if(strcmp("♦", baralho[i].naipe) == 0)
            count[0]++;
        else if(strcmp("♠", baralho[i].naipe) == 0)
            count[1]++;
        else if(strcmp("♥", baralho[i].naipe) == 0)
            count[2]++;
        else if(strcmp("♣", baralho[i].naipe) == 0)
            count[3]++;
    }

    for (int i = 1; i < 4; i++)
        count[i] += count[i - 1];

    for(int i = n - 1; i >= 0; i--){
        int index;

        if(strcmp("♦", baralho[i].naipe) == 0)
            index = 0;
        else if(strcmp("♠", baralho[i].naipe) == 0)
            index = 1;
        else if(strcmp("♥", baralho[i].naipe) == 0)
            index = 2;
        else if(strcmp("♣", baralho[i].naipe) == 0)
            index = 3;

        saida[count[index] - 1] = baralho[i];
        count[index]--;
    }

    free(baralho);
    baralho = NULL;
    free(count);
    count = NULL;

    return saida;
}