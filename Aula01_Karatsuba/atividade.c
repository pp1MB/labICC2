/* Grupo
 * Pedro Henrique de Sousa Prestes - 15507819
 * Pedro Lunkes Villela - 15484287 */

/* Trabalho 1 - Multiplicação
 * Multiplicação Convencional x Algoritmo de Karatsuba */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "operacoes.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

/* Funções referentes ao timer. */
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

/* Remove os zeros extras na frente do número. */
char *remove_leading_zeros(char *str) {
    int i = 0;
    int tam = strlen(str);
    while (str[i] == '0') {
        i++;
        if(i == tam){
            return str + i - 1;
        }
    }
    return str + i;
}

/* Função simulando uma multiplicação 'na mão'.
 * Complexidade: O(n^2)*/
char *multiplicacao(const char *str1, const char* str2){
    int tam1 = strlen(str1);
    int tam2 = strlen(str2);

    char *res = malloc(tam1 + tam2 + 1);
    if(res == NULL) exit(1);
    memset(res, '0', tam1 + tam2);
    res[tam1 + tam2] = '\0';

    char *aux = malloc(tam2);
    if(aux == NULL) exit(1);
    strcpy(aux, str2);

    for(int i = tam1 - 1; i >= 0; i--){
        for(int j = str1[i] - '0'; j > 0; j--)
            res = add(res, aux);
            aux = potencia_de_10(aux, 1);
    }

    res = remove_leading_zeros(res);
    
    return res;
}

/* Adiciona zeros extras na frente do número
 * para igualar o tamanho das strings e/ou 
 * transformar em uma quantidade de dígitos par.*/
char *pad_with_zeros(char *str, int n) {
    char *padded = calloc(strlen(str) + n + 1, sizeof(char));
    memset(padded, '0', n);
    strcpy(padded + n, str);
    padded[strlen(str) + n] = '\0';
    
    return padded;
}


/* Algoritmo Karatsuba de Multiplicação.
 * Complexidade: O(n^~1.58)*/
char *karatsuba(char *str1, char *str2){
    int n = max(strlen(str1), strlen(str2));
    char *s1 = pad_with_zeros(str1, n - strlen(str1));
    char *s2 = pad_with_zeros(str2, n - strlen(str2));

    if(n == 1){
        char *res = malloc(3);
        res[0] = ((s1[0] - '0') * (s2[0] - '0')) / 10 + '0';
        res[1] = ((s1[0] - '0') * (s2[0] - '0')) % 10 + '0';
        res[2] = '\0';
        return res;
    }

    int m = n / 2;
    //m = m + n % 2;

    char *q = s1 + m;
    char *p = strndup(s1, m);
    char *s = s2 + m;
    char *r = strndup(s2, m);

    m = m + n % 2;    

    char *pr = karatsuba(p, r);
    char *qs = karatsuba(q, s);

    char *y = karatsuba(add(p, q), add(r, s));

    char *p1 = potencia_de_10(pr, 2 * m);
    char *p2 = potencia_de_10(sub(sub(y, pr), qs), m);

    char *res = add(add(p1, p2), qs);

    res = remove_leading_zeros(res);

    return res;
}

int main() {
    Timer timer;
    char *str1 = (char *) malloc(100000);
    char *str2 = (char *) malloc(100000);

    scanf("%s", str1);
    scanf("%s", str2);

    //printf("%d %d\n", strlen(str1), strlen(str2)); 

    /* Medição de tempo Método Convencional*/
    start_timer(&timer);
    char *res = multiplicacao(str1, str2);
    printf("%s\n", res);
    printf("%f\n", stop_timer(&timer));

    /* Medição de tempo Karatsuba */ 
    start_timer(&timer);
    char *resK = karatsuba(str1, str2);
    printf("%s\n", resK);
    printf("%f\n", stop_timer(&timer));
}
