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


char *remove_leading_zeros(char *str) {
    int i = 0;
    while (str[i] == '0') {
        i++;
    }
    return str + i;
}

char *pad_with_zeros(char *str, int n) {
    char *padded = calloc(strlen(str) + n + 1, sizeof(char));
    memset(padded, '0', n);
    strcpy(padded + n, str);

    printf("%s\n", padded);
    
    return padded;
}

char *corta_string(char *str, int final) {
    char *cortada = calloc(final + 1, sizeof(char));
    strcpy(cortada, str);
    cortada[final] = '\0';
    return cortada;
}

char *karatsuba(char *str1, char *str2){
    int n = max(strlen(str1), strlen(str2));

    // if(n % 2){
    //     n++;
    // }

    pad_with_zeros(str1, n - strlen(str1));
    pad_with_zeros(str2, n - strlen(str2));

    if(n <= 3){
        char *res = (char *) malloc(sizeof(char) * 7);
        int calc = strtol(str1, NULL, 10) * strtol(str2, NULL, 10);
        sprintf(res, "%d", calc);
        remove_leading_zeros(res);
        return res;
    }
    int m = n / 2;

    char *p = corta_string(str1, m);
    char *q = str1 + m;
    char *r = corta_string(str2, m);
    char *s = str2 + m;

    char *pr = karatsuba(p, r);
    char *qs = karatsuba(q, s);
    char *y = karatsuba(add(p, q), add(r, s));

    char *res = add(add(potencia_de_10(pr, 2 * m), potencia_de_10(sub(sub(y, pr), qs), m)), qs);

    remove_leading_zeros(res);

    return res;
}


int main() {
    Timer timer;
    char *str1 = (char *) malloc(100000);
    char *str2 = (char *) malloc(100000);

    scanf("%s", str1);
    scanf("%s", str2);

    // start_timer(&timer);
    // char *res = multiplicacao(str1, str2);
    // printf("%s\n", res);
    // printf("Tempo de execução Multiplicação: %f segundos\n", stop_timer(&timer));

    start_timer(&timer);
    char *resK = karatsuba(str1, str2);
    printf("%s\n", resK);
    printf("Tempo de execução Karatsuba: %f segundos\n", stop_timer(&timer));

    // Inicialização

    // Entrada (2 números inteiros positivos de até 10000 dígitos)

    // Execução de multiplicação convencional e medição de tempo

    // Execução de Karatsuba e medição de tempo
}
