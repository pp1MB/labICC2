#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FILENAME "numeros"
#define FILEEXTENSIONBIN ".bin"

typedef struct lista_t {
    int *numeros;
    int tamanho;
} lista_t;


// Estrutura para armazenar o tempo de execução
typedef struct {
    clock_t start;
    clock_t end;
} Timer;

// Inicializa o timer
void start_timer(Timer *timer) {
    timer->start = clock();
}

// Para o timer e calcula o tempo decorrido
double stop_timer(Timer *timer) {
    timer->end = clock();
    return ((double) (timer->end - timer->start)) / CLOCKS_PER_SEC;
}

int obterNumeroDigitos(int tamanho){
    if(tamanho == 0)
        return 1;

    int digitos = 0;
    while (tamanho > 0)
    {
        tamanho = tamanho / 10;
        digitos++;
    }
    
    return digitos;
}

char* gerarNomeArquivo(int tamanho){
    char *nomeArquivo;

    int numeroDigitos = obterNumeroDigitos(tamanho);
    char *digitosString = malloc(numeroDigitos * sizeof(char));
    sprintf(digitosString, "%d", tamanho);

    nomeArquivo = malloc(strlen(FILENAME) + numeroDigitos + strlen(FILEEXTENSIONBIN));

    strcpy(nomeArquivo, FILENAME);
    strcat(nomeArquivo, digitosString);
    strcat(nomeArquivo, FILEEXTENSIONBIN);

    free(digitosString);

    return nomeArquivo;
}

int escreverListaArquivoBinario(lista_t lista){
    FILE *arquivo;

    char *nomeArquivo = gerarNomeArquivo(lista.tamanho);
    arquivo = fopen(nomeArquivo, "wb");

    if(arquivo == NULL){
        printf("Erro ao abrir arquivo.\n");
        return -1;
    }

    fwrite(lista.numeros, sizeof(int), lista.tamanho, arquivo);
    fclose(arquivo);
    
    return 1;
}

void imprimeLista(lista_t lista){
    for(int i=0; i<lista.tamanho; i++)
        printf("%d\n", lista.numeros[i]);
}

void imprimeTempoDeExecucao(double tempo){
    printf("Tempo de execução: %f segundos\n", tempo);
}

int main(){
    lista_t lista;
    Timer timer;

    srand(time(NULL));
    
    printf("Quantos elementos na lista?\n");
    scanf("%d", &lista.tamanho);

    lista.numeros = malloc(lista.tamanho * sizeof(int));

    start_timer(&timer);
    for (int i = 0; i < lista.tamanho; i++)
    {
        lista.numeros[i] = rand();
    }
    
    imprimeTempoDeExecucao(stop_timer(&timer));
    

    // imprimeLista(lista);
    escreverListaArquivoBinario(lista);

    free(lista.numeros);
    
    return 0;
}
