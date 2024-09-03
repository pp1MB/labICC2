#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *arq;
    arq = fopen("casoTesteMultiplicacao.txt", "w");

    char *num = malloc(10001);
    num[0] = '1';

    for(int i = 1;i<5000;i++){
        num[i] = '0';
        num[i+1] = '\0';
        fprintf(arq, "1 %s\n", num);
    }

    free(num);
}
