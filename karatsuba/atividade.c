#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "operacoes.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

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
    if(res == NULL) exit(1);
    memset(res, '0', tam1 + tam2);

    char *aux = malloc(tam2);
    if(aux == NULL) exit(1);
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

char *corta_str(char *str, int corte){
    char *str_cortada = (char *) malloc(sizeof(char) * corte);

    for(int i = 0;i<corte;i++){
        str_cortada[i] = str[i];
    }

    return str_cortada;
}

char* karatsuba(char* str1, char* str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int maxLen = max(len1, len2);

    if (len1 == 1 && len2 == 1) {
        int product = (str1[0] - '0') * (str2[0] - '0');
        char* result = (char*) malloc(3);
        sprintf(result, "%d", product);
        return result;
    }

    int mid = maxLen / 2;

    char* sup1 = corta_str(str1, mid);
    char* inf1 = str1 + mid;
    char* sup2 = corta_str(str2, mid);
    char* inf2 = str2 + mid;

    char* z0 = karatsuba(inf1, inf2);
    char* z1 = karatsuba(add(inf1, sup1), add(inf2, sup2));
    char* z2 = karatsuba(sup1, sup2);

    char* temp1 = sub(z1, z0);
    char* temp2 = sub(temp1, z2);

    char* result = add(add(potencia_de_10(z2, 2 * mid), potencia_de_10(temp2, mid)), z0);
    printf("%s\n", result);

    free(sup1);
    free(sup2);
    // free(temp1);
    // free(temp2);
    // free(z0);
    // free(z1);
    // free(z2);

    return result;
}

int main() {
    Timer timer;
    char *str1 = (char *) malloc(100000);
    char *str2 = (char *) malloc(100000);

    scanf("%s", str1);
    scanf("%s", str2);

    start_timer(&timer);
    char *res = multiplicacao(str1, str2);
    printf("%s\n", res);
    printf("Tempo de execução Multiplicação: %f segundos\n", stop_timer(&timer));

    start_timer(&timer);
    char *resK = karatsuba(str1, str2);
    printf("%s\n", resK);
    printf("Tempo de execução Karatsuba: %f segundos\n", stop_timer(&timer));

    // Inicialização

    // Entrada (2 números inteiros positivos de até 10000 dígitos)

    // Execução de multiplicação convencional e medição de tempo

    // Execução de Karatsuba e medição de tempo
}
