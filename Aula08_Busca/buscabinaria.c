#include <stdio.h>
#include <stdlib.h> 

typedef struct{
    int valor;
    int pos;
} TUPLA;


int cmpfunc(const void *a, const void *b) {
    TUPLA *tuplaA = (TUPLA *)a;
    TUPLA *tuplaB = (TUPLA *)b;
    return (tuplaA->valor - tuplaB->valor);
}


int busca_binaria(TUPLA *v, int n, int k){
    int ini = 0, fim = n-1;
    while(ini <= fim){
        int meio = (ini + fim) / 2;
        if(v[meio].valor == k){
            return meio;
        }else if(v[meio].valor > k){
            fim = meio - 1;
        }else{
            ini = meio + 1;
        }
    }
    return -1;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    TUPLA *v = (TUPLA *) malloc(n * sizeof(TUPLA));
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i].valor);
        v[i].pos = i;
    }

    qsort(v, n, sizeof(TUPLA), cmpfunc);

    // for(int i = 0; i < n; i++){
    //     printf("%d - %d\n", v[i].valor, v[i].pos);
    // }
    // printf("\n");

    int pos = busca_binaria(v, n, k);

    // printf("%d\n", pos);

    while(v[pos].valor == v[pos-1].valor){
        if(pos == 0){
            break;
        }

        pos--;
    }

    printf("%d\n", v[pos].pos + 1);

}
