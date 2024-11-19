#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    struct no_ *prox;
    int valor;
} NO;

typedef struct{
    NO **itens;
    int mod;               
} HASH;

int hashfunc(int k, int m);
void inserir_hash(HASH *hash, int item);
int buscar_hash(HASH *hash, int item);
void apagar_hash(HASH *hash);
int MSChash(int *seq, int n, int max);

int comparar(const void *a, const void *b);
int MSCsort(int *seq, int n);

int main(void){
    int n;
    scanf("%d", &n);
    int *seq = (int *) malloc(sizeof(int) * n);
    int max = 0;

    for(int i = 0; i < n; i++){
        scanf("%d", &seq[i]);
        max = (seq[i] > max) ? seq[i] : max;
    }

    printf("%d\n", MSChash(seq, n, max));
//    printf("%d\n", MSCsort(seq, n));

    free(seq);

    return 0;
}

int hashfunc(int k, int m){
    if(k % m < 0) printf("%d\n", k);
    return k % m;
}

HASH *inicializar_hash(int tam){
    HASH *hash = (HASH *) malloc(sizeof(HASH));
    if(hash != NULL){
        hash->mod = tam;
        hash->itens = (NO **) calloc(tam, sizeof(NO *));
        if(hash->itens == NULL){
            free(hash);
            hash = NULL;
            return NULL;
        }
    }

    return hash;
}

void inserir_hash(HASH *hash, int item){
    int index = hashfunc(item, hash->mod);
    NO *novo = (NO *) malloc(sizeof(NO));
    novo->valor = item;
    novo->prox = hash->itens[index];
    hash->itens[index] = novo;

    return;
}

int buscar_hash(HASH *hash, int item){
    int index = hashfunc(item, hash->mod);
    NO *p = hash->itens[index];
    while(p != NULL){
        if(p->valor == item)
            return 1;
        p = p->prox;
    }

    return 0;
}

void apagar_hash(HASH *hash){
    for(int i = 0; i < hash->mod; i++){
        NO *p = hash->itens[i];
        while(p != NULL){
            NO *aux = p;
            p = p->prox;
            free(aux);
            aux = NULL;
        }
    }

    free(hash->itens);
    hash->itens = NULL;
    free(hash);
    hash = NULL;

    return;
}

int MSChash(int *seq, int n, int max){
    HASH *hash = inicializar_hash(max);

    for(int i = 0; i < n; i++) inserir_hash(hash, seq[i]);
    int item, global_tamanho = 0;

    for(int i = 0; i < n; i++){
        item = seq[i];
        if(item - 1 >= 0 && !buscar_hash(hash, item - 1)){
            int tamanho = 1;
            while(buscar_hash(hash, item + 1)){
                tamanho++;
                item++;
            }
            global_tamanho = (tamanho > global_tamanho) ? tamanho : global_tamanho;
        }
    }

    apagar_hash(hash);
    return global_tamanho;
}

int comparar(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int MSCsort(int *seq, int n){
    qsort(seq, n, sizeof(int), comparar);
    
    int tamanho = 1, global_tamanho = 1;

    for(int i = 0; i < n - 1; i++){
       if(seq[i+1] == seq[i] + 1)
            tamanho++;
       else{
            global_tamanho = (tamanho > global_tamanho) ? tamanho : global_tamanho;
            tamanho = 1;
       }
    }

    return  (tamanho > global_tamanho) ? tamanho : global_tamanho;;
}
