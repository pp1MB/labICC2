#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "operacoes.h"

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

// char* multiplicacao(const char* str1, const char* str2){
//     int tam1 = strlen(str1);
//     int tam2 = strlen(str2);

//     char* res = malloc(tam1 + tam2);
//     memset(res, '0', tam1 + tam2);
    
//     int i, j, carry;
//     for(i = tam1 - 1; i >= tam1; i--){
//         carry = 0;
//         for(j = tam2 - 1; j >= tam2; j--){
//             int produto = (str1[i] - '0') * (str2[j] - '0') + (res[i+j+1] - '0') + carry;
//             res[i+j+1] = (produto % 10);
//             carry = produto / 10;
//         }
//     }

//     res[i+j+1] += carry;
//     printf("%s", res);
//     return res;
// }

/* Função simulando uma multiplicação 'na mão'.*/
char *multiplicacao(const char *str1, const char* str2){
    int tam1 = strlen(str1);
    int tam2 = strlen(str2);

    char *res = malloc(tam1 + tam2);
    memset(res, '0', tam1 + tam2);

    char *aux = malloc(tam2);
    strcpy(aux, str2);

    for(int i = tam1 - 1; i >= 0; i--){
        for(int j = str1[i] - '0'; j > 0; j--)
            res = add(res, aux);
            aux = potencia_de_10(aux, 1);
    }

    if(res[0] == '0')
        return res + 1;
    
    return res;
}

/* Algoritmo de Karatsuba*/
char* karatsuba(char* str1, char* str2);

int main() {
    Timer timer;
    char *str1 = (char *) malloc(100000);
    char *str2 = (char *) malloc(100000);

    scanf("%s", str1);
    scanf("%s", str2);

    start_timer(&timer);

    char *res = multiplicacao(str1, str2);
    printf("%s\n", res);

    printf("Tempo de execução: %f segundos\n", stop_timer(&timer));

    // Inicialização

    // Entrada (2 números inteiros positivos de até 10000 dígitos)

    // Execução de multiplicação convencional e medição de tempo

    // Execução de Karatsuba e medição de tempo
}
