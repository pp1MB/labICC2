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
    return padded;
}

char *corta_string(char *str, int final) {
    char *cortada = calloc(final + 1, sizeof(char));
    strcpy(cortada, str);
    cortada[final] = '\0';
    return cortada;
}

char *karatsuba(char *str1, char *str2){
    int tam1 = strlen(str1);
    int tam2 = strlen(str2);

    if(tam1 == 1 && tam2 == 1){
        char *res_str = malloc(3);
        res_str[0] = ((str1[0] - '0') * (str2[0] - '0') / 10) + '0';
        res_str[1] = ((str1[0] - '0') * (str2[0] - '0') % 10) + '0';
        res_str[2] = '\0';
        printf("saiu\n");
        return res_str;
    }

    int max = (strlen(str1)) > (strlen(str2)) ? (strlen(str1)) : ((strlen(str2)));

    str1 = pad_with_zeros(str1, max - strlen(str1));
    str2 = pad_with_zeros(str2, max - strlen(str2));

    int m = max / 2;

    char *sup1 = corta_string(str1, m);
    char *inf1 = str1 + m;
    char *sup2 = corta_string(str2, m);
    char *inf2 = str2 + m;

    printf("%s %s %s %s\n", sup1, inf1, sup2, inf2);

    char *z0 = karatsuba(sup1, sup2);
    printf("z0\n");
    char *z1 = karatsuba(add(inf1, sup1), add(inf2, sup2));
    printf("z1\n");
    char *z2 = karatsuba(inf1, inf2);
    printf("z2\n");

    printf("%s %s %s\n", z0, z1, z2);

    char *p1 = potencia_de_10(z2, 2 * m);
    char *p2 = potencia_de_10(sub(sub(z1, z2), z0), m);

    printf("%s %s\n", p1, p2);

    return add(add(p1, p2), z0);
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
